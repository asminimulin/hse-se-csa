#pragma once

#include <atomic>
#include <cstdint>
#include <functional>
#include <thread>
#include <vector>

class ThreadPool {
 public:
  ThreadPool() : m_threads_count(std::thread::hardware_concurrency()), m_remaining_tasks(-1) {}

  template <typename Functor>
  void AddTask(Functor functor) {
    m_tasks.emplace_back([functor = std::move(functor)] {
      functor();
    });
  }

  void Run() {
    m_remaining_tasks.store(static_cast<std::int64_t>(m_tasks.size()), std::memory_order_release);
    std::vector<std::thread> threads;
    threads.reserve(m_threads_count);
    const std::uint32_t required_threads = std::min(m_threads_count, static_cast<uint32_t>(m_tasks.size()));
    for (std::uint32_t thread_id = 0; thread_id < required_threads; ++thread_id) {
      threads.emplace_back([&]() {
        while (true) {
          std::int64_t task_id = m_remaining_tasks.fetch_sub(1, std::memory_order_acq_rel) - 1;
          if (task_id < 0)
            break;
          m_tasks[task_id]();
        }
      });
    }
    for (auto& thread : threads) {
      thread.join();
    }
  }

 private:
  const std::uint32_t m_threads_count;
  std::vector<std::function<void()>> m_tasks;
  std::atomic_int64_t m_remaining_tasks;
};

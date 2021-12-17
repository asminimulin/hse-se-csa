#include "generator/generate_books_distribution.hpp"

#include <cstdint>
#include <list>
#include <random>
#include <vector>

#include "library/book_with_location.hpp"
#include "library/library_params.hpp"
#include "thread_pool/thread_pool.hpp"

namespace detail {
void FillRowWithBooks(std::uint32_t row_id, std::uint32_t books_count, std::uint32_t bookcase_count, std::list<BookWithLocation>& books) {
  if (books_count == 0) {
    return;
  }
  static constexpr std::uint32_t authors_count = 100;
  static constexpr std::uint32_t titles_count = 100;
  std::default_random_engine random(std::random_device{}());
  for (std::uint32_t book_id = 0; book_id < books_count; ++book_id) {
    std::uint32_t bookcase_id = books_count / bookcase_count;
    std::uint32_t author_id = random() % authors_count + 1;
    std::uint32_t title_id = random() % titles_count + 1;
    std::string author = "Author#" + std::to_string(author_id);
    std::string title = "Title#" + std::to_string(title_id);
    books.emplace_back(BookWithLocation{Book{author, title}, BookLocation{row_id, bookcase_id}});
  }
}
}  // namespace detail

std::vector<std::list<BookWithLocation>> GenerateBooksDistribution(const LibraryParams& params) {
  std::vector<std::list<BookWithLocation>> uncatalogued_rows(params.row_count);

  ThreadPool thread_pool;
  for (std::uint32_t task_id = 0; task_id < params.row_count; ++task_id) {
    thread_pool.AddTask([=, &params, &uncatalogued_rows]() {
      detail::FillRowWithBooks(task_id, params.bookcase_per_row_count * params.books_per_bookcase_count, params.bookcase_per_row_count,
                               uncatalogued_rows[task_id]);
    });
  }
  thread_pool.Run();

  return uncatalogued_rows;
}

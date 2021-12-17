#pragma once

#include <cstdint>

class CommandLineOptions {
 public:
  CommandLineOptions();

  void PassCommandLineOptions(int argc, char* const* argv) noexcept;

  [[nodiscard]] std::uint32_t GetRowCount() const noexcept;
  [[nodiscard]] std::uint32_t GetBookcasePerRowCount() const noexcept;
  [[nodiscard]] std::uint32_t GetBooksPerBookcaseCount() const noexcept;

  ~CommandLineOptions();

 private:
  std::uint32_t m_rows_count{10};
  std::uint32_t m_bookcase_per_row_count{10};
  std::uint32_t m_books_per_bookcase_count{10};
};
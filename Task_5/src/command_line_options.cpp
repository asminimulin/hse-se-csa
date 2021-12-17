#include "command_line_options.hpp"

#include <cstring>
#include <cstdlib>
#include <stdexcept>

CommandLineOptions::CommandLineOptions() = default;

void CommandLineOptions::PassCommandLineOptions(int argc, char *const *argv) noexcept {
  for (int i = 1; i < argc; ++i) {
    if (i + 1 == argc) {
      break;
    } else {
      std::uint32_t value;
      value = std::strtoul(argv[i + 1], nullptr, 10);
      if (errno == ERANGE) {
        continue;
      }
      if (value <= 0) {
        continue;
      }
      if (std::strcmp(argv[i], "-m") == 0) {
        ++i;
        m_rows_count = static_cast<std::uint32_t>(value);
      } else if (std::strcmp(argv[i], "-n") == 0) {
        ++i;
        m_bookcase_per_row_count = static_cast<std::uint32_t>(value);
      } else if (std::strcmp(argv[i], "-k") == 0) {
        ++i;
        m_books_per_bookcase_count = static_cast<std::uint32_t>(value);
      }
    }
  }
}

std::uint32_t CommandLineOptions::GetRowCount() const noexcept { return m_rows_count; }

std::uint32_t CommandLineOptions::GetBookcasePerRowCount() const noexcept { return m_bookcase_per_row_count; }

std::uint32_t CommandLineOptions::GetBooksPerBookcaseCount() const noexcept { return m_books_per_bookcase_count; }

CommandLineOptions::~CommandLineOptions() = default;

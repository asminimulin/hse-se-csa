#pragma once

#include <cstdint>

struct LibraryParams {
  LibraryParams() = default;
  LibraryParams(const LibraryParams&) = default;
  LibraryParams& operator=(const LibraryParams&) = default;
  std::uint32_t row_count{10};
  std::uint32_t bookcase_per_row_count{100};
  std::uint32_t books_per_bookcase_count{1000};
};

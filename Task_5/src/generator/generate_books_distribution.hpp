#pragma once

#include <cstdint>
#include <list>
#include <random>
#include <vector>

#include "library/book_with_location.hpp"
#include "library/library_params.hpp"

std::vector<std::list<BookWithLocation>> GenerateBooksDistribution(const LibraryParams& params);

#pragma once

#include "library/book.hpp"
#include "library/book_location.hpp"

struct BookWithLocation {
  Book book;
  BookLocation location;
};

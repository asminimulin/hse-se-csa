#pragma once

#include <list>
#include <map>
#include <memory>
#include <vector>

#include "library/book_with_location.hpp"
#include "library/library_params.hpp"

namespace detail {
using UnderlyingCatalogType = std::map<std::string, std::map<std::string, std::list<BookWithLocation>>>;
}

class Catalog {
 public:
  explicit Catalog(detail::UnderlyingCatalogType&& catalog);
  static std::vector<Catalog> CreateCatalogs(LibraryParams params, std::vector<std::list<BookWithLocation>>& books);

  void Show();

 private:
  const detail::UnderlyingCatalogType m_books;
};

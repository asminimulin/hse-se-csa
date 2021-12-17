#include "catalog.hpp"

#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <vector>

#include "library/book_with_location.hpp"
#include "library/library_params.hpp"
#include "thread_pool/thread_pool.hpp"

void AddBooksToCatalog(std::list<BookWithLocation>& books, detail::UnderlyingCatalogType& catalog) {
  for (auto& book : books) {
    catalog[book.book.GetAuthor()][book.book.GetTitle()].emplace_back(std::move(book));
  }
}

Catalog::Catalog(detail::UnderlyingCatalogType&& catalog) : m_books(std::move(catalog)) {}

std::vector<Catalog> Catalog::CreateCatalogs(LibraryParams params, std::vector<std::list<BookWithLocation>>& books) {
  std::vector<detail::UnderlyingCatalogType> catalogs(params.row_count);

  ThreadPool thread_pool;
  for (std::uint32_t task_id = 0; task_id < params.row_count; ++task_id) {
    thread_pool.AddTask([=, &books, &catalogs]() {
      AddBooksToCatalog(books[task_id], catalogs[task_id]);
    });
  }

  thread_pool.Run();
  std::vector<Catalog> results;
  results.reserve(params.row_count);
  for (auto& catalog : catalogs) {
    results.emplace_back(std::move(catalog));
  }
  return results;
}

void Catalog::Show() {
  for (const auto& [author, books] : m_books) {
    std::cout << "Author=" << author << ':' << '\n';
    for (const auto& [title, book_with_locations] : books) {
      std::cout << "\tBook=" << title << ':' << '\n';
      for (const auto& book_with_location : book_with_locations) {
        std::cout << "\t\tLocation={row=" << book_with_location.location.row << "; bookcase=" << book_with_location.location.bookshelf
                  << '}' << '\n';
      }
    }
  }
}

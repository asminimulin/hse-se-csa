#include <chrono>
#include <iostream>
#include <list>
#include <string_view>
#include <vector>

#include "command_line_options.hpp"
#include "generator/generate_books_distribution.hpp"
#include "library/catalog.hpp"
#include "library/library_params.hpp"

template <typename Functor>
void RunWithStopwatch(std::string_view task_name, Functor&& functor) {
  using namespace std::chrono;
  std::cout << "Started doing task \"" << task_name << '\"' << std::endl;
  auto start = steady_clock::now();
  functor();
  auto end = steady_clock::now();
  std::cout << "Execution of task \"" << task_name << "\" took " << duration<double>(end - start).count() << " seconds" << std::endl;
}

int main(int argc, char** argv) {
  CommandLineOptions command_line_options;
  command_line_options.PassCommandLineOptions(argc, argv);
  LibraryParams library_params{};
  std::vector<std::list<BookWithLocation>> books;

  RunWithStopwatch("Creating books distribution", [&]() mutable {
    library_params.row_count = command_line_options.GetRowCount();
    library_params.bookcase_per_row_count = command_line_options.GetBookcasePerRowCount();
    library_params.books_per_bookcase_count = command_line_options.GetBooksPerBookcaseCount();
    books = GenerateBooksDistribution(library_params);
  });

  std::vector<Catalog> catalogs;
  RunWithStopwatch("Creating catalog", [&]() mutable {
    catalogs = Catalog::CreateCatalogs(library_params, books);
  });

  std::cout << "Show catalogs? (Y/y - yes, N/n - no)" << std::endl;
  if (std::tolower(std::cin.get()) == 'y') {
    size_t catalog_id = 0;
    for (auto& catalog : catalogs) {
      std::cout << "========= Catalog" << catalog_id << " ==========\n";
      catalog.Show();
      std::cout << std::endl;
      catalog_id++;
    }
  }

  return 0;
}

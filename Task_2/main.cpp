#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>

#include <libfilm/container.hpp>
#include <libfilm/film.hpp>

#include "film_generator.hpp"

void PrintUsage(const char* application_name) {
    std::cout << application_name << " [-n <number_of_elements>] <input_file> <output_file>\n";
}

[[noreturn]] void FatalError(const char* error) {
    std::cerr << error << '\n';
    exit(1);
}

void GenerateFilms(Container& container, size_t film_count, uint32_t random_seed) {
    FilmGenerator generator(random_seed);
    for (size_t i = 0; i < film_count; ++i) {
        container.Add(generator.GenerateFilm());
    }
}

int main(int argc, char** argv) {
    std::ifstream input_file;
    std::ofstream output_file;
    Container container;
    if (argc == 3) {
        input_file.open(argv[1], std::ios::in);
        output_file.open(argv[2], std::ios::out);
        if (!input_file) {
            FatalError("Cannot open input file");
        }
        input_file >> container;
        if (!input_file) {
            FatalError("Malformed container data");
        }
    }
    else if (argc == 5) {
        if (std::strcmp(argv[1], "-n") != 0) {
            PrintUsage(argv[0]);
            return 1;
        }
        size_t number = std::atoll(argv[2]);
        if (number > Container::kMaxElementsInContainer) {
            std::cerr << "Incorrect argumens. Number must be in range [1, " << Container::kMaxElementsInContainer
                << "] but it is equal to " << number;
            return 1;
        }
        input_file.open(argv[3], std::ios::in);
        output_file.open(argv[4], std::ios::out);
        if (!input_file) {
            FatalError("Cannot open input file");
        }
        if (!output_file) {
            FatalError("Cannot open output file");
        }
        uint32_t random_seed;
        if (!(input_file >> random_seed)) {
            FatalError("Malformed randomizer configuration");
        }
        GenerateFilms(container, number, random_seed);
    }
    else {
        PrintUsage(argv[0]);
        return 1;
    }
    container.SelectionSort();
    if (!(output_file << container)) {
        FatalError("Failed to write to file");
    }
    return 0;
}

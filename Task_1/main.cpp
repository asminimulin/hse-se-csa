#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <libfilm/container.hpp>
#include <libfilm/film.hpp>

void PrintUsage(const char* application_name) {
    std::cout << application_name << " [-n <number_of_elements>] <input_file> <output_file>\n";
}

void FatalError(const char* error) {
    std::cerr << error << '\n';
    exit(1);
}

void InitRandomizerSetup(std::istream& input_stream) {
    unsigned int random_seed;
    input_stream >> random_seed;
    std::srand(random_seed);
}

int main(int argc, char** argv) {
    std::ifstream input_file;
    std::ofstream output_file;
    Container container;
    Initialize(container);
    if (argc == 3) {
        input_file.open(argv[1], std::ios::in);
        output_file.open(argv[2], std::ios::out);
        auto error_code = Deserialize(container, input_file);
        switch (error_code)
        {
        case DeserializationError::kIOError:
            FatalError("Failed to read file.");
            break;
        case DeserializationError::kContainerToLittle:
            FatalError("Container cannot contain so many elements.");
            break;
        case DeserializationError::kMalformedData:
            FatalError("Malformed input");
            break;
        case DeserializationError::kSuccess:
            break;
        }
    } else if (argc == 5) {
        if (std::strcmp(argv[1], "-n") != 0) {
            PrintUsage(argv[0]);
            return 1;
        }
        size_t number;
        number = std::atoll(argv[2]);
        if (number > 10000) {
            std::cerr << "Incorrect argumens. Number must be in range [1, 10000] but it is equal to " << number;
            return 1;
        }
        input_file.open(argv[3], std::ios::in);
        output_file.open(argv[4], std::ios::out);
        InitRandomizerSetup(input_file);
        Generate(container, number);
    } else {
        PrintUsage(argv[0]);
        return 1;
    }
    SelectionSort(container);
    Serialize(container, output_file);
    return 0;
}

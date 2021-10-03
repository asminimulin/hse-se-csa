#include <cassert>
#include <iostream>
#include <string>
#include "libfilm/container.hpp"

double CalculateMagicOperationSum(const Container& container) {
    double sum = 0;
    for (size_t i = 0; i < container.size; ++i) {
        sum += GetReleaseYearDividedByNameLength(*(container.films[i]));
    }
    return sum;
}

void Initialize(Container& container) {
    container.size = 0;
}

int AddFilm(Container& container, Film* film) {
    if (container.size == detail::kMaxElementsInContainer) {
        assert(false);
        return 1;
    }
    container.films[container.size] = film;
    container.size++;
    return 0;
}

void Clear(Container& container) {
    for (size_t i = 0; i < container.size; ++i) {
        Uninitialize(*(container.films[i]));
        delete container.films[i];
    }
    container.size = 0;
}

void Uninitialize(Container& container) {
    Clear(container);
}

void Serialize(const Container& container, std::ostream& output_stream) {
    output_stream << "Container size: " << container.size << '\n';
    for (size_t i = 0; i < container.size; ++i) {
        Serialize(*(container.films[i]), output_stream);
        output_stream << "Release year devided by name length: " << GetReleaseYearDividedByNameLength(*(container.films[i])) << '\n';
    }
}

DeserializationError Deserialize(Container& container, std::istream& input_stream) {
    Clear(container);
    size_t container_size;
    if (!(input_stream >> container_size)) {
        return DeserializationError::kIOError;
    }
    input_stream >> std::ws;

    if (container_size > detail::kMaxElementsInContainer) {
        return DeserializationError::kContainerToLittle;
    }

    DeserializationError error_code = DeserializationError::kSuccess;
    for (size_t& i = container.size; i < container_size; ++i) {
        container.films[i] = new Film;
        error_code = Deserialize(*(container.films[i]), input_stream);
        if (error_code != DeserializationError::kSuccess) {
            delete container.films[i];
            break;
        }
    }
    if (error_code != DeserializationError::kSuccess) {
        Clear(container);
        return error_code;
    }

    return DeserializationError::kSuccess;
}

void SelectionSort(Container& container) {
    for (size_t sorted_part_length = 0; sorted_part_length < container.size; ++sorted_part_length) {
        size_t minimal_element_index = sorted_part_length;
        for (size_t j = sorted_part_length + 1; j < container.size; ++j) {
            if (GetReleaseYearDividedByNameLength(*container.films[minimal_element_index]) > GetReleaseYearDividedByNameLength(*container.films[j])) {
                minimal_element_index = j;
            }
        }
        std::swap(container.films[minimal_element_index], container.films[sorted_part_length]);
    }
}

void Generate(Container& container, size_t number) {
    Clear(container);
    for (size_t& i = container.size; i < number; ++i) {
        container.films[i] = new Film;
        Generate(*(container.films[i]));
    }
}

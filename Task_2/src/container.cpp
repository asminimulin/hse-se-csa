#include <cstdint>
#include <iostream>
#include <string>

#include "film_reader.hpp"
#include "libfilm/container.hpp"
#include "libfilm/film.hpp"

std::istream& operator>>(std::istream& input_stream, Container& container)
{
    size_t size;
    if (!(input_stream >> size >> std::ws)) {
        return input_stream;
    }
    if (size > Container::kMaxElementsInContainer) {
        input_stream.setstate(std::ios::failbit);
        return input_stream;
    }
    for (size_t i = 0; i < size; ++i) {
        auto film = ReadFilm(input_stream);
        if (!input_stream) {
            return input_stream;
        }
        container.m_films.emplace_back(std::move(film));
    }
    return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, const Container& container)
{
    output_stream << "Container size: " << container.m_films.size() << "\n\n";
    if (!output_stream) {
        return output_stream;
    }
    for (size_t i = 0; i < container.m_films.size(); ++i) {
        output_stream << *container.m_films[i];
        output_stream << "Release year divided by film name length: " << container.m_films[i]->GetReleaseYearDividedByNameLength() << "\n\n";
    }
    return output_stream;
}

void Container::Add(std::unique_ptr<Film>&& film)
{
    m_films.emplace_back(std::move(film));
}

void Container::SelectionSort()
{
    auto position = m_films.begin();
    while (position != m_films.end()) {
        auto it_smallest = position;
        for (auto it = it_smallest + 1; it != m_films.end(); ++it) {
            if ((*it)->GetReleaseYearDividedByNameLength() < (*it_smallest)->GetReleaseYearDividedByNameLength()) {
                it_smallest = it;
            }
        }
        std::swap(*position, *it_smallest);
        ++position;
    }
}

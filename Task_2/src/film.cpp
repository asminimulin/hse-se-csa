#include <cstring>
#include <memory>
#include <string>
#include <iostream>

#include "libfilm/film.hpp"

Film::Film(std::string name, uint32_t release_year): m_name(std::move(name)), m_release_year(release_year) {}

double Film::GetReleaseYearDividedByNameLength() const {
    if (m_name.length() == 0) {
        return 0;
    }
    return m_release_year * 1.0 / m_name.length();
}

std::ostream& operator<<(std::ostream& output_stream, const Film& film)
{
    output_stream << "Film name: " << film.m_name << '\n'
        << "Release year: " << film.m_release_year << '\n';
    if (!output_stream) {
        return output_stream;
    }
    film.PrintDetailsToOStream(output_stream);
    return output_stream;
}

#include <cstring>
#include <string>
#include <utility>

#include "libfilm/fiction.hpp"
#include "libfilm/film.hpp"

Fiction::Fiction(std::string name, uint32_t release_year, std::string director) :
    Film(std::move(name), release_year), m_director(std::move(director)) {}

void Fiction::PrintDetailsToOStream(std::ostream& output_stream) const
{
    output_stream << "Film type: fiction\n";
    output_stream << "Director: " << m_director << '\n';
}

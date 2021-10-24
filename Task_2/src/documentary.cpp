#include <iostream>
#include "libfilm/documentary.hpp"
#include "libfilm/errors.hpp"

Documentary::Documentary(std::string name, uint32_t release_year, uint32_t duration):
    Film(std::move(name), release_year), m_duration(duration) {}

void Documentary::PrintDetailsToOStream(std::ostream& output_stream) const
{
    output_stream << "Film type: documentary\n";
    output_stream << "Duration: " << m_duration << '\n';
}

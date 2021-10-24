#pragma once

#include <cstdint>
#include <iostream>
#include <string>

#include "libfilm/film.hpp"

class Fiction : public Film {
public:
    Fiction(std::string name, uint32_t release_year, std::string director);

protected:
    void PrintDetailsToOStream(std::ostream& output_stream) const override;

private:
    std::string m_director;
};

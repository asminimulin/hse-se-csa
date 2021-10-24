#pragma once

#include <cstdint>
#include <iostream>

#include "libfilm/film.hpp"

class Documentary : public Film
{
public:
    Documentary(std::string name, uint32_t release_year, uint32_t duration);

protected:
    void PrintDetailsToOStream(std::ostream& output_stream) const override;

private:
    uint32_t m_duration;
};

#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

class Film {
public:
    Film(std::string name, uint32_t release_year);

    double GetReleaseYearDividedByNameLength() const;

    friend std::ostream& operator<<(std::ostream& output_stream, const Film& film);

    virtual ~Film() = default;

protected:
    virtual void PrintDetailsToOStream(std::ostream& output_stream) const = 0;

private:
    std::string m_name;
    uint32_t m_release_year;
};

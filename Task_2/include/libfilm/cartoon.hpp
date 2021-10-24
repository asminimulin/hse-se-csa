#pragma once

#include <iostream>

#include "libfilm/film.hpp"

class Cartoon : public Film {
public:
    enum class Type {
        kUndefinedCartoon = 0,
        kHandDrawnCartoon = 1,
        kPuppetCartoon = 2,
        kClayAnimation = 3
    };

    Cartoon(std::string name, uint32_t release_year, Type type);

protected:
    void PrintDetailsToOStream(std::ostream& output_stream) const override;

private:
    static const char* CartoonTypeToString(Type type);

    Type m_type;
};
#include <cstdint>
#include <iostream>

#include "film_reader.hpp"

#include "libfilm/cartoon.hpp"
#include "libfilm/documentary.hpp"
#include "libfilm/fiction.hpp"
#include "libfilm/film.hpp"

static std::string ReadNonEmptyLine(std::istream& input_stream) {
    std::string result;
    std::getline(input_stream, result);
    if (input_stream && result.empty()) {
        input_stream.setstate(std::ios::failbit);
    }
    return result;
}

static bool IsValidCartoonType(const std::string& cartoon_type)
{
    return cartoon_type == "puppet" || cartoon_type == "clay" || cartoon_type == "handdrawn";
}

static Cartoon::Type CartoonTypeFromString(const std::string& cartoon_type)
{
    if (cartoon_type == "puppet") {
        return Cartoon::Type::kPuppetCartoon;
    }
    else if (cartoon_type == "clay") {
        return Cartoon::Type::kClayAnimation;
    }
    else if (cartoon_type == "handdrawn") {
        return Cartoon::Type::kHandDrawnCartoon;
    }
    return Cartoon::Type::kUndefinedCartoon;
}

std::unique_ptr<Film> ReadFilm(std::istream& input_stream)
{
    std::string name = ReadNonEmptyLine(input_stream);
    if (!input_stream) {
        return {};
    }
    uint32_t release_year;
    if (!(input_stream >> release_year >> std::ws)) {
        return {};
    }
    std::string film_type = ReadNonEmptyLine(input_stream);
    if (!input_stream) {
        return {};
    }
    std::unique_ptr<Film> film;
    if (film_type == "cartoon") {
        const std::string cartoon_type = ReadNonEmptyLine(input_stream);
        if (!input_stream) {
            return {};
        }
        if (!IsValidCartoonType(cartoon_type)) {
            input_stream.setstate(std::ios::failbit);
            return {};
        }
        film = std::make_unique<Cartoon>(std::move(name), release_year, CartoonTypeFromString(cartoon_type));
    } else if (film_type == "documentary") {
        uint32_t duration;
        if (!(input_stream >> duration >> std::ws)) {
            return {};
        }
        film = std::make_unique<Documentary>(std::move(name), release_year, duration);
    } else if (film_type == "fiction") {
        std::string director = ReadNonEmptyLine(input_stream);
        if (!input_stream) {
            return {};
        }
        film = std::make_unique<Fiction>(std::move(name), release_year, std::move(director));
    } else {
        input_stream.setstate(std::ios::failbit);
        return {};
    }

    return film;
}

#pragma once

#include <cstdint>
#include <memory>
#include <random>

#include "libfilm/cartoon.hpp"
#include "libfilm/film.hpp"

class FilmGenerator {
public:
    FilmGenerator(uint32_t random_seed);
    
    std::unique_ptr<Film> GenerateFilm();

private:
    std::string GenerateFilmName();
    uint32_t GenerateReleaseYear();
    std::string GenerateDirector();
    uint32_t GenerateDuration();
    Cartoon::Type GenerateCartoonType();
    std::string GenerateString(size_t max_length);

    std::mt19937 m_random;
};


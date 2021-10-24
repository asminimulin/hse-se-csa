#include <cstdint>
#include <memory>
#include <random>

#include "film_generator.hpp"
#include "libfilm/cartoon.hpp"
#include "libfilm/documentary.hpp"
#include "libfilm/fiction.hpp"

FilmGenerator::FilmGenerator(uint32_t random_seed): m_random(std::random_device{}()) {
    m_random.seed(random_seed);
}

std::unique_ptr<Film> FilmGenerator::GenerateFilm() {
    static constexpr auto kCartoon = 0;
    static constexpr auto kDocumentary = 1;
    static constexpr auto kFiction = 2;
    uint32_t film_type = m_random() % 3;
    std::unique_ptr<Film> film;
    if (film_type == kCartoon) {
        film = std::make_unique<Cartoon>(GenerateFilmName(), GenerateReleaseYear(), GenerateCartoonType());
    } else if (film_type == kDocumentary) {
        film = std::make_unique<Documentary>(GenerateFilmName(), GenerateReleaseYear(), GenerateDuration());
    } else {
        film = std::make_unique<Fiction>(GenerateFilmName(), GenerateReleaseYear(), GenerateDirector());
    }
    return film;
}

std::string FilmGenerator::GenerateDirector()
{
    static constexpr size_t kMaxFilmDirectorNameLength = 20;
    return GenerateString(kMaxFilmDirectorNameLength);
}

Cartoon::Type FilmGenerator::GenerateCartoonType()
{
    return Cartoon::Type((m_random() % 3) + static_cast<uint32_t>(Cartoon::Type::kHandDrawnCartoon));
}

std::string FilmGenerator::GenerateFilmName()
{
    static constexpr size_t kMaxFilmNameLength = 15;
    return GenerateString(kMaxFilmNameLength);
}

uint32_t FilmGenerator::GenerateReleaseYear()
{
    return m_random() % 100 + 1920;
}

uint32_t FilmGenerator::GenerateDuration()
{
    return m_random() % 10000 + 1;
}

std::string FilmGenerator::GenerateString(size_t max_length)
{
    std::string result;
    if (max_length == 0) {
        return result;
    }
    static constexpr char characters[] = "abcdefghijklmnopqrstuvwxyz ";
    const auto length = m_random() % max_length + 1;
    for (size_t i = 0; i < length; ++i) {
        result += characters[m_random() % (sizeof(characters) - 1)];
    }
    return result;
}

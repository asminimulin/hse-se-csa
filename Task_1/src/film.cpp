#include <cstring>
#include <iostream>
#include <string>
#include "libfilm/film.hpp"

DeserializationError Deserialize(Film& film, std::istream& input_stream) {
    std::string type_string;
    Film::Type type;
    uint32_t release_year;
    std::string film_name;
    std::getline(input_stream, film_name);
    if (input_stream.eof()) {
        return DeserializationError::kMalformedData;
    } else if (input_stream.fail()) {
        return DeserializationError::kIOError;
    }
    if (!(input_stream >> release_year >> std::ws)) {
        if (input_stream.eof()) {
            return DeserializationError::kMalformedData;
        } else {
            return DeserializationError::kIOError;
        }
    }
    std::getline(input_stream, type_string);
    if (input_stream.eof()) {
        return DeserializationError::kMalformedData;
    } else if (input_stream.fail()) {
        return DeserializationError::kIOError;
    }
    DeserializationError error_code;
    if (type_string == "cartoon") {
        type = Film::Type::kCartoon;
        error_code = Deserialize(film.cartoon, input_stream);
    } else if (type_string == "documentary") {
        type = Film::Type::kDocumentary;
        error_code = Deserialize(film.documentary, input_stream);
    } else if (type_string == "fiction") {
        type = Film::Type::kFiction;
        error_code = Deserialize(film.fiction, input_stream);
    } else {
        error_code = DeserializationError::kMalformedData;
    }

    if (error_code != DeserializationError::kSuccess) {
        return error_code;
    }

    Initialize(film, type, film_name, release_year);

    return DeserializationError::kSuccess;
}

double GetReleaseYearDividedByNameLength(const Film& film) {
    if (film.name.length() == 0) {
        return 0;
    }
    return film.release_year * 1.0 / film.name.length();
}

void Initialize(Film& film, Film::Type type, const std::string& name, uint32_t release_year) {
    film.type = type;
    film.name = name;
    film.release_year = release_year;
}

void Serialize(const Film& film, std::ostream& output_stream) {
    output_stream << "Film name: " << film.name << '\n';
    output_stream << "Film release year: " << film.release_year << '\n';
    output_stream << "Film type: ";
    switch (film.type) {
    case Film::Type::kCartoon:
        output_stream << "cartoon\n";
        Serialize(film.cartoon, output_stream);
        break;
    case Film::Type::kDocumentary:
        output_stream << "documentary\n";
        Serialize(film.documentary, output_stream);
        break;
    case Film::Type::kFiction:
        output_stream << "fiction\n";
        Serialize(film.fiction, output_stream);
        break;
    default:
        std::cerr << "Internal error in film serialization";
        break;
    }
}

void Uninitialize(Film& film) {
    if (film.type == Film::Type::kFiction)
        Uninitialize(film.fiction);
    film.name.clear();
}

void Generate(Film& film) {
    const Film::Type film_type = Film::Type(std::rand() % 3);
    const auto film_name = "Film #" + std::to_string(static_cast<unsigned>(std::rand()));
    Initialize(film, film_type, film_name, static_cast<unsigned>(rand() % 2000));
    switch (film_type)
    {
    case Film::Type::kCartoon:
        Initialize(film.cartoon, Cartoon::Type(static_cast<unsigned>(rand()) % 3));
        break;
    case Film::Type::kFiction:
        Initialize(film.fiction, "Director #" + std::to_string(static_cast<unsigned>(std::rand())));
        break;
    case Film::Type::kDocumentary:
        Initialize(film.documentary, static_cast<unsigned>(std::rand()));
    default:
        break;
    }
}

#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include "libfilm/cartoon.hpp"
#include "libfilm/documentary.hpp"
#include "libfilm/fiction.hpp"
#include "libfilm/errors.hpp"

struct Film {
    std::string name;
    uint32_t release_year;

    enum class Type {
        kCartoon,
        kDocumentary,
        kFiction
    };
    Type type;
    union {
        Cartoon cartoon;
        Documentary documentary;
        Fiction fiction;
    };
};

/**
* Deserializes film from input_stream.
* 
* @returns Error code of operation completion.
* @retval DeserializationError::kSuccess Success.
* @retval DeserializationError::kIOError Some error happened during reading from input stream. 
* @retval DeserializationError::kMalformedData Input stream contains malformed data.
*/
DeserializationError Deserialize(Film& film, std::istream& input_stream);

/**
* Calculates release year divided by length of film name.
* 
* @return release year devided by name length if film name is not empty and zero otherwise.
*/
double GetReleaseYearDividedByNameLength(const Film& film);

/**
* Initializes film
*/
void Initialize(Film& film, Film::Type type, const std::string& name, uint32_t release_year);

/**
* Serializes film data to output_stream.
*/
void Serialize(const Film& film, std::ostream& output_stream);

/**
* Uninitializes film, clears resoures if necessary.
*/
void Uninitialize(Film& film);

/**
* Generates film filled with random values.
*/
void Generate(Film& film);


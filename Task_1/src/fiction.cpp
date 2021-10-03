#include <cstring>
#include <iostream>
#include <string>
#include "libfilm/errors.hpp"
#include "libfilm/fiction.hpp"

DeserializationError Deserialize(Fiction& fiction, std::istream& input_stream) {
    std::string director;
    std::getline(input_stream, director);
    if (input_stream.eof()) {
        return DeserializationError::kIOError;
    } else if (input_stream.fail()) {
        return DeserializationError::kMalformedData;
    }
    Initialize(fiction, director);
    return DeserializationError::kSuccess;
}

void Initialize(Fiction& fiction, const std::string& director) {
    fiction.director = new char[director.size() + 1];
    std::memcpy(fiction.director, director.c_str(), director.size() + 1);
}

void Uninitialize(Fiction& fiction) {
    delete fiction.director;
}

void Serialize(const Fiction& fiction, std::ostream& output_stream) {
    output_stream << "Fiction director: " << fiction.director << '\n';
}

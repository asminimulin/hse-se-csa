#include <iostream>
#include "libfilm/documentary.hpp"
#include "libfilm/errors.hpp"

DeserializationError Deserialize(Documentary& documentary, std::istream& input_stream) {
    uint32_t duration;
    if (!(input_stream >> duration >> std::ws)) {
        if (input_stream.eof()) {
            return DeserializationError::kMalformedData;
        } else if (input_stream.fail()) {
            return DeserializationError::kIOError;
        }
    }
    Initialize(documentary, duration);
    return DeserializationError::kSuccess;
}

void Initialize(Documentary& documentary, uint32_t duration) {
    documentary.duration = duration;
}

void Serialize(const Documentary& documentary, std::ostream& output_stream) {
    output_stream << "Documentary duration: " << documentary.duration << '\n';
}

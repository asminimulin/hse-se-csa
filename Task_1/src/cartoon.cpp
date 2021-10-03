#include <string>
#include "libfilm/cartoon.hpp"

DeserializationError Deserialize(Cartoon& cartoon, std::istream& input_stream) {
    std::string type_str;
    std::getline(input_stream, type_str);
    if (input_stream.eof()) {
        return DeserializationError::kMalformedData;
    } else if (input_stream.fail()) {
        return DeserializationError::kIOError;
    }
    Cartoon::Type type;
    if (type_str == "handdrawn") {
        type = Cartoon::Type::kHandDrownCartoon;
    } else if (type_str == "puppet") {
        type = Cartoon::Type::kPuppetCartoon;
    } else if (type_str == "clay") {
        type = Cartoon::Type::kClayAnimation;
    } else {
        return DeserializationError::kMalformedData;
    }
    Initialize(cartoon, type);
    return DeserializationError::kSuccess;
}

void Initialize(Cartoon& cartoon, Cartoon::Type type) {
    cartoon.type = type;
}

void Generate(Cartoon& cartoon) {
    Initialize(cartoon, Cartoon::Type(rand() % 3));
}

void Serialize(const Cartoon& cartoon, std::ostream& output_stream) {
    output_stream << "Cartoon type: ";
    switch (cartoon.type) {
    case Cartoon::Type::kClayAnimation:
        output_stream << "clay\n";
        break;
    case Cartoon::Type::kHandDrownCartoon:
        output_stream << "handdrawn\n";
        break;
    case Cartoon::Type::kPuppetCartoon:
        output_stream << "puppet\n";
        break;
    default:
        std::cerr << "Internal error in cartoon serialization\n";
        break;
    }
}

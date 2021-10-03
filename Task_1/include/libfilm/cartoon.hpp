#pragma once

#include <iostream>
#include "libfilm/errors.hpp"

struct Cartoon {
    enum class Type {
        kHandDrownCartoon,
        kPuppetCartoon,
        kClayAnimation
    };

    Type type;
};

/**
* Deserialize cartoon data.
* 
* @param[in] cartoon Deserializing cartoon.
* @param[in] input_stream Input stream.
* 
* @returns Error code of operation completion.
* @retval DeserializationError::kSuccess Success.
* @retval DeserializationError::kIOError Some error happened during reading from input stream. 
* @retval DeserializationError::kMalformedData Input stream contains malformed data.
*/
DeserializationError Deserialize(Cartoon& cartoon, std::istream& input_stream);

/**
* Initializes cartoon.
* 
* @detail No memory allocations happen.
* 
* @param[in] cartoon Initializing cartoon
* @param[in] type Type of the cartoon
*/
void Initialize(Cartoon& cartoon, Cartoon::Type type);

/**
* Generate cartoon filled with random values
* 
* @param[in] cartoon Generating cartoon.
*/
void Generate(Cartoon& cartoon);

/**
* Serialize cartoon to output stream.
* 
* @param[in] cartoon Serializing cartoong
* @param[in] output_stream Output stream.
*/
void Serialize(const Cartoon& cartoon, std::ostream& output_stream);

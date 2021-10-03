#pragma once

#include <iostream>
#include <string>
#include "libfilm/errors.hpp"

struct Fiction {
    char* director;
};

/**
* Deserialized fiction film data from input_stream.
* 
* @param[in] fiction The fiction which will be filled.
* @param[in] input_stream Input stream.
* 
* @returns Error code of operation completion.
* @retval DeserializationError::kSuccess Success.
* @retval DeserializationError::kIOError Some error happened during reading from input stream. 
* @retval DeserializationError::kMalformedData Input stream contains malformed data.
*/
DeserializationError Deserialize(Fiction& fiction, std::istream& input_stream);

/**
* Initializes fiction film.
* 
* @param[out] fiction The fiction, that will be initialized.
* @param[in] director The fiction director.
*/
void Initialize(Fiction& fiction, const std::string& director);

/**
* Uninitialize fiction film.
* 
* @param[in] fiction The fiction, that will be uninitialized.
*/
void Uninitialize(Fiction& fiction);

/**
* Serialize fiction film.
* 
* @param[in] fiction Serializing film.
* @param[in] output_stream Output stream.
*/
void Serialize(const Fiction& fiction, std::ostream& output_stream);

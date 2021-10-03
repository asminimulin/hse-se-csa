#pragma once

#include <iostream>
#include "libfilm/errors.hpp"

struct Documentary {
    uint32_t duration; // in minutes
};

/**
* Deserializes documentary film data from input_stream
* 
* @param[in] documentary Reading documentary. 
* @param[in] input_stream Input stream 
* 
* @returns Error code of operation completion.
* @retval DeserializationError::kSuccess Success.
* @retval DeserializationError::kIOError Some error happened during reading from input stream. 
* @retval DeserializationError::kMalformedData Input stream contains malformed data.
*/
DeserializationError Deserialize(Documentary& documentary, std::istream& input_stream);

/**
* Initialize data of documentary film.
* 
* @param[in] documentary Initializing film.
* @param[in] duration The duration of documentary.
*/
void Initialize(Documentary& documentary, uint32_t duration);

/**
* Serialize documentary film to output stream
* 
* @param[in] documentary Serializing documentary.
* @param[in] output_stream Output stream.
*/
void Serialize(const Documentary& documentary, std::ostream& output_stream);

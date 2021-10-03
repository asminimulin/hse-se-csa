#pragma once
#include <cstdint>
#include <iostream>
#include <utility>
#include "libfilm/errors.hpp"
#include "libfilm/film.hpp"

namespace detail {
    static constexpr size_t kMaxElementsInContainer = 10000;
}

/**
* Container takes owenership of films that were added.
* Max elements amount in container is 10000. (See ::detail::kMaxElementsInContainer)
*/
struct Container {
    Film* films[detail::kMaxElementsInContainer];
    size_t size;
};

/**
* Initialized empty container
* 
* @param[out] container Initialized empty container.
*/
void Initialize(Container& container);

/**
* Adds a new film to container.
* 
* @param[in] container Container.
* @param[in] film Added film.
* 
* @returns Error code of the operation. 
* @retval 0 Success.
* @retval 1 Container is full.
*/
int AddFilm(Container& container, Film* film);

/**
* Clears container. Calls procedure unitinialize on every item in container.
* 
* @param[in] container Cleaning container.
*/
void Clear(Container& container);

/**
* Calculates sum of results of doing magic operation on every item in container.
* 
* @param[in] conatiner Container with items to process.
* 
* @returns Sum of results of doing magic operation.
*/
double CalculateMagicOperationSum(const Container& container);

/**
* Serializes conatiner to the output stream. It calls Serialize procedure on 
* every element of container.
* 
* @param[in] container Serializing conatiner.
* @param[in] output_stream Output stream.
*/
void Serialize(const Container& container, std::ostream& output_stream);


/**
* Uninitializes container. It calls Clear method internally.
* 
* @param[in] container Uninitializing container.
*/
void Uninitialize(Container& container);

/**
* Deserializes container from input stream. If container contained any items before this procedure called,
* all of them are Uninitialized and deleted.
* @param[in] container Deserializing container.
* @param[in] input_stream Input stream.
* 
* @returns Error code of operation completion.
* @retval DeserializationError::kSuccess Success.
* @retval DeserializationError::kIOError Some error happened during reading from input stream. 
* @retval DeserializationError::kContainerToLittle Container cannot load so many elements that input stream contains.
* @retval DeserializationError::kMalformedData Input stream contains malformed data.
*/
DeserializationError Deserialize(Container& container, std::istream& input_stream);

/**
* Sort container using straight selection sort.
* 
* @param[in] container Sorting container.
*/
void SelectionSort(Container& container);

/**
* Fill container with random data.
* 
* @param[in] container Filling container.
* @param[in] number of generated films.
*/
void Generate(Container& container, size_t number);

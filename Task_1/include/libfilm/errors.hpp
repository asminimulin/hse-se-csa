#pragma once

enum class DeserializationError : int {
    kSuccess = 0,
    kIOError = 1,
    kContainerToLittle = 2,
    kMalformedData = 3,
};

#include "CustomException.h"

const char* CustomException::what() const noexcept {
    return "Invalid pet age!";
}

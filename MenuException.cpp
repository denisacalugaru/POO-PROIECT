#include "MenuException.h"

// Constructor that takes the error message and stores it
/**
 * @brief Constructor for the MenuException class.
 *
 * Initializes the exception with a custom error message.
 *
 * @param message A string representing the error message.
 */
MenuException::MenuException(const std::string& message) : message(message) {}

// Returns the error message
/**
 * @brief Returns the error message associated with the exception.
 *
 * This function overrides the `what()` method from the `std::exception` class
 * and returns the error message stored during the construction of the exception.
 *
 * @return A C-style string representing the error message.
 */
const char* MenuException::what() const noexcept {
    return message.c_str();
}

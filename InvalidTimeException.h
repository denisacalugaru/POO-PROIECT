#ifndef INVALID_TIME_EXCEPTION_H
#define INVALID_TIME_EXCEPTION_H

#include "MenuException.h"

// Exception class to handle errors related to invalid time inputs for menu availability
// This class is derived from the MenuException base class.
class InvalidTimeException : public MenuException {
public:
    // Constructor to initialize the exception with an error message
    // @param message: The error message describing the invalid time input
    explicit InvalidTimeException(const std::string& message)
        : MenuException(message) {}  // Pass the message to the base class constructor
};

#endif // INVALID_TIME_EXCEPTION_H

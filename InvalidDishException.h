#ifndef INVALID_DISH_EXCEPTION_H
#define INVALID_DISH_EXCEPTION_H

#include "MenuException.h"

// Exception class to handle errors related to invalid dishes in the menu
// This class is derived from the MenuException base class.
class InvalidDishException : public MenuException {
public:
    // Constructor to initialize the exception with an error message
    // @param message: The error message describing the invalid dish
    explicit InvalidDishException(const std::string& message)
        : MenuException(message) {}  // Pass the message to the base class constructor
};

#endif // INVALID_DISH_EXCEPTION_H

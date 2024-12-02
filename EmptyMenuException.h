#ifndef EMPTY_MENU_EXCEPTION_H
#define EMPTY_MENU_EXCEPTION_H

#include "MenuException.h"

// Exception thrown when a menu is empty
class EmptyMenuException : public MenuException {
public:
    // Constructor for the EmptyMenuException
    // @param message: A message that provides additional details about the exception
    explicit EmptyMenuException(const std::string& message)
        : MenuException(message) {}  // Pass the message to the base class constructor
};

#endif // EMPTY_MENU_EXCEPTION_H

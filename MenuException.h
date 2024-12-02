#ifndef MENU_EXCEPTION_H
#define MENU_EXCEPTION_H

#include <exception>
#include <string>

/**
 * @class MenuException
 * @brief A class for exceptions related to menu errors.
 *
 * This class is derived from the `std::exception` class and provides
 * functionality for throwing and catching menu-related exceptions.
 */
class MenuException : public std::exception {
public:
    /**
     * @brief Constructs a MenuException with a given error message.
     *
     * Initializes the exception object with the specified error message.
     *
     * @param message A string representing the error message.
     */
    explicit MenuException(const std::string& message);

    /**
     * @brief Returns the error message associated with the exception.
     *
     * This method overrides the `what()` method from the `std::exception` class
     * to return the error message stored in the exception object.
     *
     * @return A C-style string containing the error message.
     */
    const char* what() const noexcept override;

private:
    std::string message; ///< The error message associated with the exception
};

#endif // MENU_EXCEPTION_H

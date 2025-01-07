#ifndef EMPTYMENUEXCEPTION_H
#define EMPTYMENUEXCEPTION_H

#include <exception>
#include <string>

// Excepție personalizată pentru un meniu gol
class EmptyMenuException : public std::exception {
public:
    explicit EmptyMenuException(const std::string& message)
        : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif // EMPTYMENUEXCEPTION_H


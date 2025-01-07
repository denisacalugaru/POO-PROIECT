
#ifndef INVALIDDISHEXCEPTION_H
#define INVALIDDISHEXCEPTION_H

#include <exception>
#include <string>

// Excepție personalizată pentru un fel de mâncare invalid
class InvalidDishException : public std::exception {
public:
    explicit InvalidDishException(const std::string& message)
        : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif // INVALIDDISHEXCEPTION_H

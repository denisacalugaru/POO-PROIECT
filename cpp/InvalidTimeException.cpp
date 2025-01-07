#ifndef INVALIDTIMEEXCEPTION_H
#define INVALIDTIMEEXCEPTION_H

#include <exception>
#include <string>


class InvalidTimeException : public std::exception {
public:
    explicit InvalidTimeException(const std::string& message)
        : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

#endif

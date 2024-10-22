#ifndef INVALID_INPUT_EXCEPTION_H
#define INVALID_INPUT_EXCEPTION_H

#include <exception>
#include <string>

class InvalidInputException : public std::exception {
public:
    explicit InvalidInputException(const std::string& message) : msg(message) {}
    
    virtual const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

#endif // INVALID_INPUT_EXCEPTION_H


#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>
#include <regex>

class BirthDayException : public std::exception {
public:
    explicit BirthDayException(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class DateException : public std::exception {
public:
    explicit DateException(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class PhoneException : public std::exception {
public:
    explicit PhoneException(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class EmailException : public std::exception {
public:
    explicit EmailException(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class FullNameException : public std::exception {
public:
    explicit FullNameException(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

#endif

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

class EncrollmentYearException : public std::exception {
public:
    explicit EncrollmentYearException(const std::string& message) : msg_(message) {}
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

class EntryCoreException : public std::exception {
public:
    explicit EntryCoreException(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

class SemesterNameException : public std::exception {
public:
    explicit SemesterNameException(const std::string& message) : msg_(message) {}
    virtual const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

#endif

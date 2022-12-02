#ifndef LAB2_EXCEPTIONS_HPP
#define LAB2_EXCEPTIONS_HPP

#include <exception>
#include <stdexcept>

class IndexError : public std::runtime_error {
public:
    IndexError() : std::runtime_error("Out of bounds of vector") {};
};

class FileError: public std::runtime_error{
public:
    FileError() : std::runtime_error("Unable to reach a file or file is corrupted"){}
};

class EmptyVector: public std::runtime_error{
public:
    EmptyVector() : std::runtime_error("Empty vector"){}
};

#endif //LAB2_EXCEPTIONS_HPP

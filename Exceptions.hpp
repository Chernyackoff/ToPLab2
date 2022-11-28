#ifndef LAB2_EXCEPTIONS_HPP
#define LAB2_EXCEPTIONS_HPP

#include <exception>
#include <stdexcept>

class IndexError : public std::runtime_error {
public:
    IndexError() : std::runtime_error("Out of bounds of vector") {};
};

#endif //LAB2_EXCEPTIONS_HPP

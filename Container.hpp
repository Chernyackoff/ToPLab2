#ifndef LAB2_CONTAINER_HPP
#define LAB2_CONTAINER_HPP

#include "Vector.cpp"
#include "Note.hpp"

class Container {
    Vector<Note *> records;
protected:
    void sort();

    bool compareNotes(Note* rec1, Note* rec2);
public:
    Container() = default;

    ~Container() = default;

    void append(Note *rec);

    Note* operator[](int i);

    int size();

    Note* find_by_tel(std::string tel);

};


#endif //LAB2_CONTAINER_HPP

#ifndef LAB2_NOTE_HPP
#define LAB2_NOTE_HPP
#include <string>

class Note {
private:
    std::string surname, name, telephone;
    int birthday[3];
public:
    Note() = default;
    Note(std::string surnm, std::string nm);
    Note(std::string surnm, std::string nm, std::string tel);
    ~Note() = default;

    void set_surname(std::string surnm);
    void set_name(std::string nm);
    void set_tel(std::string tel);
    void set_birthday(int day, int month, int year);

    std::string get_surname();
    std::string get_name();
    std::string get_tel();
    std::string get_birthday();

    int get_year();
    int get_month();
    int get_day();
};


#endif //LAB2_NOTE_HPP

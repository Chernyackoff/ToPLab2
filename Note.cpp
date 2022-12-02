#include "Note.hpp"
#include "correct_input.cpp"
#include <iostream>

Note::Note(std::string surnm, std::string nm) {
    surname = std::move(surnm);
    name = std::move(nm);
}

Note::Note(std::string surnm, std::string nm, std::string tel) {
    surname = std::move(surnm);
    name = std::move(nm);
    telephone = std::move(tel);
}

void Note::set_surname(std::string surnm) {
    surname = std::move(surnm);
}

void Note::set_name(std::string nm) {
    name = std::move(nm);
}

void Note::set_tel(std::string tel) {
    telephone = std::move(tel);
}

void Note::set_birthday(int day, int month, int year) {
    birthday[0] = day;
    birthday[1] = month;
    birthday[2] = year;
}

std::string Note::get_surname() {
    return surname;
}

std::string Note::get_name() {
    return name;
}

std::string Note::get_tel() {
    return telephone;
}

std::string Note::get_birthday() {
    auto res = std::to_string(birthday[0]) + '.' + std::to_string(birthday[1]) + '.' + std::to_string(birthday[2]);
    return res;
}

int Note::get_year() {
    return birthday[2];
}

int Note::get_month() {
    return birthday[1];
}

int Note::get_day() {
    return birthday[0];
}

std::istream &operator>>(std::istream &in, Note *rec) {
    std::string temp_name, temp_surname, temp_tel;
    int temp_day = 0;
    int temp_month = 0;
    int temp_year = 0;

    std::cout << "Please, enter the surname:\n";
    temp_surname = correct_input<std::string>(in);

    std::cout << "Please enter the name:\n";
    temp_name = correct_input<std::string>(in);

    std::cout << "Please enter the tel number:\n";
    temp_tel = correct_input<std::string>(in);

    std::cout << "Please enter the birth year:\n";
    temp_year = correct_input<int>(in);
    while(temp_year < 0){
        std::cout << "Please enter correct year (> 0):\n";
        temp_year = correct_input<int>(in);
    }

    std::cout << "Please enter the birth month:\n";
    temp_month = correct_input<int>(in);
    while(temp_month < 1 || temp_month > 12){
        std::cout << "Please enter correct month (1 <= x <= 12 ):\n";
        temp_month = correct_input<int>(in);
    }

    std::cout << "Please enter the birth day:\n";
    temp_day = correct_input<int>(in);
    while(temp_day > 31 || temp_day < 1 ){
        std::cout << "Please enter correct day (1 <= x <= 31):\n";
        temp_day = correct_input<int>(in);
    }

    rec->set_name(temp_name);
    rec->set_surname(temp_surname);
    rec->set_tel(temp_tel);
    rec->set_birthday(temp_day, temp_month, temp_year);

    return in;
}

std::ostream &operator<<(std::ostream &out, Note *rec) {
    auto fio = rec->surname + ' ' + rec->name;
    out << fio << '\n';
    out << rec->telephone << '\n';

    auto birth_date = std::to_string(rec->birthday[0]) +'.'
            +std::to_string(rec->birthday[1]) + '.'
            + std::to_string(rec->birthday[2]);
    out << birth_date << '\n';
    return out;
}

Note::Note(const Note &src) {
    *this = src;
}

Note &Note::operator=(const Note &src) {
    if (this == &src) return *this;
    surname = src.surname;
    name = src.name;
    telephone = src.telephone;
    std::copy(std::begin(src.birthday), std::end(src.birthday), std::begin(birthday));
    return *this;
}


#include "Note.hpp"

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

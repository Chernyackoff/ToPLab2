#include "Container.hpp"
#include "Exceptions.hpp"

void Container::append(Note *rec) {
    records.append(rec);
    sort();
}

bool Container::compareNotes(Note* rec1, Note* rec2) {
    if(rec1->get_year() > rec2->get_year()) return true;
    if(rec1->get_year() < rec2->get_year()) return false;

    if(rec1->get_month() > rec2->get_month()) return true;
    if(rec1->get_month() < rec2->get_month()) return false;

    if(rec1->get_day() > rec2->get_day()) return true;
    if(rec1->get_day() < rec2->get_day()) return false;
    return false;
}

void Container::sort() {
    for (auto i = 0; i < records.size() - 1; i++) {
        for (auto j = 0; j < records.size() - 1 - i; j++) {
            if(compareNotes(records[j], records[j+1])) {
                auto tmp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = tmp;
            }
        }
    }
}

Note *Container::operator[](int i) {
    try {
        return records[i];
    } catch (std::string &msg) {
        throw IndexError();
    }
}

Note *Container::find_by_tel(std::string tel) {
    if (records.size() == 0) return nullptr;

    for (auto i = 0;  i < records.size(); i++) {
        if(records[i]->get_tel() == tel) return records[i];
    }

    return nullptr;
}

int Container::size() {
    return records.size();
}

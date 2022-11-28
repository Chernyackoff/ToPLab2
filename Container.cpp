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
    for (auto i = 0; i < records.size() - 1; i++){
        for (auto j = 0; j < records.size(); j++){
            if(compareNotes(records[i], records[j])) {
                auto tmp = records[i];
                records[i] = records[j];
                records[j] = tmp;
            }
        }
    }
}

Note *Container::operator[](int i) {
    try {
        return records[i];
    } catch (std::string &msg){
        throw IndexError();

    }
}

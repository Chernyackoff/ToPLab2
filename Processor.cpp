#include "Processor.hpp"
#include "Exceptions.hpp"
#include <string>
#include <sstream>
#include <iostream>

Processor::Processor(const std::string &file_name) {
    ifile.open(file_name);
    result = new Vector<std::string>;
}

bool Processor::is_valid_sting(const std::string& input) {
    std::stringstream sstr(input);
    char temp;
    while(sstr >> temp){
        if (temp == ' ') continue;
        else if(temp == '-') return true;
        else return false;
    }
    return false;
}

void Processor::process_file() {
    if(!ifile.good()) throw FileError();
    std::string buff;
    if (!ifile.is_open()) throw FileError();
    while (std::getline(ifile, buff, '.')) {
        if(is_valid_sting(buff)){
            result->append(buff);
        }
    }
}

Vector<std::string> *Processor::get_result() {
    process_file();
    if (result->size() == 0) throw EmptyVector();
    return result;
}

Processor::~Processor() {
    ifile.close();
}

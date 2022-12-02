#ifndef LAB2_PROCESSOR_HPP
#define LAB2_PROCESSOR_HPP

#include <fstream>
#include <string>
#include "Vector.cpp"

class Processor {
    std::ifstream ifile;
    Vector<std::string>* result;
protected:
    void process_file();
    static bool is_valid_sting(const std::string& input);
public:
    explicit Processor(const std::string& file_name);
    ~Processor();

    Vector<std::string> *get_result();

};


#endif //LAB2_PROCESSOR_HPP

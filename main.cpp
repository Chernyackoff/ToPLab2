#include <iostream>
#include "Container.hpp"
#include "Processor.hpp"
#include "correct_input.cpp"
#include "Exceptions.hpp"

void note_ui(){
    Container cont;
    while(true){
        std::cout << "Chose an option:\n"<<
        "\t1.Add record\n" <<
        "\t2.Show all records\n"<<
        "\t3.Show record by telephone number\n"<<
        "\t4. Exit\n";
        int ans = correct_input<int>();
        switch (ans) {
            case 1:{
                auto temp_rec = new Note();
                std::cin >> temp_rec;
                cont.append(temp_rec);
                std::cout << "Added successfully!\n";
                break;
            }
            case 2:{
                for (auto i = 0; i < cont.size(); i++){
                    std::cout << cont[i];
                }
                break;
            }
            case 3:{
                std::string temp;
                std::cout << "Please enter telephone number:\n";
                temp = correct_input<std::string>();
                auto rec = cont.find_by_tel(temp);
                if(rec != nullptr){
                    std::cout << rec;
                } else{
                    std::cout << "No record with such telephone number!\n";
                }
            }
            case 4:{
                return;
            }
            default:{
                std::cout << "No such option!\n";
            }
        }
    }
}

void stream_ui() {
    std::cout << "PLease enter filename:\n";
    auto filename = correct_input<std::string>();
    Processor prc(filename);
    while (true){
        std::cout << "Chose an option:\n" <<
        "\t1.Process\n"<<
        "\t2.Exit\n";
        auto ans = correct_input<int>();
        switch (ans) {
            case 1:{
                Vector<std::string>* res;
                try{
                    res = prc.get_result();
                }
                catch(EmptyVector &err){
                    std::cout << err.what() << std::endl;
                    return;
                }
                catch (FileError& err){
                    std::cout << err.what() << std::endl;
                    return;
                }
                std::cout << res[0] << std::endl;
                break;
            }
            case 2:{
                return;
            }

            default:{
                std::cout << "No such option!" << std::endl;
                break;
            }
        }
    }
}

int main() {
    while (true) {
        std::cout << "Please choose an option:\n" <<
                  "\t1.Note\n" << "\t2.File and string streams\n" << "\t3. Exit\n";
        int ans = correct_input<int>();
        switch (ans) {
            case 1:{
                note_ui();
                break;
            }
            case 2:{
                stream_ui();
                break;
            }
            case 3: {
                return 0;
            }
            default:{
                std::cout << "No such option!\n";
            }
        }
    }
}

#include <iostream>
#include <numeric>

template <typename T>
T correct_input(){
    T temp;
    std::cin >> temp;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fool proofing
        std::cout << "Wrong input! Enter correct value" << std::endl;
        std::cin >> temp;
    }
    return temp;
}


template <typename T>
T correct_input(std::istream &in){
    T temp;
    in >> temp;
    while (in.fail()) {
        in.clear();
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // fool proofing
        std::cout << "Wrong input! Enter correct value" << std::endl;
        in >> temp;
    }
    return temp;
}

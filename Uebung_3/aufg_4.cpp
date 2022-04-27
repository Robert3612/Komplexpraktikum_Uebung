#include <stdint.h>
#include <iostream>


namespace a3 {
    int giveNumber();
}

int a3::giveNumber(){return 3;}

namespace a4 {
        int giveNumber();
}

int a4::giveNumber(){return 4;}

int main() {
std::cout << a3::giveNumber()<< std::endl;
std::cout << a4::giveNumber()<< std::endl;
return 0;
}


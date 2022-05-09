#include <iostream>
#include <vector>
#include <stdint.h>
#include "aufg_3.cpp"

class Mammal: public Animal{
    protected:
        int age;
    
    public:
    Mammal(){
        age =0;
    }
        void breath(){
            std::cout << "atmet" << std::endl;
        }
        void walking(){
            std::cout << "läuft" << std::endl;
        }
        int getAge(){
        return age;
        }
};
#include <iostream>
#include <vector>

class NoDefault{
public:
NoDefault(int a){
std::cout<<"Das ist kein defaultconstructor"<<std::endl;
}
};

class C{
private:
    NoDefault b;
public:
C(): b(NoDefault(4)){}

};


int main() {
C a;
}
#include <iostream>

template<typename T>
constexpr int give_size(const T& array){
    return sizeof(array)/sizeof(*array);
}


int main() {
int myints[] = { 10, 20, 30, 40  };

std::cout << sizeof(myints)/sizeof(*myints) << std::endl;
std::cout << give_size(myints) << std::endl;

std::string mystring[] = {"ha", "he", "ho" };

std::cout << sizeof(mystring)/sizeof(*mystring) << std::endl;
std::cout << give_size(mystring) << std::endl;
return 0;
}
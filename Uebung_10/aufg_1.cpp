#include <iostream>
#include <random>

u_int random(int min, int max, int seed= 0){
   /** std::random_device  rand_dev;
    std::cout<<rand_dev()<<std::endl;**/
    std::uniform_int_distribution<u_int> distribution(min, max);
    if(seed==0){
        std::random_device  rand_dev;
        std::mt19937 generator( rand_dev() );
        return distribution(generator);
    }
    else{
        std::mt19937 generator( seed );
        
        return distribution(generator);
    }




}


int main() {
std::cout<<random(0, 10, 454)<<std::endl;
if (__cplusplus == 201703L)
        std::cout << "C++17" << std::endl;
    else if (__cplusplus == 201402L)
        std::cout << "C++14" << std::endl;
    else if (__cplusplus == 201103L)
        std::cout << "C++11" << std::endl;
    else if (__cplusplus == 199711L)
        std::cout << "C++98" << std::endl;
    else
        std::cout << "pre-standard C++" << std::endl;
return 0;
}
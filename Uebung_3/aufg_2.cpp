#include <stdint.h>
#include <iostream>
int main() {
std::cout << "This program prints all numbers from 0 to 256 exactly once!"
<< std::endl;
for (uint16_t i = 0; i <= 256; ++i) {
std::cout << " " << i;
if(i==256){
    std::cout << " " << i;
}
}
std::cout << "\nDone" << std::endl;
return 0;
}

#include <iostream>
#include <stdint.h>
#include <cstring>


int main()
{
uint64_t *array = (uint64_t*) malloc(7 * sizeof(uint64_t));
std::memset(array, 0,7*sizeof(uint64_t));//trotzdem 529 in array[7]
uint64_t a=8;
std::memcpy (array+2,&a , sizeof(a));
for(int i =0;i<8;i++){
    std::cout<< array[i]<<std::endl;
}
return 0;
}
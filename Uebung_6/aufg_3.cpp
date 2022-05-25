#include <iostream>
#include <vector>
#include <stdint.h>
#include <string.h>
#include <cstring>
 
int main ()
{
  char str1[] = "hallo"; 
  char str2[] = "tschüss"; 
 
  std::cout << str1 <<std::endl;
  std::cout << str2 <<std::endl;
 
  std::memcpy (str1, str2, sizeof(str2));
  std::cout << str1 <<std::endl;
  std::cout << str2 <<std::endl;
 
  char str3[] = "baum"; 
  char str4[] = "laufen"; 
 
  std::cout << str3 <<std::endl;
  std::cout << str4 <<std::endl;
  std::memmove (str3, str4, sizeof(str2));
  std::cout << str3 <<std::endl;
  std::cout << str4 <<std::endl;

    char buff1[] = "hallo ";
    char buff2[] = "hellowwdwdwd";


  
    int a;
  
    a = std::memcmp(buff1, buff2, sizeof(buff1));
  
    if (a > 0)
        std::cout << buff1 << " ist größer als " << buff2<< std::endl;
    else if (a < 0)
        std::cout << buff1 << " ist kleiner als " << buff2<< std::endl;
    else
        std::cout << buff1 << " ist gleich groß wie " << buff2<< std::endl;
 
  return 0;
}

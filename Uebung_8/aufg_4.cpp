#include <iostream>

void my_print()
{
    
}

template <typename T, typename... Types>
void my_print(T var1, Types... var2)
{
    std::cout << var1 << std::endl;
 
    my_print(var2...);
}


int main() {
my_print(3);
my_print("hallo", "hello");
my_print('e', 'h', 34, 's', "hallo");

return 0;
}
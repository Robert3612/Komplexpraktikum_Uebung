#include <iostream>
#include <vector>
#include <stdint.h>

class example{
    private:
        int i;
    public:
    example(int e){
        i=e;
    }
    int getI(){
        return i;
    }
};


int main() {
example stack(3);
example t1 = stack;
example t2(4);
t2=stack;
example* heap = new example(3);
std::cout << "stack: " << stack.getI() << std::endl; 
std::cout << "heap: " << heap->getI() << std::endl; 
return 0;
}
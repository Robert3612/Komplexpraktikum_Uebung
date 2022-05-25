#include <iostream>
#include <memory>
struct MyA {
int a = 4;
};
void myfunc( std::unique_ptr< MyA > func_ptr ) {
std::cout << func_ptr->a << std::endl;
return;
}
int main( int arg, const char** argv ) {
// Create a (uniquely owned) resource
std::unique_ptr<MyA> a_ptr = std::make_unique<MyA>();
// Transfer ownership to `myfunc`,
myfunc( a_ptr );
MyA* a= a_ptr;
std::unique_ptr< MyA[] > a_arr_ptr( new MyA[3] );
return 0;
}
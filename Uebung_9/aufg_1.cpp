#include <iostream>
#include <vector>

bool find(std::vector<int>::iterator a, std::vector<int>::iterator b, int n){
while(a!=b){
    if(*a==n){
        return true;
    }
    a++;
}
return false;

}

std::vector<int>::iterator find_iterator(std::vector<int>::iterator a, std::vector<int>::iterator b, int n){
while(a!=b){
    if(*a==n){
        return a;
    }
    a++;
}
std::vector<int>::iterator v;
return v;

}


int main() {
std::vector<int> v = { 4, 18, 46, 36 };
std::vector<int>::iterator a=v.begin();
std::vector<int>::iterator b=v.begin();
b++;
b++;
std::cout<< *find_iterator(a,b,90)<<std::endl;
return 0;
}
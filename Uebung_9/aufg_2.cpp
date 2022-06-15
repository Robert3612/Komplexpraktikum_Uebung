#include <iostream>
#include <vector>
#include <list>

bool equal(std::vector<int> a, std::vector<int> b){
std::vector<int>::iterator it_a = a.begin();
std::vector<int>::iterator it_b = b.begin();
while(it_a != a.end() && it_b != b.end()){
    if(*it_a != *it_b){
        return false;
    }
    it_a++;
    it_b++;
}
if(it_a == a.end() && it_b == b.end()){
    return true;
}
else{
    return false;
}
}

bool equalwithList(std::vector<int> v, std::list<int> l){
std::vector<int>::iterator it_a = v.begin();
std::list<int>::iterator it_b = l.begin();
while(it_a != v.end() && it_b != l.end()){
    if(*it_a != *it_b){
        return false;
    }
    it_a++;
    it_b++;
}
if(it_a == v.end() && it_b == l.end()){
    return true;
}
else{
    return false;
}
}



int main() {
std::vector<int> v = { 4, 18, 46, 36 };
std::vector<int> b = { 4, 18, 46, 36, 45 };
std::cout<<equal(v,b)<<std::endl;

std::vector<int> a = { 4, 18, 46, 36 };
std::list<int> l = { 4, 18, 46, 36 };
std::cout<<equalwithList(a,l)<<std::endl;

return 0;
}
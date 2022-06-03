#include <iostream>
#include <list>
#include <vector>

template<typename Iterator, typename T>
  Iterator find_template (Iterator first, Iterator last, const T& val)
{
  while (first!=last) {
    if (*first==val) return first;
    first++;
  }
  return last;
}


int main() {
std::vector<int> v = { 4, 18, 46, 36 };
std::vector<int>::iterator pv;
pv = find_template(v.begin(), v.end(), 30);
if(pv != v.end()){
std::cout<< "Wert gefunden: " << *pv <<std::endl;}
else {
    std::cout<< "Wert nicht gefunden" <<std::endl;
}
std::list<std::string> l = { "hallo", "hello", "was geht", "bis bald" };
std::list<std::string>::iterator p;
p = find_template(l.begin(), l.end(), "hello");
if(p != l.end()){
std::cout<< "Wert gefunden: " << *p <<std::endl;}
else {
    std::cout<< "Wert nicht gefunden" <<std::endl;
}
return 0;
}
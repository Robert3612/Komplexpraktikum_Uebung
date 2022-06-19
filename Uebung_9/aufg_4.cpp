#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

//einfachste Methode, da Konstruktion des pairs am ehesten Konstruktionen anderer Objekte wie Objekt einer Klasse ähnelt
std::vector<std::pair<std::string, int>> create_vector(std::list<std::string> l, std::list<int> l2){
std::list<std::string>::iterator i1 = l.begin();
std::list<int>::iterator i2 = l2.begin();
std::vector<std::pair<std::string, int>> v;
while(i1 != l.end() && i2 != l2.end()){
    std::pair<std::string, int> p (*i1, *i2);
    v.push_back(p);
    i1++;
    i2++;
}
return v;
}


std::vector<std::pair<std::string, int>> create_vector_2(std::list<std::string> l, std::list<int> l2){
std::list<std::string>::iterator i1 = l.begin();
std::list<int>::iterator i2 = l2.begin();
std::vector<std::pair<std::string, int>> v;
while(i1 != l.end() && i2 != l2.end()){
    auto p = make_pair(*i1, *i2);
    v.push_back(p);
    i1++;
    i2++;
}
return v;
}

// nicht einfach zu verstehen, weil Konstruktion des pairs hinter der Funktion versteckt ist
std::vector<std::pair<std::string, int>> create_vector_3(std::list<std::string> l, std::list<int> l2){
std::list<std::string>::iterator i1 = l.begin();
std::list<int>::iterator i2 = l2.begin();
std::vector<std::pair<std::string, int>> v;
while(i1 != l.end() && i2 != l2.end()){
    v.emplace_back(*i1, *i2);
    i1++;
    i2++;
}
return v;
}


int main() {
std::list<std::string> l1 = {"hallo", "hi", "ho"};
std::list<int> l2 = {34, 45, 56};
std::vector<std::pair<std::string, int>> v = create_vector_2(l1, l2);
for(auto it=v.begin(); it!=v.end(); it++){
    std::cout<<it->first<< "+" << it->second<< std::endl;
}
return 0;
}
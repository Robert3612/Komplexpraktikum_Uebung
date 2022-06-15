#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>


void add_children(std::unordered_map<std::string, std::vector<std::string>> &m, std::string children){
    std::string name= children.substr(0,children.find(","));
    if(m.count(name)==1){
    std::vector<std::string> v= m[name];
    v.push_back(children);
    m[name] = v;
    }
    else{
        std::vector<std::string> v;
        v.push_back(children);
        m[name] = v;
    }
}

void add_children_pair(std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> &m, std::pair<std::string, std::string> children){
    std::string cname= children.first;
    std::string name= cname.substr(0,cname.find(","));
    if(m.count(name)==1){
    std::vector<std::pair<std::string, std::string>> v= m[name];
    v.push_back(children);
    m[name] = v;
    }
    else{
        std::vector<std::pair<std::string, std::string>> v;
        v.push_back(children);
        m[name] = v;
    }
}


int main() {
std::unordered_map<std::string, std::vector<std::string>> family_map;
std::string c1 = "Müller, Hans";
std::string c2 = "Müller, Sabine";
std::string c3 = "Müller, Franz";
std::vector<std::string> v;
v.push_back(c1);
v.push_back(c2);
family_map["Müller"] = v;
std::vector<std::string> help = family_map["Müller"];
for(auto it=help.begin(); it!=help.end(); it++){
    std::cout<< *it<<std::endl;
}
add_children(family_map, c3);
std::vector<std::string> help2 = family_map["Müller"];
for(auto it=help2.begin(); it!=help2.end(); it++){
    std::cout<< *it<<std::endl;
}

std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> family_map_pair;
std::pair<std::string, std::string> p1 ("Schmidt, Hans", "1.3");
std::pair<std::string, std::string> p2 ("Schmidt, Sabine", "6.12");
std::pair<std::string, std::string> p3 ("Schmidt, Franz", "23.6");
std::vector<std::pair<std::string, std::string>> vp;
vp.push_back(p1);
vp.push_back(p2);
family_map_pair["Schmidt"] = vp;
std::vector<std::pair<std::string, std::string>> help3 = family_map_pair["Schmidt"];
for(auto it=help3.begin(); it!=help3.end(); it++){
    std::cout<<it->first<< "+" << it->second<< std::endl;
}
add_children_pair(family_map_pair, p3);
std::vector<std::pair<std::string, std::string>> help4 = family_map_pair["Schmidt"];
for(auto it=help4.begin(); it!=help4.end(); it++){
    std::cout<<it->first<< "+" << it->second<< std::endl;
}
return 0;
}
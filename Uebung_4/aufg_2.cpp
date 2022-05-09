
#include <iostream>
#include <vector>
#include "/home/robert/Komplexpraktikum_Uebung/Uebung_5/aufg_1.cpp"

class Person:public Mammal{
private:
std::string name;
std::string first_name;
std::vector<std::string> parents;
public:
Person(std::string n, std::string fn, int a, std::string fp, std::string sp){
    name=n;
    first_name=fn;
    age = a;
    parents.push_back(fp);
    parents.push_back(sp);
}
Person(std::string n, std::string fn, std::string fp, std::string sp){
    name=n;
    first_name=fn;
    age = 0;
    parents.push_back(fp);
    parents.push_back(sp);
}
Person(std::string n, std::string fn, int a, std::string fp){
    name=n;
    first_name=fn;
    age = a;
    parents.push_back(fp);
}
Person(std::string n, std::string fn, int a){
    name=n;
    first_name=fn;
    age = a;
}
~Person(){
    std::cout<<"Destrukter called"<<std::endl;
}
std::string getName(){
    return name;
}
std::string getFirst_name(){
    return first_name;
}
int getAge(){
    return age;
}
std::string getParents(){
    if (parents.empty()){
        return "keine Eltern";
    }else{
        std::string help = "";
        std::vector<std::string>::iterator it;
        for(it = parents.begin(); it != parents.end(); it++)    {
        help = help + *it + ", ";
        }
        help = help.substr(0, help.size()-2);
        return help;
    }
}
void aging(){
    age++;
}
void walking(){
    std::cout << "läuft anders" <<std::endl;
}
};
int main() {
Person *a= new Person("Jan", "Schiffer",21);
Person *b = new Person("Robert", "Schmidt",21, "Steffen", "Carmen");
Mammal *m = new Mammal();
a->aging();
m->walking();
a->walking();
m->breath();
a->breath();
m->live();

std::cout<< a->getAge()<<std::endl;
std::cout<< b->getParents()<<std::endl;
delete a;
return 0;
}
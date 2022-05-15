#include <iostream>
#include <vector>
#include <stdint.h>

class Animal{
    private:
    std::string race;
    protected:
        int age;
    
    public:
    Animal(){
        age=0;
    }
    Animal(std::string r){
        age=0;
        race = r;
    }
    std::string getRace(){
        return race;
    }
    void live(){
        std::cout<<"lebt"<<std::endl;
    }
    void setAge(int i){
        age = i;
    }
    void aging(){
        age++;
    }
    int getAge(){
        return age;
    }
};

class Mammal: public Animal{
    public:
    Mammal(){

    }
        void breath(){
            std::cout << "atmet" << std::endl;
        }
        void walking(){
            std::cout << "läuft" << std::endl;
        }
};

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
void walking(){
    std::cout << "läuft anders" <<std::endl;
}
};
int main() {
Person *a= new Person("Jan", "Schiffer",21);
Person *b = new Person("Robert", "Schmidt",21, "Steffen", "Carmen");
Mammal *m = new Mammal();
Animal an("hund");
std::cout << an.getRace() << std::endl;
a->aging();
m->walking();
a->walking();
m->breath();
a->breath();
m->live();
Person c("Jan","Schiffer", 22);
c.aging();

std::cout<< a->getAge()<<std::endl;
std::cout<< b->getParents()<<std::endl;
delete a;
return 0;
}
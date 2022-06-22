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
std::vector<Person *> parents;
std::vector<Person *> siblings;
std::vector<Person *> children;
Person* spouse =(Person*) malloc( sizeof( Person ) );
bool spouseSet = false;
public:
Person(std::string n, std::string fn, int a, Person* fp, Person* sp){
    name=n;
    first_name=fn;
    age = a;
    parents.push_back(fp);
    parents.push_back(sp);
}
Person(std::string n, std::string fn, Person* fp, Person* sp){
    name=n;
    first_name=fn;
    age = 0;
    parents.push_back(fp);
    parents.push_back(sp);
}
Person(std::string n, std::string fn, int a, Person* fp){
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
Person(const Person& other){
    name=other.name;
    first_name=other.first_name;
    if(other.age > 0){
        age = other.age;
    }
    if(other.parents.empty()){
        parents=other.parents;
    }
}
Person& operator=(const Person& t){
    name=t.name;
    first_name=t.first_name;
    if(t.age > 0){
        age = t.age;
    }
    if(t.parents.empty()){
        parents=t.parents;
    }
    return *this;
}
~Person(){
    std::cout<<"Destrukter called "+ getName()<<std::endl;
    
   std::vector<Person *>().swap(parents); 
   std::vector<Person *>().swap(children);
   std::vector<Person *>().swap(siblings);
    free(spouse);
}
void addParents(Person* sp){
    parents.push_back(sp);
}
void addChildren(Person* sp){
    children.push_back(sp);
}
void addSibling(Person* sp){
    siblings.push_back(sp);
}
void addSpouse(Person s){
    spouseSet= true;
    *spouse = s;
}
std::string getName(){
    return name;
}
std::string getFirst_name(){
    return first_name;
}
std::vector<Person *> getParents(){
    return parents;
}
std::vector<Person *> getChildren(){
    return children;
}
std::vector<Person *> getSiblings(){
    return siblings;
}
Person* getSpouse(){
    if(spouseSet==false){
        return NULL;
    }
    else{
    return spouse;
    }
}
std::string getParentsToString(){
    if (parents.empty()){
        return "keine Eltern";
    }else{
        std::string help = "";
        for(int i=0; i<parents.size(); i++)    {
        help = help+ parents[i]->getName()+" " + parents[i]->getFirst_name() + ", ";
        }
        help = help.substr(0, help.size()-2);
        return help;
    }
}
void walking(){
    std::cout << "läuft anders" <<std::endl;
}
static void familytree(Person p){
    std::cout<<"parents"<<std::endl;
    std::cout<<p.getParents().size()<<std::endl;
    for(int i=0; i<p.getParents().size(); i++)    {
        std::cout<< p.getParents()[i]->getName()+" " + p.getParents()[i]->getFirst_name()<<std::endl;
        }
    std::cout<<"siblings"<<std::endl;
    for(int i=0; i<p.siblings.size(); i++)    {
        std::cout<< p.siblings[i]->getName()+" " + p.siblings[i]->getFirst_name()<<std::endl;
        }
    std::cout<<"children"<<std::endl;
    for(int i=0; i<p.children.size(); i++)    {
        std::cout<< p.children[i]->getName()+" " + p.children[i]->getFirst_name()<<std::endl;
        }
    std::cout<<"spouse"<<std::endl;
    
    std::cout<< p.spouse->getName()+" " + p.spouse->getFirst_name()<<std::endl;
    
}
};
/**
int main() {
Person carmen("Carmen", "Schmidt", 55);
Person steffen("Steffen", "Schmidt", 57);
Person juliane("Juliane", "Schmidt", 24);
Person kevin("Kevin", "Schwabe", 31);
Person opa("helmut","Schmidt", 90);
Person oma("Gerdrut", "Schmidt", 85);
Person *Robert = new Person("Robert", "Schmidt",21, &carmen, &steffen);
steffen.addSpouse(carmen);
carmen.addSpouse(steffen);
steffen.addParents(&opa);
steffen.addParents(&oma);
steffen.addChildren(Robert);
steffen.addChildren(&juliane);
carmen.addChildren(Robert);
carmen.addChildren(&juliane);
opa.addChildren(&steffen);
oma.addChildren(&steffen);
opa.addSpouse(oma);
oma.addSpouse(opa);
juliane.addParents(&steffen);
juliane.addParents(&carmen);
juliane.addSibling(Robert);
juliane.addSpouse(kevin);
kevin.addSpouse(juliane);
Robert->addSibling(&juliane);


std::cout<< Robert->getParentsToString()<<std::endl;
Person::familytree(*Robert);
delete Robert;

return 0;
}
**/
#include <iostream>
#include <vector>
#include <algorithm>
#include "/home/robert/Komplexpraktikum_Uebung/Uebung_7/aufg_1.cpp"

//Textaufgabe 2 mitschicken
bool has_realtionship(Person &p){
    if(p.getParents().empty() && p.getChildren().empty() && p.getSiblings().empty() && p.getSpouse()==NULL){
        return false;
    }
    else{
        return true;
    }
}

auto has_age = [](Person* p){ return p->getAge() == 21; };
bool has_age2(Person* p){
    std::cout<< "helllllllllllllllllllllllllllllllllllllllll";
    if(p->getAge()==21){
        return true;
    }
    else{
        return false;
    }
}
std::vector<Person> find_persons(Person &p){
    std::vector<Person> returnq;
    int n =0;
    std::vector<Person*> find1 = p.getParents();
    
    auto help2= find1.begin();
    for (int i = 0; i < (int)p.getParents().size(); i++){
        std::cout<< p.getParents().at(i)->getAge() <<std::endl;}
    while(n==1){
    auto help= std::find_if(help2, find1.end(),  [](Person* const& c) { return has_age2(c); });
    if(help != find1.end()){
    returnq.push_back(**help);
    help++;
    help2 = help;
    }
    else{
        n=1;
    }
    }
    n=0;
    find1= p.getSiblings();
    help2= find1.begin();
    while(n==1){
    auto help= (std::find_if(help2, find1.end(), has_age));
    if(help != find1.end()){
    returnq.push_back(**help);
    help++;
    help2 = help;
    }
    else{
        n=1;
    }
    }

    n=0;
    find1= p.getChildren();
    help2= find1.begin();
    while(n==1){
    auto help= (std::find_if(help2, find1.end(), has_age));
    if(help != find1.end()){
    returnq.push_back(**help);
    help++;
    help2 = help;
    }
    else{
        n=1;
    }
    }
    if(p.getSpouse()->getAge()==21){
        returnq.push_back(*p.getSpouse());
    }

    std::cout<< "hello";
    if(returnq.empty()){
        std::cout<< "hello";
    }
    for (int i = 0; i < (int)returnq.size(); i++){
        std::cout<< returnq.empty() <<std::endl;}
    return returnq;

}



int main() {
Person carmen("Carmen", "Schmidt", 21);
Person steffen("Steffen", "Schmidt", 21);
Person juliane("Juliane", "Schmidt", 21);
Person kevin("Kevin", "Schwabe", 21);
Person opa("helmut","Schmidt", 21);
Person oma("Gerdrut", "Schmidt", 85);
Person *Robert = new Person("Robert", "Schmidt",21, &carmen, &steffen);
steffen.addSpouse(carmen);
steffen.addParents(&opa);
steffen.addParents(&oma);
steffen.addChildren(Robert);
steffen.addChildren(&juliane);




Robert->addSibling(&juliane);
std::cout<< has_realtionship(*Robert) <<std::endl;
std::vector<Person> v = find_persons(steffen);
for (int i = 0; i < (int)v.size(); i++){
        std::cout<< v.at(i).getName() <<std::endl;}
std::cout<< has_age(Robert)<< std::endl;

return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include "/home/robert/Komplexpraktikum_Uebung/Uebung_7/aufg_1.cpp"

bool has_realtionship(Person &p){
    if(p.getParents().empty() && p.getChildren().empty() && p.getSiblings().empty() && p.getSpouse()==NULL){
        return false;
    }
    else{
        return true;
    }
}


std::vector<Person*> find_persons(Person &p, int year){
    std::vector<Person*> returnq;
    int n =1;
    std::vector<Person*> find1 = p.getParents();
    
    auto has_age = [&](Person* p){ return p->getAge() == year; };
    auto help2= find1.begin();
    
    while(n==1){
 
    auto help= std::find_if(help2, find1.end(),  has_age);
    if(help != find1.end()){
    returnq.push_back(*help);
    help++;
    help2 = help;
    }
    else{
        n=0;
    }
    }
    n=1;
    find1= p.getSiblings();
    help2= find1.begin();
    while(n==1){
    auto help= (std::find_if(help2, find1.end(), has_age));
    if(help != find1.end()){
    returnq.push_back(*help);
    help++;
    help2 = help;
    }
    else{
        n=0;
    }
    }

    n=1;
    find1= p.getChildren();
    help2= find1.begin();
    while(n==1){

    auto help= (std::find_if(help2, find1.end(), has_age));
    if(help != find1.end()){
    returnq.push_back(*help);
    help++;
    help2 = help;
    }
    else{
        n=0;
    }
    }
    if(p.getSpouse()->getAge()==21){
        returnq.push_back(p.getSpouse());
    }

    return returnq;

}



int main() {
Person carmen("Carmen", "Schmidt", 21);
Person steffen("Steffen", "Schmidt", 21);
Person juliane("Juliane", "Schmidt", 24);
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
std::vector<Person*> v = find_persons(steffen, 21);
for (int i = 0; i < (int)v.size(); i++){
        std::cout<< v.at(i)->getName() <<std::endl;}


return 0;
}
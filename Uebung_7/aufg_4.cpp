#include <iostream>
#include <vector>
#include <stdint.h>
#include <string.h>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>


std::vector<int>* getVector(){
    return new std::vector<int>;
}

void fill(std::vector<int>* vec, int a){
    vec->push_back(a);
}

void read(std::vector<int>*vec){
    for(int i=0;i<vec->size();i++){
        std::cout << vec->at(i)<<std::endl;
    }
}

std::shared_ptr<std::vector<int>> getVectorShared(){
    return std::make_shared<std::vector<int>>();
}

void fillShared(std::shared_ptr<std::vector<int>> vec, int a){
    std::shared_ptr<std::vector<int>> vecs = vec;
    vecs->push_back(a);
}

void readShared(std::shared_ptr<std::vector<int>> vec){
    std::shared_ptr<std::vector<int>> vecs = vec;
    for(int i=0;i<vecs->size();i++){
        std::cout << vecs->at(i)<<std::endl;
    }
}



int main()
{
    std::shared_ptr<std::vector<int>> p = getVectorShared();
    fillShared(p, 3);
    fillShared(p, 4);
    readShared(p);
    p.reset();
    std::vector<int>* vec = getVector();
    fill(vec, 3);
    fill(vec, 4);
    read(vec);
    delete vec;
return 0;
}
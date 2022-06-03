#include <iostream>
#include <vector>
#include <set>

template<typename Container>
void print_container(const Container& container){
    auto it = container.begin();
    for(typename Container::size_type i=0; i<container.size() ; i++){
        std::cout<< *it << std::endl;
        it++;
    }
    
}

template<typename Container>
void print_container_iterator(const Container& container){
    auto begin = container.begin();
    auto end = container.end();
    while(begin != end){
        std::cout << *begin << std::endl;
        begin++;
    }
        
}


int main() {
std::set<int> v{3,49,23, 45, 67, 63636, 878, 7787};
print_container(v);
std::vector<std::string> vs = {"halo", "helo", "hulo"};
print_container(vs);

return 0;
}
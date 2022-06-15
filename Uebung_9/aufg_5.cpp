#include <iostream>
#include <vector>
#include <fstream>
#include <string>




int main() {
std::ifstream file("file.txt");
    std::string content;
std::vector<std::string> v;
    while(std::getline(file, content)) {
        v.push_back(content);
    }

std::ofstream outfile ("test.txt");
while(!v.empty()){
outfile << v.back() << std::endl;
v.pop_back();
}
outfile.close();

std::ifstream file2("file.txt");
    std::string content2;
std::vector<std::string> v2;
    while(file2 >> content2) {
        v2.push_back(content2);
    }

std::ofstream outfile2 ("test2.txt");
while(!v2.empty()){
outfile2 << v2.back() << std::endl;
v2.pop_back();
}

outfile2.close();
return 0;
}
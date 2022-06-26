#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <iomanip>


template <class T> 
const T& max (const T& a, const T& b) {
    if(a<b){
        return b;
    }
    else{
        return a;
    }
 
}




template <class T> 
const T& min (const T& a, const T& b) {
    if(a<b){
        return a;
    }
    else{
        return b;
    }
 
}

template <class RandomAccessIterator>
  void sort_me_with_clamp (RandomAccessIterator first, RandomAccessIterator last){
   RandomAccessIterator help = last;
   RandomAccessIterator help2;
   RandomAccessIterator help3;
   RandomAccessIterator help4 = first;
   RandomAccessIterator help5;
   while(help4 != last){
    //clamp(*help4,INTMAX_MIN, INTMAX_MAX);
    help5 = help4;
    *help5 = std::clamp(*help4, 0, 100);
    
    
    help4++;
   }
   while(help!= first){
    help2 = first;
    while(help2 != last){
        help3 = help2;
        help2++;
        if(*help3>*help2 && help2 != last){
            
            std::iter_swap(help3, help2);
        }
    }
    help--;
   }
  }

  template <class RandomAccessIterator>
  void sort_me_without_clamp (RandomAccessIterator first, RandomAccessIterator last){
   RandomAccessIterator help = last;
   RandomAccessIterator help2;
   RandomAccessIterator help3;
   RandomAccessIterator help4 = first;
   RandomAccessIterator help5;
   while(help4 != last){
    //clamp(*help4,INTMAX_MIN, INTMAX_MAX);
    *help4 = min(*help4, 100);
    *help4 = max(*help4, 0);
    
    
    
    help4++;
   }
   while(help!= first){
    help2 = first;
    while(help2 != last){
        help3 = help2;
        help2++;
        if(*help3>*help2 && help2 != last){
            
            std::iter_swap(help3, help2);
        }
    }
    help--;
   }
  }



int main() {
    
std::vector<int> v = { 4, 18, 46, 36 , 67,4, 3, 101};
for (int i = 0; i < (int)v.size(); i++){
        std::cout<< v.at(i) <<std::endl;}

sort_me_without_clamp  (v.begin(), v.end());
for (int i = 0; i < (int)v.size(); i++){
        std::cout<< v.at(i) <<std::endl;}

return 0;
}
// example.h
#include <vector>
class Example {
public:
static double rate = 6.5;   //benötigt const
static const int vecSize = 20;
static std::vector<double> vec(vecSize);
}
// example.C
//#include "example.h"
double Example::rate;   //kein double benötigt
std::vector<double> Example::vec; 
float a = Example::rate;
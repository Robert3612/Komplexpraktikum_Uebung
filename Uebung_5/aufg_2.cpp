#include <iostream>
#include <vector>
#include <stdint.h>

class Y;

class X{
public:
    Y* a;
};

class Y{
public:
    X b;
};
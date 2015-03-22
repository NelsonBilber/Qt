#include "child.h"
#include <iostream>

using namespace std;


Child::Child(QObject *parent) : QObject(parent)
{
    std::cout << "Child()" << std::endl;
}

Child::~Child()
{
    std::cout << "~Child()" << std::endl;
}


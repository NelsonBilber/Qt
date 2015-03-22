#include "parent.h"
#include <iostream>

using namespace std;

Parent::Parent(QObject *parent) : QObject(parent)
{
    std::cout << "Parent()" << std::endl;
}

Parent::~Parent()
{
    std::cout << "~Parent()" << std::endl;
}


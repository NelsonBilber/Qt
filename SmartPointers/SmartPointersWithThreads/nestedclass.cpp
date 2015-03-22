#include "nestedclass.h"
#include <iostream>
#include <QDebug>

using namespace std;

NestedClass::NestedClass(Base* base, QObject *parent) : QObject(parent),
    base_(base),
    terminate_(false),
    mutex_()
{
    cout << "NestedClass ()" << endl;
}

NestedClass::~NestedClass()
{
    cout << "~ NestedClass ()" << endl;
}

void NestedClass::terminator()
{
    terminate_ = true;
}



void NestedClass::process()
{
    qDebug() << "\t init process()";
    //mutex_.lock();
    int i=0;
    while(!terminate_)
    {
        qDebug() << "\t process() id = "<< i <<" -->" << QThread::currentThreadId();
        i++;
    }
    qDebug() << "\t\t end process() = " << i << " elements" << " -->" << QThread::currentThreadId();
    emit finishThread();
    //mutex_.unlock();
}




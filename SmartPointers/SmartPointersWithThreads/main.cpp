//http://blog.codef00.com/2011/12/15/not-so-much-fun-with-qsharedpointer/
//http://doc-snapshots.qt.io/4.8/qsharedpointer.html

#include "parent.h"
#include "child.h"
#include "base.h"
#include "nestedclass.h"
#include <QCoreApplication>
#include <QObject>
#include <QSharedPointer>
#include <QDebug>

#include <iostream>

using namespace std;

void MyAwesomeFunction(Child* o)
{
    qDebug() << "--> Using Object!" << o->metaObject()->className();
}

void MyAwesomeFunctionPtr(const QSharedPointer <Child>& o)
{
     qDebug() << "--> Using Object!" << o.data()->metaObject()->className();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    // -- opt1
    Parent *const parent = new Parent(0);
    Child *const child = new Child(parent);
    MyAwesomeFunction(child);
    qDebug() << "\n# Before delete parent\n";
    //delete child;
    delete parent;
    //delete child;
    */

    //opt2
    /*
    Parent *const parent = new Parent(0);
    QSharedPointer<Child > child (new Child(parent));
    MyAwesomeFunctionPtr(child);
    qDebug() << "\n# Before delete parent\n";
    delete parent;
    */

    //opt 3
    //simply not mix and match the two memory management schemes
    /*
    Parent *const parent = new Parent(0);
    QSharedPointer<Child> child(new Child());
    MyAwesomeFunctionPtr(child);
    delete parent;
    */

    qDebug() << "\n";
    /*
    Base * base = new Base(0);
    base->jump();
    base->fall();
    delete base;
    */


    QList<Base*> lst;

    for(int i = 0; i < 5; i++) {
        Base * base = new Base(0);
        lst.append(base);
    }

    foreach (Base* b, lst) {
        b->jump();
    }

    /*
    foreach (Base* b, lst) {
        b->reset();
    }
    */


    foreach (Base* b, lst) {
        b->fall();
    }

    foreach (Base* b, lst) {
        delete b;
    }

    qDebug() << "\n## Exit main ##";

    return 0;
}



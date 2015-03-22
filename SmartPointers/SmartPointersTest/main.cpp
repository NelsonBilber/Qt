//http://blog.qt.io/blog/2009/08/25/count-with-me-how-many-smart-pointer-classes-does-qt-have/
//http://qt-project.org/wiki/Smart_Pointers
//http://www.slideshare.net/auranx/smart-pointers-3098055
//http://doc.qt.io/qt-5/qscopedpointer.html#reset
//http://www.informit.com/articles/article.aspx?p=1750226&seqNum=5
//https://meetingcpp.com/index.php/br/items/an-overview-on-smart-pointers.html
//http://www.macieira.org/blog/2012/07/continue-using-qpointer/
//http://www.iesensor.com/blog/2013/03/06/qtcore-vs-c-stl-boost-lib-4-smart-pointers/

#include <QCoreApplication>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QDebug>

#include "parent.h"


void scopedPointer(const QScopedPointer<Parent>& o){
    qDebug() << "init scopedPointer()";
    o->print();
    qDebug() << "end scopedPointer()";
}

void scopedPointer()
{
    qDebug() << "init scopedPointer()";
    QScopedPointer<Parent> o (new Parent(0));
    o->print();
    qDebug() << "end scopedPointer()";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "\n";

    //example 01
    //qt scoped pointer passing a function parameter
    /*
    QScopedPointer<Parent> parent (new Parent(0));
    qDebug() << "start call scoped pointer";
    scopedPointer(parent);
    qDebug() << "out call scoped pointer";

    qDebug() << "\n ---------------------------- \n";
    */
    //example 02
    //qt scoped pointer inside a function
    scopedPointer();

    qDebug() << "# return 0 #";

    return 0;
}


/*

//http://www.informit.com/articles/article.aspx?p=1750226&seqNum=5

QScopedPointer is a smart pointer that automatically deletes the referenced object when the pointer goes out of scope.
It is similar to std::auto_ptr. It makes no sense to copy QScopedPointers because then the referenced object would be
deleted twice. The scope of the pointer clearly shows the lifetime and ownership of the referenced object.

QSharedPointer, like QScopedPointer, is a smart pointer that deletes its referenced object, but copies are permitted,
and the QSharedPointer keeps a reference count. The shared heap object is deleted only when the last shared pointer to
it is destroyed.


*/

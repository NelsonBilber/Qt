//http://doc-snapshots.qt.io/4.8/qsharedpointer.html

#include "base.h"
#include <iostream>
#include <QTime>
#include <QCoreApplication>

using namespace std;

Base::Base(QObject *parent) : QObject(parent)
{
    cout << "Base ()" << endl;
    nested_ = QSharedPointer<NestedClass> (new NestedClass(this)/*, doDeleteLater*/);
    thread_ = new QThread;
}

Base::~Base()
{
    cout << "~ Base()" << endl;

    // ::Important::
    // Before delete object make sure thread is stopped !!!
}

void Base::jump()
{
    cout << "--> jump()" << endl;

    connect( thread_, SIGNAL(started()),  (NestedClass*)nested_.data(), SLOT(process()));
    connect( thread_, SIGNAL(finished()), (NestedClass*)nested_.data(), SLOT(deleteLater()));
    connect( thread_, SIGNAL(finished()), this, SLOT(stopThread()));
    //connect( (NestedClass*)nested_.data(), SIGNAL(finishThread()), thread_, SLOT(quit()), Qt::QueuedConnection);on);

    nested_->moveToThread(thread_);
    thread_->start();

    cout << "-->end jump()" << endl;
}

void Base::fall()
{
    QTime dieTime = QTime::currentTime().addMSecs( 10 );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }

    end();
    cout << "--> end fall()" << endl;
}

void Base::reset()
{
    cout << "--> reset" << endl;
    nested_.clear();
    cout << "--> end reset()" << endl;
}

void Base::doDeleteLater(NestedClass *ptr)
{
    cout << "--> doDeleteLater" << endl;
    ptr->deleteLater();
}

void Base::end()
{
    /*if(thread_ != 0)
    {
        if(thread_->isRunning())
        {
            //thread_->quit(); //QObject: shared QObject was deleted directly. The program is malformed and may crash.
            //thread_->wait(200);
            nested_.data()->terminator();
        }
    }*/
    nested_.data()->terminator();
    cout << "--> end()" << endl;
}

void Base::stopThread()
{
    thread_->quit(); //QObject: shared QObject was deleted directly. The program is malformed and may crash.
    thread_->wait(200);
    //thread_ = 0;
}

#include "workerqueue.h"

#include <QDebug>
#include <QThread>
#include <QMutexLocker>

WorkerQueue::WorkerQueue(QObject *parent):
    QObject(parent),
    abort_(false),
    isRunning_(true)
{
    qDebug()<<"cerate Thread "<<thread()->currentThreadId();
}

WorkerQueue::~WorkerQueue()
{
   abort();
}

void WorkerQueue::addItem(const QString message)
{
    QMutexLocker locker(&mutex);
    queue_.enqueue(message);
    //qDebug()<<"add  = " << queue_.count();
    sleep(1);
    condition.wakeOne();
}

void WorkerQueue::abort()
{
    qDebug()<<"Request worker aborting in Thread "<<thread()->currentThreadId();
    QMutexLocker locker(&mutex);
    abort_ = true;
    condition.wakeOne();
}

void WorkerQueue::pause()
{

    QMutexLocker locker(&mutex);
    //qDebug()<<"pause = " << queue_.count();
    isRunning_ = false;
    condition.wakeOne();
}

void WorkerQueue::resume()
{

    QMutexLocker locker(&mutex);
    qDebug()<<"resume = " << queue_.count();
    isRunning_ = true;
    condition.wakeOne();
}

void WorkerQueue::reset()
{
    //qDebug()<<"reset";
    QMutexLocker locker(&mutex);
    abort_ = false;
    isRunning_ = true;
    queue_.clear();
    condition.wakeOne();
}

void WorkerQueue::process()
{
    qDebug() << "" << QThread::currentThreadId() ;

    while(!abort_)
    {
        mutex.lock();

        while(!queue_.empty() /*&& isRunning_*/)
        {
            QString msg = queue_.dequeue();
            qDebug( ) << "msg = " << msg;
            sleep(1);
            emit sendNewMessage(msg);
            //qDebug() << "Queue count 2 = " << queue_.count();
        }

        condition.wait(&mutex);

        mutex.unlock();
    }
}

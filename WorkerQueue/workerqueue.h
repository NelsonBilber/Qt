#ifndef WORKERQUEUE_H
#define WORKERQUEUE_H

#include <QObject>
#include <QQueue>
#include <Qmutex>
#include <QWaitCondition>

class WorkerQueue: public QObject
{
    Q_OBJECT
public:
    WorkerQueue(QObject *parent = 0);
    ~WorkerQueue();

    void addItem(const QString message);

    void abort();
    void pause();
    void resume();
    void reset();

public slots:
    void process();


signals:
    void sendNewMessage(const QString);

private:

    QWaitCondition condition;
    QQueue<QString> queue_;
    QMutex mutex;
    bool abort_;
    bool isRunning_;
};

#endif // WORKERQUEUE_H

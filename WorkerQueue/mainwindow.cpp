#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "workerqueue.h"

#include <QThread>
#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    queue(new WorkerQueue())

{
    ui->setupUi(this);
    thread = new QThread();

    //connect(this, SIGNAL(startWork()), obj, SLOT(doWork()));

     QMetaObject::invokeMethod(queue, "process", Qt::QueuedConnection);

     connect(queue, SIGNAL(sendNewMessage(const QString)), this, SLOT(setText(const QString)), Qt::QueuedConnection);

     thread = new QThread();
    //connect(thread, SIGNAL(started()), queue, SLOT(process()));

    queue->moveToThread(thread);
    //qDebug()<<"Starting thread in Thread "<<this->->currentThreadId();
    thread->start();

    //forever
    {
        queue->addItem("data0");
        queue->addItem("data1");
        queue->addItem("data2");
        queue->addItem("data3");
        queue->addItem("data4");

        //queue->pause();

        queue->addItem("data10");
        queue->addItem("data11");
        queue->addItem("data12");
        queue->addItem("data13");
        queue->addItem("data14");

        //queue->resume();
    }
}

MainWindow::~MainWindow()
{
    thread->wait();
    qDebug()<<"Deleting thread and worker in Thread "<<this->QObject::thread()->currentThreadId();
    thread->quit();
    delete ui;
}

void MainWindow::setText(const QString message)
{
    qDebug() << "Message = " << message;
}

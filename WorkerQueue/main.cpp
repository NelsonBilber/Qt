#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QThread>

#include "workerqueue.h"

#include <QMutex>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "main thread ID: " << a.thread()->currentThreadId();
    MainWindow win;

    return a.exec();
}

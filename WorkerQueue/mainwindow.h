#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "workerqueue.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setText(const QString );

private:
    Ui::MainWindow *ui;
    WorkerQueue* queue ;
    QThread* thread ;
};

#endif // MAINWINDOW_H

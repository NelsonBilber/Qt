#ifndef MYTABLEVIEW
#define MYTABLEVIEW
#include <QtGui>
#include <QDebug>
#include <iostream>
class myTableView:public QTableView
{
  Q_OBJECT
  public:
  myTableView():QTableView()
  {
    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(clickedSlot(QModelIndex)));
    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickedSlot(QModelIndex)));
  }

  ~myTableView()
  {
  }

private slots:

  void clickedSlot(QModelIndex index)
  {
      //timmer start

      qDebug() << "ONE CLICK";
  }

  void doubleClickedSlot(QModelIndex index)
  {
      // timer stop

    qDebug() << "TWO CLICK";
   }

};
#endif // MYTABLEVIEW


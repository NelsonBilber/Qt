#include <QtSql>
#include "myTableView.h"
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    myTableView* table = new myTableView();
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setWindowTitle("QTableView Item Click/Item Double Click");


    QStandardItemModel* model = new QStandardItemModel(4,2);

    // Attach the model to the view
    table->setModel(model);

    // Generate data
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            QModelIndex index
                    = model->index(row,col,QModelIndex());
            // 0 for all data
            model->setData(index,0);
        }
    }


    table->show();
    return app.exec();
}

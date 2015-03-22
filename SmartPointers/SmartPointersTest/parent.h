#ifndef PARENT_H
#define PARENT_H

#include <QObject>

class Parent : public QObject
{
    Q_OBJECT
public:
    explicit Parent(QObject *parent = 0);
    virtual ~Parent();

    void print();

signals:

public slots:
};

#endif // PARENT_H

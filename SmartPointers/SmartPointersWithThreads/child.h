#ifndef CHILD_H
#define CHILD_H

#include <QObject>

class Child : public QObject
{
    Q_OBJECT
public:
    explicit Child(QObject *parent = 0);
    ~Child();

signals:

public slots:
};

#endif // CHILD_H

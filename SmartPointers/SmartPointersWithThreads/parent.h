#ifndef PARENT_H
#define PARENT_H

#include <QObject>
#include <QSharedPointer>

#include "nestedclass.h"

class Parent : public QObject
{
    Q_OBJECT
public:
    explicit Parent(QObject *parent = 0);
    virtual ~Parent();


signals:

public slots:
};

#endif // PARENT_H

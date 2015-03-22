#ifndef NESTEDCLASS_H
#define NESTEDCLASS_H

#include "base.h"
#include <QObject>
#include <QMutex>

class Base;

class NestedClass : public QObject
{
    Q_OBJECT
public:
    explicit NestedClass(Base* base, QObject *parent = 0);

    virtual ~NestedClass();

    void terminator();


private:
    Base* base_;
    bool terminate_;
    QMutex mutex_;

signals:
    void finishThread();

public slots:
      void process();
};

#endif // NESTEDCLASS_H

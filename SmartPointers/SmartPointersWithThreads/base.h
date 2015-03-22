#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QSharedPointer>
#include <QThread>
#include <QTimer>
#include "nestedclass.h"

class NestedClass;

class Base : public QObject
{
    Q_OBJECT
public:
    explicit Base(QObject *parent = 0);
    virtual ~Base();
    void jump();
    void fall();
    void reset();

    static void doDeleteLater(NestedClass* ptr);

public slots:
    void end();
    void stopThread();

private:

    QSharedPointer<NestedClass> nested_;
    QThread* thread_;

signals:

public slots:
};

#endif // BASE_H

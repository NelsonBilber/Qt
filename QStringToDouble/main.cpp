#include <QCoreApplication>
#include <QString>
#include <QDebug>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString value("92.847260000000");
    qDebug() << "QString = " << value << " double = " << value.toDouble()
             << qSetRealNumberPrecision( 10 ) << "x = " << value.toDouble()
             <<  QString::number( value.toDouble(), 'f', 7 );

    //-- Add

    double val1 = 10.345673;
    double val2 = 10.345679;

    double sum = val1 + val2;

    qDebug() << "sum = " <<  sum << "Format = " <<  QString::number( sum, 'f', 10 ); ;

    double mul = val1 * val2;

    qDebug() << "mul = " <<  mul << "Format = " <<  QString::number( mul, 'f', 10 ); ;

    double div = val1 / val2;

    qDebug() << "div = " <<  div << "Format = " <<  QString::number( div, 'f', 10 ); ;


    //----

    QString s("9338.712001");
    bool ok = false;

    double a = 9338.712001;
    double b = s.toDouble(&ok);
    double c = 1/3.0;

    qDebug() << "a: " << a;
    cout << "a cout ::" << a << endl;
    cout.precision(10);
    cout << "a cout ::" << std::fixed << a << endl;
    qDebug() << "b: " << b;
    qDebug() << "a: " << QString("%1").arg(a, 0, 'g', 13);
    qDebug() << "b: " << QString("%1").arg(b, 0, 'e', 13);
    qDebug() << "c: " << QString("%1").arg(c, 0, 'g', 30);

    return app.exec();
}

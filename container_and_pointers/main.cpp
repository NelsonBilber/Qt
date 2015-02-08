#include <iostream>
#include <QHash>
#include <QDebug>

using namespace std;


class Pointer
{
  public:
    Pointer(int i):id_(i) {}
    ~Pointer(){ qDebug() << "~ Pointer";}
    inline int getid(){ return id_;}

private:
    int id_;
};

int main()
{
    QHash<QString, Pointer*> hash;

    Pointer* p = new Pointer(0);
    hash.insert(QString::number(0), p);

    Pointer* p1 = new Pointer(1);
    hash.insert(QString::number(1), p1);

    Pointer* p2 = new Pointer(2);
    hash.insert(QString::number(2), p2);

    Pointer* p3 = new Pointer(3);
    hash.insert(QString::number(3), p3);

    Pointer* p4 = new Pointer(4);
    hash.insert(QString::number(4), p4);

    Pointer* p5 = new Pointer(5);
    hash.insert(QString::number(5), p5);

    Pointer* p6 = new Pointer(6);
    hash.insert(QString::number(6), p6);

    Pointer* p7 = new Pointer(7);
    hash.insert(QString::number(7), p7);

    Pointer* p8 = new Pointer(8);
    hash.insert(QString::number(8), p8);

    Pointer* p9 = new Pointer(9);
    hash.insert(QString::number(9), p9);

    qDebug() << "start reset \n ";

    Pointer* pp = 0;
    QHash<QString, Pointer*>::iterator it;
    for(it = hash.begin(); it != hash.end(); it++)
    {
        if(it.key() == "1")
        {
            pp = hash.value("1");
            hash.remove("1");
        }
    }

    hash.remove("1");
    qDebug() << "Pointer = " << pp->getid() << "\n";

    QHash<QString, Pointer*>::iterator it_find;
    it_find  = hash.find("1");
    qDebug() << "Pointer exists = " << (it_find != hash.end()) << "\n";

    qDebug() << "hash elems = "<< hash.size() << "\n";
    //hash.clear();
    //qDebug() << "hash elems = "<< hash.size() << "\n";

    /*prints*/
    QHash<QString, Pointer*>::iterator i;
    for(i = hash.begin(); i != hash.end(); ++i)
    {
        qDebug() << "key = "     << i.key()
                 << "Value = "   << i.value()
                 /*<<"value id = " <<i.value()->getid()*/;
        //delete i.value();
    }
    return 0;
}


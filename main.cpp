#include "mainwindow.h"








//These functions are useful during debugging

//--------------- DoDebug ---------------

void DoDebug ( quint32 t1){

    qDebug() << "";
    QString str1 = QString("%1").arg(t1, 8, 16, QLatin1Char('0') );
    QString outStr1 = QString("num1  %1   %2   %3").
                                arg(str1.toUpper(), 10, ' ').
                                    arg(QString::number(t1), 10, ' ').
                                        arg(t1, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr1;

}//DoDebug

//--------------- DoDebug ---------------

void DoDebug ( quint32 t1, quint32 t2){

    qDebug() << "";
    QString str1 = QString("%1").arg(t1, 8, 16, QLatin1Char('0') );
    QString outStr1 = QString("num1  %1   %2   %3").
                                arg(str1.toUpper(), 10, ' ').
                                    arg(QString::number(t1), 10, ' ').
                                        arg(t1, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr1;

    //----------

    QString str2 = QString("%1").arg(t2, 8, 16, QLatin1Char('0') );
    QString outStr2 = QString("num2  %1   %2   %3").
                                arg(str2.toUpper(), 10, ' ').
                                    arg(QString::number(t2), 10, ' ').
                                        arg(t2, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr2;

}//DoDebug

//--------------- DoDebug ---------------

void DoDebug ( quint32 t1, quint32 t2, quint32 t3){

    qDebug() << "";
    QString str1 = QString("%1").arg(t1, 8, 16, QLatin1Char('0') );
    QString outStr1 = QString("num1  %1   %2   %3").
                                arg(str1.toUpper(), 10, ' ').
                                    arg(QString::number(t1), 10, ' ').
                                        arg(t1, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr1;

    //----------

    QString str2 = QString("%1").arg(t2, 8, 16, QLatin1Char('0') );
    QString outStr2 = QString("num2  %1   %2   %3").
                                arg(str2.toUpper(), 10, ' ').
                                    arg(QString::number(t2), 10, ' ').
                                        arg(t2, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr2;

    //----------

    QString str3 = QString("%1").arg(t3, 8, 16, QLatin1Char('0') );
    QString outStr3 = QString("num3  %1   %2   %3").
                                arg(str3.toUpper(), 10, ' ').
                                    arg(QString::number(t3), 10, ' ').
                                        arg(t3, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr3;

}//DoDebug

//--------------- DoDebug ---------------

void DoDebug ( quint32 t1, quint32 t2, quint32 t3, quint32 t4){

    qDebug() << "";
    QString str1 = QString("%1").arg(t1, 8, 16, QLatin1Char('0') );
    QString outStr1 = QString("num1  %1   %2   %3").
                                arg(str1.toUpper(), 10, ' ').
                                    arg(QString::number(t1), 10, ' ').
                                        arg(t1, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr1;

    //----------

    QString str2 = QString("%1").arg(t2, 8, 16, QLatin1Char('0') );
    QString outStr2 = QString("num2  %1   %2   %3").
                                arg(str2.toUpper(), 10, ' ').
                                    arg(QString::number(t2), 10, ' ').
                                        arg(t2, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr2;

    //----------

    QString str3 = QString("%1").arg(t3, 8, 16, QLatin1Char('0') );
    QString outStr3 = QString("num3  %1   %2   %3").
                                arg(str3.toUpper(), 10, ' ').
                                    arg(QString::number(t3), 10, ' ').
                                        arg(t3, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr3;


    //----------

    QString str4 = QString("%1").arg(t4, 8, 16, QLatin1Char('0') );
    QString outStr4 = QString("num4  %1   %2   %3").
                                arg(str4.toUpper(), 10, ' ').
                                    arg(QString::number(t4), 10, ' ').
                                        arg(t4, 32, 2, QLatin1Char('0'));
    qDebug()<<outStr4;

}//DoDebug






int MaxTaps :: num = 0;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

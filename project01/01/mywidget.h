#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"  //子窗口头文件

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

    //声明函数
    void change();
    void changewin();
    void printwin(int, QString);

private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    QPushButton *b4;
    QPushButton b5;

    //Qt4声明槽函数
//public slots:
//    void change();
//    void changewin();
//    void printwin(int, QString);



    subwidget h;  //声明子窗口

};

#endif // MYWIDGET_H

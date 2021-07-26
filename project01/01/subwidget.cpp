#include "subwidget.h"

subwidget::subwidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("副窗口");

    c1.setParent(this);
    c1.setText("返回");
    c1.move(100,100);

    c2.setParent(this);
    c2.setText("打印");
    c2.move(200,100);

    //调用函数
    connect(&c1, &QPushButton::clicked, this, &subwidget::sendsignal);
    connect(&c2, &QPushButton::clicked, this, &subwidget::sendsignal1);

    //控制窗口大小
    resize(500,500);
}


void subwidget::sendsignal()
{
    //发送信号
    emit mysignal();
}

void subwidget::sendsignal1()
{
    //发送信号
    emit mysignal();
    //发送重载信号
    emit mysignal(100,"子窗口");
}







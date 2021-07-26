#include "mywidget.h"
#include <QPushButton>  //按钮的头文件
#include <QDebug>  //打印的头文件

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{

    //定义按钮
    b1.setParent(this);
    b1.setText("退出");
    b1.move(200,100);

    b2 = new QPushButton(this);
    b2->setText("登陆");
    b2->move(100,100);

    b3.setParent(this);
    b3.setText("修改");
    b3.move(300,100);

    b4 = new QPushButton(this);
    b4->setText("Lamda");
    b4->move(100,200);

     //Lamda表达式: [] 引入外部的对象  = 把外部的对象以值的形式（只读）引入
     //            () 输入参数
    connect(b4, QPushButton::clicked,
            []() //mutable  引入的对象可修改
            {
                qDebug() << "Lamda";
            }
            );

    b5.setParent(this);
    b5.setText("anniu");
    b5.move(300,200);

    //定义主窗口的 信号和槽
    connect(&b1, &QPushButton::pressed, this, &MyWidget::close);
    connect(&b3, &QPushButton::pressed, &b1, &QPushButton::hide);
    //调用函数
    connect(b2, &QPushButton::clicked, this, &MyWidget::change);

    //开始时显示主窗口，隐藏副窗口
    this->show();
    h.hide();

    //收到副窗口信号后，调用函数
    //connect(&h, &subwidget::mysignal, this, &MyWidget::changewin);


    //收到副窗口的重载信号，调用函数
    void(subwidget::*folksignal)() = &subwidget::mysignal;
    connect(&h, folksignal, this, &MyWidget::changewin);

    void(subwidget::*folksignal1)(int,QString) = &subwidget::mysignal;
    connect(&h, folksignal1, this, &MyWidget::printwin);


    //Qt4的信号和槽函数调用
    //connect(&h, SIGNAL(mysignal()), this, SLOT(change()));



    resize(500,500);

}

//定义函数

void MyWidget::change()
{
    this->hide();
    h.show();
    //显示副窗口，隐藏主窗口
}

void MyWidget::changewin()
{
    this->show();
    h.hide();
}

void MyWidget::printwin(int a, QString str)
{
    qDebug() << a << str;
}

MyWidget::~MyWidget()
{

}

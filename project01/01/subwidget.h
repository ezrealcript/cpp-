#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class subwidget : public QWidget
{
    Q_OBJECT
public:
    explicit subwidget(QWidget *parent = nullptr);

    void sendsignal();  //声明发送信号的函数
    void sendsignal1(); //声明发送重载信号的函数


signals:
    void mysignal();  //声明一个信号
    void mysignal(int, QString);  //声明重载信号

public slots:

private:
    QPushButton c1;
    QPushButton c2;

};

#endif // SUBWIDGET_H

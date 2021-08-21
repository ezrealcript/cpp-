#ifndef JISUANQI_H
#define JISUANQI_H

#include <QString>
#include <QVector>

class jisuanqi
{
public:
    jisuanqi();
    void setA();
    void CIN();


private:
    QString input; //输入的字符串
    char in[300];
    bool s=0; //判断是否合法

};

#endif // JISUANQI_H

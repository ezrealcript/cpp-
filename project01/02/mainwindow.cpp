#include "mainwindow.h"
#include <QMenuBar>  //菜单栏头文件
#include <QMenu>     //菜单头文件
#include <QAction>   //动作头文件
#include <QDebug>
#include <QToolBar>  //工具栏头文件
#include <QPushButton>
#include <QStatusBar> //状态栏头文件
#include <QLabel>    //标签头文件
#include <QTextEdit> //文本编辑头文件
#include <QDockWidget> //浮动窗口头文件


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,500);

    //添加菜单栏
    QMenuBar *mBar = menuBar();

    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");

    //添加菜单项，添加动作
    QAction *pNew = pFile->addAction("新建");

    connect(pNew, &QAction::triggered,
            []()
            {
                qDebug() << "已处理1";
            }

            );

    pFile->addSeparator();  //添加分割线

    QAction *pOpen = pFile->addAction("打开");

    connect(pOpen, &QAction::triggered,
            []()
            {
                qDebug() << "已处理2" ;
            }
            );

    //工具栏（菜单栏的快捷方式）
    QToolBar *toolBar = addToolBar("toolBar");
    toolBar->addAction(pNew);

    QPushButton *b1 = new QPushButton(this);
    b1->setText(">.<");
    //添加小控件
    toolBar->addWidget(b1);

    connect(b1, &QPushButton::clicked,
            [=]()
            {
                 b1->setText("+.+");
            }
            );

    //添加状态栏
    QStatusBar *Bar = statusBar();


    //(1)添加标签
    QLabel *lable = new QLabel(this);
    lable->setText("nomal text file");

    Bar->addWidget(lable);

    //(2)直接动态分配空间
    Bar->addWidget(new QLabel("again", this));  //从左往右

    Bar->addPermanentWidget(new QLabel("right", this));  //从右向左


    //核心控件
    QTextEdit *Textedit = new QTextEdit(this);
    setCentralWidget(Textedit);

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);

     QTextEdit *Textedit1 = new QTextEdit(this);
     dock->setWidget(Textedit1);   //为浮动窗口设置文本编辑

}





MainWindow::~MainWindow()
{
}

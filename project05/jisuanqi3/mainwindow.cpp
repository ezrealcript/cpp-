#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(500,500);
    this->move(150,150);
    this->setWindowTitle("计算器");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_jisuan_clicked()
{
    int num=ui->spinBox->value();
    ui->spinBox_2->setValue(num);
    ui->spinBox_3->setValue(num);
}

void MainWindow::on_pushButton_clicked()
{
    ui->spinBox->hide();
}

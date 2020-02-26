#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString s1 = "Игрок 1", s2 = "Игрок 2";         //Установка имён игроков по умолчанию

    if (ui->lineEdit->text() != "")                 //Если вписаны имена, то берём их
        s1 = ui->lineEdit->text();

    if (ui->lineEdit_2->text() != "")
        s2 = ui->lineEdit_2->text();



    SecondWindow wind(s1, s2);                      //Создаём объект второго окна и передаём имена игроков
    wind.setModal(true);
    wind.exec();
}

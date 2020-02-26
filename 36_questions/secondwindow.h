#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QString>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QString &s1, QString &s2, QWidget *parent = 0);
    ~SecondWindow();
    void delay(int);

private slots:
    void slotClick();               //Слоты для отлавливания нажатий на кнопки
    void slotClick_2();
private:
    Ui::SecondWindow *ui;
    QPushButton *pushButton, *pushButton_2;         //Объекты двух кнопок
    int count = -1, size = 0;                       //Счётчик передвижения по вопросам и размер массива строк соответственно
    QString *Str = new QString[0], gamer1, gamer2;  //Имена игроков, получаемые из первого окна
};

#endif // SECONDWINDOW_H

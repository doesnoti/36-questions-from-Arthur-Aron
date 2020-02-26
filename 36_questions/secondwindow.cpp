#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextCodec>
#include <QString>
#include <QPushButton>
#include <QApplication>
#include <QDebug>
#include <QTime>
#include <ctime>
#include <QSound>

void push_back(QString *&Str, int &i);

SecondWindow::SecondWindow(QString &s1, QString &s2, QWidget *parent):
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QDialog::showFullScreen();                          //Установка второго окна на весь экран
    ui->pushButton->hide();                             //Скрываем кнопку предыдущего вопроса

    ui->label->setAlignment(Qt::AlignCenter);           //Центрируем надписи в label'ах для красоты
    ui->label_2->setText("Начинаем!");
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setWordWrap(true);                     //Устанавливаем перенос слов для длинных вопросов

    QFile quest("Questions.txt");                       //Подключаем файл с вопросами

    if (!quest.open(QIODevice::ReadOnly | QIODevice::Text))                 //Проверяем открылся ли файл
    {
        QMessageBox::critical(this, "Внимание!","Файл не открылся");
    }

    gamer1 = s1;                            //Присываиваем имена игроков из предыдущего окна
    gamer2 = s2;

    pushButton = ui->pushButton;
    pushButton_2 = ui->pushButton_2;        //Присваеваем объктам класса "кнопка" реальные кнопки на форме

    size = 0;                               //Пустой массив сток по умолчанию

    while(!quest.atEnd())                   //Считываем до конца файла
    {
        push_back(Str, size);               //Вызываем функцию добавления нового элемента в массив строк

        Str[size] = quest.readLine();       //Записываем в последний элемент строку из файла

        size++;                             //Увеличиваем размер массива
    }

    connect(pushButton, SIGNAL(clicked()), this, SLOT(slotClick()));        //Устанавливаем соединение сигнала от нажатия кнопки со слотом
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(slotClick_2()));

    quest.close();                          //Закрываем файл
}

SecondWindow::~SecondWindow()
{
    delete[] Str;                           //Удаляем динамический массив при закрытии окна
    delete ui;
}

void SecondWindow::slotClick()              //Слот отвечающий за возврат к предыдущему вопросу
{
    QSound::play("Click.wav");              //Звук нажатия на кнопку
    count--;                                //Уменьшаем номер вопроса
    ui->label_2->setText(Str[count]);       //Помещаем в лейбл строку под заданым номером

    if (count == 0)                         //При нулевом (по массиву) вопросу сурываем кнопку
    {
        ui->pushButton->hide();
    }
}

void SecondWindow::slotClick_2()            //Слот для перехода к след. вопросу
{
    if (count == (size-1))                  //Проверяем дошли ли до последнего элемента массива, если да, то сообщение предлагающее выйти из программы
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Выход", "Вы хотите завершить программу?",
                                                                  QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)      //Если пользователь ответил "Да", то закрываем окно и вызывается деструктор
        {
            QWidget::close();
        }
    }
    else                                    //Елси не дошли до конца
    {
        count++;                            //Увеличиваем номер вопроса
        if (count != 0)                     //Если номер вопроса не нулевой (по массиву), то показываем кнопку "Предыдущий"
            ui->pushButton->show();
        ui->label_2->setText(Str[count]);   //В лебл записываем вопрос по номеру

        for (int i = 0; i <= 10; i++)       //Цикл для создания эффекта "Казино" при высвечивании имени отвечающего
        {
            QSound::play("Spin.wav");       //Звук щелчка

            ui->label->setText("<FONT COLOR = red>" + gamer1 + "</FONT>"); //Имя первого игрока красным цветом в лейбл
            delay(100);                     //Вызываем функцию задержки времени в миллисекундах, чтобы было заметно глазу

            QSound::play("Spin.wav");       //Тоже самое для второго имени, только синим цветом

            ui->label->setText("<FONT COLOR = blue>" + gamer2 + "</FONT>");
            delay(100);
        }
        for (int i = 0; i <= 5; i++)        //Массив, где делаем эффект заметления прокрутки имён
        {
            QSound::play("Spin.wav");

            ui->label->setText("<FONT COLOR = red>" + gamer1 + "</FONT>");
            delay(100 + 100 * i);           //Увеличиваем время задержки пропорционально номеру итерации

            QSound::play("Spin.wav");

            ui->label->setText("<FONT COLOR = blue>" + gamer2 + "</FONT>");
            delay(100 + 100 * i);
        }

        delay(400);                         //Делаем задержку перед появлением итогового имени

        srand(time(0));                     //Функция, чтобы рандомные числа не повторялись
        int a = qrand() % 2;                //Создаём переменную, в которую рандомно помещаем "0" или "1"
        if (a == 0)                         //В зависимости от результата показываем имя первого или второго игрока
        {
            QSound::play("Spin.wav");       //Звук прокрутки только если имя меняется, а предыдущий цикл останавливается на имени второго игрока

            ui->label->setText("<FONT COLOR = red>" + gamer1 + "</FONT>");
        }
        else
            ui->label->setText("<FONT COLOR = blue>" + gamer2 + "</FONT>");
    }
}

void push_back(QString *&Str, int &i)       //Функция добавления нового элемента в массив строк
{
    QString *newStr = new QString[i+1];     //Создаём новый динамический массив на единицу больше

    for (int j = 0; j < i; j++)             //Циклом копируем все существующие строки в новый массив из старого
    {
        newStr [j] = Str [j];
    }

    delete[] Str;                           //Удаляем содержимое старого массива

    Str = newStr;                           //Ставим указатель старого массива на новый
}

void SecondWindow::delay(int millisecondsToWait)    //Функция задержки времени
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);  //Создаём переменную текущего времен + время в миллисекундах, которое передали в функцию
    while(QTime::currentTime() < dieTime)           //Пока текущее время будет меньше заданного выполняем цикл
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100); //Выставляет все последующие события в очередь
    }
    return;
}

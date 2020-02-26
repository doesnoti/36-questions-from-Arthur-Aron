/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QFrame *frame;
    QLabel *label_2;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QStringLiteral("SecondWindow"));
        SecondWindow->resize(1366, 768);
        SecondWindow->setStyleSheet(QLatin1String("SecondWindow{\n"
"	border-image: url(\"SecondWindow.png\") 0 0 0 0 stretch stretch;\n"
"	background-color: #ebffff;\n"
"}\n"
"\n"
"QFrame#frame{\n"
"	background-color: #55007f;\n"
"\n"
"}\n"
"\n"
"QLabel#label{\n"
"	font: 87 28pt \"Segoe UI Black\";\n"
"}\n"
"\n"
"QLabel#label_2{\n"
"	background-color: #fff9b0;\n"
"	border-radius: 15px;\n"
"	font: 75 italic 24pt \"Monotype Corsiva\";\n"
"	border: 3px solid black;\n"
"}\n"
"\n"
"QPushButton{\n"
"	border-radius: 35px;\n"
"	border: 2px solid gray;\n"
"	background-color: #e2e2e2;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	border: 2px solid black;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	border: 2px solid black;\n"
"	color: #e2e2e2;\n"
"}"));
        pushButton = new QPushButton(SecondWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 540, 500, 120));
        QFont font;
        font.setPointSize(30);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(SecondWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(740, 540, 500, 120));
        pushButton_2->setFont(font);
        label = new QLabel(SecondWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 165, 400, 50));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        frame = new QFrame(SecondWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(240, 250, 871, 241));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(16, 12, 841, 221));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "Dialog", 0));
        pushButton->setText(QApplication::translate("SecondWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271", 0));
        pushButton_2->setText(QApplication::translate("SecondWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271", 0));
        label->setText(QApplication::translate("SecondWindow", "<html><head/><body><p align=\"center\">\320\230\320\274\321\217</p></body></html>", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H

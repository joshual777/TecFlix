/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Viewer
{
public:
    QLabel *label;
    QLabel *lmovieinfo;
    QLabel *ltitle;
    QLabel *lduration;
    QLabel *lgenere;
    QLabel *lyear;
    QLabel *lcountry;
    QLabel *ldirector;
    QLabel *lstars;
    QLabel *ldirectorname;
    QLabel *lactor1;
    QLabel *lactor2;
    QLabel *lactor3;
    QLabel *lcontent;

    void setupUi(QDialog *Viewer)
    {
        if (Viewer->objectName().isEmpty())
            Viewer->setObjectName(QStringLiteral("Viewer"));
        Viewer->resize(610, 464);
        Viewer->setStyleSheet(QLatin1String("QWidget{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		padding: 5px; 	\n"
"}"));
        label = new QLabel(Viewer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 10, 231, 311));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: yellow;\n"
"		border: 1px solid black;\n"
"		color: black;\n"
"		padding: 5px; 	\n"
"}"));
        lmovieinfo = new QLabel(Viewer);
        lmovieinfo->setObjectName(QStringLiteral("lmovieinfo"));
        lmovieinfo->setGeometry(QRect(110, 10, 131, 51));
        QFont font;
        font.setPointSize(17);
        lmovieinfo->setFont(font);
        lmovieinfo->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        ltitle = new QLabel(Viewer);
        ltitle->setObjectName(QStringLiteral("ltitle"));
        ltitle->setGeometry(QRect(130, 60, 151, 51));
        ltitle->setFont(font);
        ltitle->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lduration = new QLabel(Viewer);
        lduration->setObjectName(QStringLiteral("lduration"));
        lduration->setGeometry(QRect(10, 120, 67, 21));
        QFont font1;
        font1.setPointSize(9);
        lduration->setFont(font1);
        lduration->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lgenere = new QLabel(Viewer);
        lgenere->setObjectName(QStringLiteral("lgenere"));
        lgenere->setGeometry(QRect(10, 150, 67, 21));
        lgenere->setFont(font1);
        lgenere->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lyear = new QLabel(Viewer);
        lyear->setObjectName(QStringLiteral("lyear"));
        lyear->setGeometry(QRect(110, 120, 67, 21));
        lyear->setFont(font1);
        lyear->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lcountry = new QLabel(Viewer);
        lcountry->setObjectName(QStringLiteral("lcountry"));
        lcountry->setGeometry(QRect(190, 120, 67, 21));
        lcountry->setFont(font1);
        lcountry->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        ldirector = new QLabel(Viewer);
        ldirector->setObjectName(QStringLiteral("ldirector"));
        ldirector->setGeometry(QRect(10, 210, 81, 31));
        QFont font2;
        font2.setPointSize(11);
        ldirector->setFont(font2);
        ldirector->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lstars = new QLabel(Viewer);
        lstars->setObjectName(QStringLiteral("lstars"));
        lstars->setGeometry(QRect(10, 260, 51, 31));
        lstars->setFont(font2);
        lstars->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        ldirectorname = new QLabel(Viewer);
        ldirectorname->setObjectName(QStringLiteral("ldirectorname"));
        ldirectorname->setGeometry(QRect(150, 210, 81, 31));
        ldirectorname->setFont(font2);
        ldirectorname->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lactor1 = new QLabel(Viewer);
        lactor1->setObjectName(QStringLiteral("lactor1"));
        lactor1->setGeometry(QRect(90, 260, 81, 31));
        lactor1->setFont(font2);
        lactor1->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lactor2 = new QLabel(Viewer);
        lactor2->setObjectName(QStringLiteral("lactor2"));
        lactor2->setGeometry(QRect(90, 310, 81, 31));
        lactor2->setFont(font2);
        lactor2->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lactor3 = new QLabel(Viewer);
        lactor3->setObjectName(QStringLiteral("lactor3"));
        lactor3->setGeometry(QRect(90, 350, 81, 31));
        lactor3->setFont(font2);
        lactor3->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));
        lcontent = new QLabel(Viewer);
        lcontent->setObjectName(QStringLiteral("lcontent"));
        lcontent->setGeometry(QRect(280, 120, 67, 21));
        lcontent->setFont(font1);
        lcontent->setStyleSheet(QLatin1String("QLabel{\n"
"		background-color: black;\n"
"		border: 1px solid black;\n"
"		color: yellow;\n"
"		padding: 5px; 	\n"
"}"));

        retranslateUi(Viewer);

        QMetaObject::connectSlotsByName(Viewer);
    } // setupUi

    void retranslateUi(QDialog *Viewer)
    {
        Viewer->setWindowTitle(QApplication::translate("Viewer", "Dialog", nullptr));
        label->setText(QApplication::translate("Viewer", "TextLabel", nullptr));
        lmovieinfo->setText(QApplication::translate("Viewer", "Movie Info", nullptr));
        ltitle->setText(QApplication::translate("Viewer", "movie", nullptr));
        lduration->setText(QApplication::translate("Viewer", "duration", nullptr));
        lgenere->setText(QApplication::translate("Viewer", "genere", nullptr));
        lyear->setText(QApplication::translate("Viewer", "year", nullptr));
        lcountry->setText(QApplication::translate("Viewer", "country", nullptr));
        ldirector->setText(QApplication::translate("Viewer", "Director", nullptr));
        lstars->setText(QApplication::translate("Viewer", "Stars", nullptr));
        ldirectorname->setText(QApplication::translate("Viewer", "directro name", nullptr));
        lactor1->setText(QApplication::translate("Viewer", "actor1", nullptr));
        lactor2->setText(QApplication::translate("Viewer", "actor2", nullptr));
        lactor3->setText(QApplication::translate("Viewer", "actor3", nullptr));
        lcontent->setText(QApplication::translate("Viewer", "content", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Viewer: public Ui_Viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H

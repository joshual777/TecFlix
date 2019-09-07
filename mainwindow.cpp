#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyle>
#include <QDesktopWidget>
#include <QtDebug>
#include <QWheelEvent>
#include <QStringList>
#include <qfile.h>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

//Variables to take pages

int static current, previous, next;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn1_clicked()
{

    QString page = ui->btn1->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    next = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << next;
    qDebug() << "first";
}

void MainWindow::on_btn2_clicked()
{
    QString page = ui->btn2->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    next = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << next;
    qDebug() << "second";
}

void MainWindow::on_btn3_clicked()
{
    QString page = ui->btn3->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    next = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << next;
    qDebug() << "third";
}

void MainWindow::on_btn4_clicked()
{
    QString page = ui->btn4->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    next = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << next;
    qDebug() << "fourth";
}

void MainWindow::on_btn5_clicked()
{
    QString page = ui->btn5->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    next = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << next;
    qDebug() << "fifth";
}

//Button to the next page
void MainWindow::on_btnnext_clicked()
{
    int first; //First variable takes the number from the first button
    int last;  //Last variable takes the number from the last button
    QString textf = ui->btn1->text();  //Getting the value
    QString textl = ui->btn5->text();  //Getting the value
    first = textf.toInt();  //Convertion to int
    last = textl.toInt();   //Convertion to int

//    qDebug() << first;
//    qDebug() << last;

    //QPushButton Array to store the buttons from the GUI in order to work later
    QPushButton * options[5] = {ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5};

    //Initialize position in array
    int pos = 0;

    //Cycle to increase the page visit and set the name to the buttons
    for (int i = first+1; i <= last+1; i++){
        QString s = QString::number(i);
        options[pos]->setText(s);

//        qDebug() << i;
        pos+=1;
    }
}

void MainWindow::on_btnprev_clicked()
{
    int first; //First variable takes the number from the first button
    int last;  //Last variable takes the number from the last button
    QString textf = ui->btn1->text();  //Getting the value
    QString textl = ui->btn5->text();  //Getting the value
    first = textf.toInt();  //Convertion to int
    last = textl.toInt();   //Convertion to int

//    qDebug() << first;
//    qDebug() << last;

    //QPushButton Array to store the buttons from the GUI in order to work later
    //Array must be backward
    QPushButton * options[5] = {ui->btn5, ui->btn4, ui->btn3, ui->btn2, ui->btn1};

    //Initialize position in array
    int pos = 0;

    //Cycle to increase the page visit and set the name to the buttons
    for (int i = last-1; i >= first-1; i--){

        //There are not negative pages
            QString s = QString::number(i);
            options[pos]->setText(s);

//            qDebug() << i;
            pos+=1;
        }
}

void MainWindow::on_btnnext_2_clicked()
{
    int last;  //Last variable takes the number from the last button
    QString textl = ui->btn5->text();  //Getting the value
    last = textl.toInt();   //Convertion to int

    //QPushButton Array to store the buttons from the GUI in order to work later
    QPushButton * options[5] = {ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5};

    //Initialize position in array
    int pos = 0;

    //Cycle to increase the page visit and set the name to the buttons
    for (int i = last+1; i <= last+5; i++){
        QString s = QString::number(i);
        options[pos]->setText(s);

//        qDebug() << i;
        pos+=1;
    }
}

void MainWindow::on_btnprev_2_clicked()
{
    int first; //First variable takes the number from the first button
    QString textf = ui->btn1->text();  //Getting the value
    first = textf.toInt();  //Convertion to int

    //QPushButton Array to store the buttons from the GUI in order to work later
    //Array must be backward
    QPushButton * options[5] = {ui->btn5, ui->btn4, ui->btn3, ui->btn2, ui->btn1};

    //Initialize position in array
    int pos = 0;

    //Cycle to increase the page visit and set the name to the buttons
    for (int i = first-1; i >= first-5; i--){

        //There are not negative pages
            QString s = QString::number(i);
            options[pos]->setText(s);

//            qDebug() << i;
            pos+=1;
        }
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;
    //qDebug() << numSteps;

    if (event->orientation() == Qt::Vertical) {
        numSteps++;
        if (numSteps > 0){
            Page(numSteps);
        }
        if (numSteps == 0){
            Page(numSteps);
        }
    }
    event->accept();
}
int MainWindow::Page(int parameter){
    int conteo=0;
    if (parameter > 0){
        conteo++;
        QString s = QString::number(conteo);
        ui->pagel->setText(s);
        qDebug()<<  conteo;
    }
    if (parameter == 0){
        QString s = QString::number(conteo);
        ui->pagel->setText(s);
        qDebug()<< conteo;
        conteo--;
    }
}

void MainWindow::File(QString name){
    QStringList wordList;

        //File name
        QFile f("movie_metadata.csv");

        if (f.open(QIODevice::ReadOnly))
        {
            //file opened successfully
            QString data;
            data = f.readAll();  //Reading the file
            qDebug () << data;
            wordList = data.split(','); //Separating the file when find a ","

            //Funtion to get the columns
            const QStringList fields { data.split(',') };
            const QString column { fields[38] };

//            qDebug() <<wordList.length();
//            qDebug() << wordList[11];
//            qDebug() << "";
//            qDebug() << column;

            //Movie Ranking
            int i = 11; //Initial position where are the movies titles
            while(i<wordList.length()) //Goes through all de dataset getting the titles
            {
                qDebug() << wordList[i];
                i = i + 27;
            }

            //Director info
            i = 1; //Initial position where are the directors
            while(i<wordList.length()) //Goes through all de dataset getting the titles
            {
                qDebug() << wordList[i];
                i = i + 27;
            }

            //Close the file after parsing it
            f.close();
        }
}





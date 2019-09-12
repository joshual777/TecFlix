#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>

#include <QtDebug>
#include <QWheelEvent>
#include <QStringList>
#include <qfile.h>
#include <QTextStream>
#include <QFileDialog>

#include "list.h"
#include "list.cpp"

#include <page.h>
#include <page.cpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineselect->setVisible(false);
    ui->lineupload->setVisible(false);
    ui->btnselect->setVisible(false);
    ui->btnupload->setVisible(false);
}

//Variables to take pages

int static current, previous, nextt;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn1_clicked()
{

    QString page = ui->btn1->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    nextt = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << nextt;
    qDebug() << "first";
}

void MainWindow::on_btn2_clicked()
{
    QString page = ui->btn2->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    nextt = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << nextt;
    qDebug() << "second";
}

void MainWindow::on_btn3_clicked()
{
    QString page = ui->btn3->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    nextt = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << nextt;
    qDebug() << "third";
}

void MainWindow::on_btn4_clicked()
{
    QString page = ui->btn4->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    nextt = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << nextt;
    qDebug() << "fourth";
}

void MainWindow::on_btn5_clicked()
{
    QString page = ui->btn5->text();
    previous = page.toInt() -1 ;
    current = page.toInt();
    nextt = page.toInt() +1;

    qDebug() << previous;
    qDebug() << current;
    qDebug() << nextt;
    qDebug() << "fifth";
}

//Button to the next page
void MainWindow::on_btnnext_clicked()
{
    int first; //First variable takes the number from the first button
    int last;  //Last variable takes the number from the last button
    QString textf = ui->btn1->text();  //Getting the value
    QString textl = ui->btn5->text();  //Getting the value
    first = textf.toInt();  //Conversion to int
    last = textl.toInt();   //Conversion to int

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
    return  0;
}

void MainWindow::on_btnselect_clicked()
{
    m_fileName = QFileDialog::getOpenFileName(this, "Get Any File");
    ui->lineselect->setText(m_fileName);

    //QLabel array to diplay the titles inside them
    QLabel * options[9] = {ui->lmovie1, ui->lmovie2, ui->lmovie3, ui->lmovie4, ui->lmovie5, ui->lmovie6,
                          ui->lmovie7, ui->lmovie8, ui->lmovie9};


    //Reciever the movies titles
    QString *reciever;
    reciever = chargefile(m_fileName);
    qDebug() << "BREAK";
    //chargefile(m_fileName);
    qDebug() << *(reciever);

    ui->lmovie1->setText(*(reciever));

    //chargefile(m_fileName);
//    for (int i = 0; i <= 9; i++){
//        //options[i]->setText(*reciever);
//        qDebug() << "JOSHUA";
//        qDebug() << *(reciever+i);
//    }
}

void MainWindow::on_btnupload_clicked()
{

//    QStringList wordList, longer;
//    int colums, totalrows, amount;

//     m_file = new QFile(m_fileName);
//     if (m_file->open(QIODevice::ReadOnly))
//     {
//         //File opened successfully

//         //Variables to manage the file
//         QString data;  //Read the whole csv file
//         QString size;  //Read just the first line in order to take the main information

//         size = m_file->readLine();    //Size read the first line
//         data = m_file->readAll();  //Reading the file

//         longer = size.split(','); //Sparating the first row when finds a ','
//         wordList = data.split(','); //Separating the file when finds a ","

//         colums = longer.length() - 1; //This variable gives me the amount of colums
//         totalrows = wordList.length() /colums +1; //This variable gives the amount of rows in the csv
//         amount = wordList.length(); //Variable who has the amount of the whole csv


//         //Monitorizing the varibales
//         qDebug() << colums;
//         qDebug() << totalrows;
//         qDebug() << amount;

//         //The array can  manage the whole csv in bigger cases will happen the same
//         //but in order to work better it will be segment in fractions of 1200 movies to manage easily
//         //file in eficienttly


//         /////////////////////////////////////////////////////////////////////////////////////////////////////

//         // dynamically allocate memory of size M*N
//         QString* A = new QString[totalrows * colums];

//         int counter = 0;

//         // assign values to allocated memory
//         for (int i = 0; i < 1200; i++){
//             qDebug() << i;
//             for (int j = 0; j < colums; j++){
//                 qDebug() << j;
//                 *(A + i*colums + j) = wordList[counter];
//                 counter++;
//                 qDebug() << *(A + i*colums + j);
//            }
//         }

//         qDebug() << "JOSHUA";
//         qDebug() << (A + 0*colums)[11];
//         qDebug() << (A + 2*colums)[11];

////         // print the 2D array
////         for (int i = 0; i < M; i++)
////         {
////             for (int j = 0; j < N; j++)
////                 std::cout << *(A + i*N + j) << " ";	// or (A + i*N)[j])

////             std::cout << std::endl;
////         }


//         // deallocate memory
//         delete[] A;
//     }

}

void MainWindow::on_btnfile_clicked()
{
    ui->lineselect->setVisible(true);
    ui->lineupload->setVisible(true);
    ui->btnselect->setVisible(true);
    ui->btnupload->setVisible(true);
}

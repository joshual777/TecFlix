#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QWheelEvent>
#include <QStringList>
#include <qfile.h>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "list.h"
//#include "list.cpp"

#include "html.h"
#include "html.cpp"

#include <page.h>
#include <page.cpp>

#include <label.h>
#include <viewer.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    //Check if there is internet aviable
//    QNetworkAccessManager nam;
//    QNetworkRequest req(QUrl("https://www.imdb.com"));
//    QNetworkReply* reply = nam.get(req);
//    QEventLoop loop;
//    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//    loop.exec();
//    //If there is internet the program can be execute
//    if (reply->bytesAvailable()){
//        QMessageBox::information(this, "Info", "You are connected to the internet :)");
//    }
//    //If threre is not internet the program will close
//    else{
//        QMessageBox::critical(this, "Info", "You are not connected to the internet :(");
//        ui->lineselect->setVisible(false);
//        ui->btnselect->setVisible(false);
//        ui->btnupload->setVisible(false);
//        ui->label_10->setVisible(false);
//    }

    //Making thos elements invisibles in first entrance
    ui->lineselect->setVisible(false);
    ui->btnselect->setVisible(false);
    ui->btnupload->setVisible(false);

//    QPixmap pix("/home/joshua/Documentos/movie.jpg");
//    int w = ui->lposter->width();
//    int h = ui->lposter->height();
//    ui->lposter->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    //Creating the slot for the labels, it will has the function to display the images and videos in a new window
    connect(ui->lmovie1, SIGNAL(Mouse_Pressed()),this, SLOT(Mouse_Pressed()));

}

//Variables to take pages

int static current, previous, nextt;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetImages(QString images){
    qDebug() << images + "JOSHUA";
}


void RecpetorURL(QString links){
    List <QString> Urls;
    MainWindow SET;
    Urls.add_end(links);
    for (int i = 0; i<=Urls.size(); i++){
        Urls.getbyposicion(i);
        SET.SetImages(Urls.getbyposicion(i));
    }

}
void take(QString element){

    if(element.contains("https")){
        //qDebug() <<element;
        htmlGet({element.remove(4)}, [](const QString &body){
            //QString arra [1];
            List <QString> line;
            QString sender;
            QRegExp rx("https");// match a comma or a space
            QStringList list = body.split(rx, QString::SkipEmptyParts);
            //arra[0] = "https" + list.takeAt(14).left(list.takeAt(14).lastIndexOf('@'))+ "@._V1_.jpg";
            line.add_end("https" + list.takeAt(13).left(114));
            qDebug()<< line.getbyposicion(0);
            sender=line.getbyposicion(0);
            RecpetorURL(sender);

            //qDebug() << arra[0];
            //return arra[0];
            //list.takeAt(13).lastIndexOf('@')
       });
        qDebug() << "A";
    }
    else{
        if (element.insert( 4, "s" ).contains("https")){
            //qDebug() << element.remove(4);
            htmlGet({element.remove(4)}, [](const QString &body){
                List <QString> line;
                QString sender;
                //QString arra [1];
                QRegExp rx("https");// match a comma or a space
                QStringList list = body.split(rx, QString::SkipEmptyParts);
                //arra[0] = "https" + list.takeAt(13).left(list.takeAt(13).lastIndexOf('@'))+ "@._V1_.jpg";
                line.add_end("https" + list.takeAt(13).left(114));
                line.getbyposicion(0);
                qDebug()<< line.getbyposicion(0);
                sender=line.getbyposicion(0);
                RecpetorURL(sender);

                //qDebug() << arra[0];
                //return arra[0];
           });
        }
        qDebug() << "B";
    }
}

void MainWindow::Displaying(int getpage){

    QString reciever;  //This pointer is assign in order to receive teh data from the csv

    //Giving the previous page
    List <QString> previous_page;
    QString elementp;

    //Giving the current page
    List <QString> current_page;
    QString elementc;

    //Giving the next page
    List <QString> next_page;
    QString elementn;

    //This variables are in order to give the current, previous and  next position
    //Those are going to store the pages
    previous = getpage -1;
    current = getpage;
    nextt = getpage +1;

    //QLabel pointer array to diplay the titles inside them
    QLabel * options[9] = {ui->lmovie1, ui->lmovie2, ui->lmovie3, ui->lmovie4, ui->lmovie5, ui->lmovie6,
                          ui->lmovie7, ui->lmovie8, ui->lmovie9};

    //Variables to count and extract the exact positions from one specific cell
    int pos = current;  //Take the current page
    int slicer = pos*9 - 9;  //Give the multiple of 9 in order to count from that page
    int past = previous*9 -9; //Gives the number start from the previous page
    int follow = nextt*9 -9;  //Gives the number start from the next page
    int index = 0;   //To count the labels

//    qDebug() << pos;
//    qDebug() << slicer;
//    qDebug() << follow;
//    qDebug() << past;

    //A cycle to extract the information
    while(slicer < current*9){

        //Storing the previous page
        elementp = GetPage(ui->lineselect->text(),past);
        previous_page.add_end(elementp);
        qDebug() << previous_page.getbyposicion(index);

        //Storing the current page
        elementc = GetPage(ui->lineselect->text(),slicer);
        current_page.add_end(elementc);
        qDebug() << current_page.getbyposicion(index);

        //Storing the next page
        elementn= GetPage(ui->lineselect->text(),follow);
        next_page.add_end(elementn);
        qDebug() << next_page.getbyposicion(index);

        //Get the url storing on the given csv file
        reciever = Search(ui->lineselect->text(), slicer);
        options[index]->setText((reciever));

        take((reciever));
        //qDebug() << *(reciever);
        slicer++;
        past++;
        follow++;
        index++;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(QUrl("https://m.media-amazon.com/images/M/MV5BNjk4OTczOTk0NF5BMl5BanBnXkFtZTcwNjQ0NzMzMw@@._V1_UY1200_CR90,0,630,1200_AL_.jpg"));
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply->readAll();
    QImage img(20, 20, QImage::Format_Indexed8);
    img.loadFromData(bytes);
    int w = ui->lmovie1->width();
    int h = ui->lmovie1->height();
    ui->lmovie1->setPixmap(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));


    //HERE IS WHERE THE CICLK MUST BE CREATED IN ORDER TO ACCESS THE MOVIE TITLE DATA

    qDebug() << previous;
    qDebug() << current;
    qDebug() << nextt;
    qDebug() << "first";
}

//Method to give the first page, with the 9 posters on it
void MainWindow::on_btn1_clicked(){

    //Catch the number from the button to give the page
    QString thispage = ui->btn1->text();
    int sendpage = thispage.toInt();  //Convertion from QString to int
    Displaying(sendpage);  //The page will send to the Displaying method
}


//Method to give the second page, with the 9 posters on it
void MainWindow::on_btn2_clicked(){
    //Catch the number from the button to give the page
    QString thispage = ui->btn2->text();
    int sendpage = thispage.toInt();  //Convertion from QString to int
    Displaying(sendpage);  //The page will send to the Displaying method

    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(QUrl("https://m.media-amazon.com/images/M/MV5BMTU2NTYxODcwMF5BMl5BanBnXkFtZTcwNDk1NDY0Nw@@._V1_.jpg"));
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply->readAll();
    QImage img(20, 20, QImage::Format_Indexed8);
    img.loadFromData(bytes);
    int w = ui->lmovie1->width();
    int h = ui->lmovie1->height();
    ui->lmovie2->setPixmap(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
}


//Method to give the third page, with the 9 posters on it
void MainWindow::on_btn3_clicked(){
    //Catch the number from the button to give the page
    QString thispage = ui->btn3->text();
    int sendpage = thispage.toInt();  //Convertion from QString to int
    Displaying(sendpage);  //The page will send to the Displaying method
}


//Method to give the fourth page, with the 9 posters on it
void MainWindow::on_btn4_clicked(){
    //Catch the number from the button to give the page
    QString thispage = ui->btn4->text();
    int sendpage = thispage.toInt();  //Convertion from QString to int
    Displaying(sendpage);  //The page will send to the Displaying method
}

//Method to give the fifth page, with the 9 posters on it
void MainWindow::on_btn5_clicked(){
    //Catch the number from the button to give the page
    QString thispage = ui->btn5->text();
    int sendpage = thispage.toInt();  //Convertion from QString to int
    Displaying(sendpage);  //The page will send to the Displaying method
}


//Button to the next page
void MainWindow::on_btnnext_clicked(){
    int first; //First variable takes the number from the first button
    int last;  //Last variable takes the number from the last button
    QString textf = ui->btn1->text();  //Getting the value
    QString textl = ui->btn5->text();  //Getting the value
    first = textf.toInt();  //Conversion to int
    last = textl.toInt();   //Conversion to int

    //QPushButton Array to store the buttons from the GUI in order to work later
    QPushButton * options[5] = {ui->btn1, ui->btn2, ui->btn3, ui->btn4, ui->btn5};

    //Initialize position in array
    int pos = 0;

    //Cycle to increase the page visit and set the name to the buttons
    for (int i = first+1; i <= last+1; i++){
        QString s = QString::number(i);
        options[pos]->setText(s);
        pos+=1;
    }
}

//Method to return to next page, from the last position
void MainWindow::on_btnprev_clicked(){
    int first; //First variable takes the number from the first button
    int last;  //Last variable takes the number from the last button
    QString textf = ui->btn1->text();  //Getting the value
    QString textl = ui->btn5->text();  //Getting the value
    first = textf.toInt();  //Convertion to int
    last = textl.toInt();   //Convertion to int

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
            pos+=1;
        }
}


//This method gives the previous five options (numbers) from the first position
void MainWindow::on_btnnext_2_clicked(){
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
        pos+=1;
    }
}

//This method gives the next five options (numbers) from the last position
void MainWindow::on_btnprev_2_clicked(){
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


//Method to let the scroll
void MainWindow::wheelEvent(QWheelEvent *event){
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

//This method let the user choose teh file from the system
void MainWindow::on_btnselect_clicked(){
    m_fileName = QFileDialog::getOpenFileName(this, "Get Any File");   //Take the name of the file
    ui->lineselect->setText(m_fileName);  //Shows the name of the file into the label
    chargefile(m_fileName);     //The function "chargefile" from the page class will open and read the whole file
}


void MainWindow::on_btnupload_clicked()
{
}

//Pressing the file button in order to upload the csv to the program
void MainWindow::on_btnfile_clicked(){
    //Just make the elemts visbles in order to upload the file
    ui->lineselect->setVisible(true);
    ui->btnselect->setVisible(true);
    ui->btnupload->setVisible(true);
}

void MainWindow::Mouse_Pressed(){

    Viewer  Viewer;
    Viewer.setModal(true);
    Viewer.exec();

    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
    QNetworkRequest request(QUrl("https://m.media-amazon.com/images/M/MV5BMTU2NTYxODcwMF5BMl5BanBnXkFtZTcwNDk1NDY0Nw@@._V1_.jpg"));
    QNetworkReply *reply = netAccManager->get(request);
    QEventLoop loop;
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    QByteArray bytes = reply->readAll();
    QImage img(20, 20, QImage::Format_Indexed8);
    img.loadFromData(bytes);
    int w = ui->lmovie1->width();
    int h = ui->lmovie1->height();
    ui->lmovie3->setPixmap(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
}






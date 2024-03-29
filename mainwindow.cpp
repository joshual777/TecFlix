#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QWheelEvent>
#include <QStringList>
#include <qfile.h>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>

//Group of funtions related to handle the process to take the html, get the url and display the poster
#include <unistd.h>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QDesktopServices>


//Using the list class to be implemented
#include "list.h"


//Use method from the Page class to take the info related
#include <page.h>
#include <page.cpp>
#include <label.h>

//Library to measure the execution tiem of each function
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Window Main features
    setWindowTitle("TECFLIX");  //Window Title
    setWindowIcon(QIcon("/home/joshua/Documentos/TecFlix/movie.jpg"));  //Icon to project

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


    //Info labels invisible
    //All the gadgets that are going to display must be invisible
    ui->btnback->setVisible(false);
    ui->lback->setVisible(false);
    ui->lstars->setVisible(false);
    ui->ltitle->setVisible(false);
    ui->lmoviedisplay->setVisible(false);
    ui->lmovieinfo->setVisible(false);
    ui->ldirector->setVisible(false);
    ui->lcountry->setVisible(false);
    ui->lgenere->setVisible(false);
    ui->lduration->setVisible(false);
    ui->lyear->setVisible(false);
    ui->llanguage->setVisible(false);
    ui->lcontent->setVisible(false);
    ui->ldirectorname->setVisible(false);
    ui->lactor1->setVisible(false);
    ui->lactor2->setVisible(false);
    ui->lactor3->setVisible(false);
    ui->btnback_2->setVisible(false);
    ui->ldirector_2->setVisible(false);



    /*
                Information of each URL Manager

    Managers in order to take the url image from the html give by the link in the csv and display the image on each label
    Those managers have the main funtion to take the url form the csv, parse the html
    Once the html form the url has got, the html is cut and take the position of the image url
    This url is pass to the next function in order to display the image on the buttons

    */

    //MOVIE 1
    manager = new QNetworkAccessManager();
        QObject::connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                List<QString> line;
                QString answer = reply->readAll();
                QRegExp rx("https");// match a comma or a space
                QStringList list = answer.split(rx, QString::SkipEmptyParts);
                line.add_end("https" + list.takeAt(13).left(114));
                qDebug()<< line.getbyposicion(0);

                QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                QNetworkRequest request(QUrl(line.getbyposicion(0)));
                QNetworkReply *replyy = netAccManager->get(request);
                QEventLoop loop;
                QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                loop.exec();
                QByteArray bytes = replyy->readAll();
                QImage img(20, 20, QImage::Format_Indexed8);
                img.loadFromData(bytes);
                int w = ui->bmovie1->width();
                int h = ui->bmovie1->height();
                ui->bmovie1->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
            }
        );

        //MOVIE 2
        manager2 = new QNetworkAccessManager();
            QObject::connect(manager2, &QNetworkAccessManager::finished,
                this, [=](QNetworkReply *reply) {
                    List<QString> line;
                    QString answer = reply->readAll();
                    QRegExp rx("https");// match a comma or a space
                    QStringList list = answer.split(rx, QString::SkipEmptyParts);
                    line.add_end("https" + list.takeAt(13).left(114));
                    qDebug()<< line.getbyposicion(0);

                    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                    QNetworkRequest request(QUrl(line.getbyposicion(0)));
                    QNetworkReply *replyy = netAccManager->get(request);
                    QEventLoop loop;
                    QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                    loop.exec();
                    QByteArray bytes = replyy->readAll();
                    QImage img(20, 20, QImage::Format_Indexed8);
                    img.loadFromData(bytes);
                    int w = ui->bmovie2->width();
                    int h = ui->bmovie2->height();
                    ui->bmovie2->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                }
            );

            //MOVIE 3
            manager3 = new QNetworkAccessManager();
                QObject::connect(manager3, &QNetworkAccessManager::finished,
                    this, [=](QNetworkReply *reply) {
                        List<QString> line;
                        QString answer = reply->readAll();
                        QRegExp rx("https");// match a comma or a space
                        QStringList list = answer.split(rx, QString::SkipEmptyParts);
                        line.add_end("https" + list.takeAt(13).left(114));
                        qDebug()<< line.getbyposicion(0);

                        QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                        QNetworkRequest request(QUrl(line.getbyposicion(0)));
                        QNetworkReply *replyy = netAccManager->get(request);
                        QEventLoop loop;
                        QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                        loop.exec();
                        QByteArray bytes = replyy->readAll();
                        QImage img(20, 20, QImage::Format_Indexed8);
                        img.loadFromData(bytes);
                        int w = ui->bmovie3->width();
                        int h = ui->bmovie3->height();
                        ui->bmovie3->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                    }
                );

                //MOVIE 4
                manager4 = new QNetworkAccessManager();
                    QObject::connect(manager4, &QNetworkAccessManager::finished,
                        this, [=](QNetworkReply *reply) {
                            List<QString> line;
                            QString answer = reply->readAll();
                            QRegExp rx("https");// match a comma or a space
                            QStringList list = answer.split(rx, QString::SkipEmptyParts);
                            line.add_end("https" + list.takeAt(13).left(114));
                            qDebug()<< line.getbyposicion(0);

                            QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                            QNetworkRequest request(QUrl(line.getbyposicion(0)));
                            QNetworkReply *replyy = netAccManager->get(request);
                            QEventLoop loop;
                            QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                            loop.exec();
                            QByteArray bytes = replyy->readAll();
                            QImage img(20, 20, QImage::Format_Indexed8);
                            img.loadFromData(bytes);
                            int w = ui->bmovie4->width();
                            int h = ui->bmovie4->height();
                            ui->bmovie4->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                        }
                    );

                    //MOVIE 5
                    manager5 = new QNetworkAccessManager();
                        QObject::connect(manager5, &QNetworkAccessManager::finished,
                            this, [=](QNetworkReply *reply) {
                                List<QString> line;
                                QString answer = reply->readAll();
                                QRegExp rx("https");// match a comma or a space
                                QStringList list = answer.split(rx, QString::SkipEmptyParts);
                                line.add_end("https" + list.takeAt(13).left(114));
                                qDebug()<< line.getbyposicion(0);

                                QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                                QNetworkRequest request(QUrl(line.getbyposicion(0)));
                                QNetworkReply *replyy = netAccManager->get(request);
                                QEventLoop loop;
                                QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                                loop.exec();
                                QByteArray bytes = replyy->readAll();
                                QImage img(20, 20, QImage::Format_Indexed8);
                                img.loadFromData(bytes);
                                int w = ui->bmovie5->width();
                                int h = ui->bmovie5->height();
                                ui->bmovie5->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                            }
                        );

                        //MOVIE 6
                        manager6 = new QNetworkAccessManager();
                            QObject::connect(manager6, &QNetworkAccessManager::finished,
                                this, [=](QNetworkReply *reply) {
                                    List<QString> line;
                                    QString answer = reply->readAll();
                                    QRegExp rx("https");// match a comma or a space
                                    QStringList list = answer.split(rx, QString::SkipEmptyParts);
                                    line.add_end("https" + list.takeAt(13).left(114));
                                    qDebug()<< line.getbyposicion(0);

                                    QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                                    QNetworkRequest request(QUrl(line.getbyposicion(0)));
                                    QNetworkReply *replyy = netAccManager->get(request);
                                    QEventLoop loop;
                                    QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                                    loop.exec();
                                    QByteArray bytes = replyy->readAll();
                                    QImage img(20, 20, QImage::Format_Indexed8);
                                    img.loadFromData(bytes);
                                    int w = ui->bmovie6->width();
                                    int h = ui->bmovie6->height();
                                    ui->bmovie6->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                                }
                            );

                            //MOVIE 7
                            manager7 = new QNetworkAccessManager();
                                QObject::connect(manager7, &QNetworkAccessManager::finished,
                                    this, [=](QNetworkReply *reply) {
                                        List<QString> line;
                                        QString answer = reply->readAll();
                                        QRegExp rx("https");// match a comma or a space
                                        QStringList list = answer.split(rx, QString::SkipEmptyParts);
                                        line.add_end("https" + list.takeAt(13).left(114));
                                        qDebug()<< line.getbyposicion(0);

                                        QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                                        QNetworkRequest request(QUrl(line.getbyposicion(0)));
                                        QNetworkReply *replyy = netAccManager->get(request);
                                        QEventLoop loop;
                                        QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                                        loop.exec();
                                        QByteArray bytes = replyy->readAll();
                                        QImage img(20, 20, QImage::Format_Indexed8);
                                        img.loadFromData(bytes);
                                        int w = ui->bmovie7->width();
                                        int h = ui->bmovie7->height();
                                        ui->bmovie7->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                                    }
                                );


                                //MOVIE 8
                                manager8 = new QNetworkAccessManager();
                                    QObject::connect(manager8, &QNetworkAccessManager::finished,
                                        this, [=](QNetworkReply *reply) {
                                            List<QString> line;
                                            QString answer = reply->readAll();
                                            QRegExp rx("https");// match a comma or a space
                                            QStringList list = answer.split(rx, QString::SkipEmptyParts);
                                            line.add_end("https" + list.takeAt(13).left(114));
                                            qDebug()<< line.getbyposicion(0);

                                            QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                                            QNetworkRequest request(QUrl(line.getbyposicion(0)));
                                            QNetworkReply *replyy = netAccManager->get(request);
                                            QEventLoop loop;
                                            QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                                            loop.exec();
                                            QByteArray bytes = replyy->readAll();
                                            QImage img(20, 20, QImage::Format_Indexed8);
                                            img.loadFromData(bytes);
                                            int w = ui->bmovie8->width();
                                            int h = ui->bmovie8->height();
                                            ui->bmovie8->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                                        }
                                    );

                                    //MOVIE 9
                                    manager9 = new QNetworkAccessManager();
                                        QObject::connect(manager9, &QNetworkAccessManager::finished,
                                            this, [=](QNetworkReply *reply) {
                                                List<QString> line;
                                                QString answer = reply->readAll();
                                                QRegExp rx("https");// match a comma or a space
                                                QStringList list = answer.split(rx, QString::SkipEmptyParts);
                                                line.add_end("https" + list.takeAt(13).left(114));
                                                qDebug()<< line.getbyposicion(0);

                                                QNetworkAccessManager* netAccManager = new QNetworkAccessManager;
                                                QNetworkRequest request(QUrl(line.getbyposicion(0)));
                                                QNetworkReply *replyy = netAccManager->get(request);
                                                QEventLoop loop;
                                                QObject::connect(replyy,SIGNAL(finished()),&loop,SLOT(quit()));
                                                loop.exec();
                                                QByteArray bytes = replyy->readAll();
                                                QImage img(20, 20, QImage::Format_Indexed8);
                                                img.loadFromData(bytes);
                                                int w = ui->bmovie9->width();
                                                int h = ui->bmovie9->height();
                                                ui->bmovie9->setIcon(QPixmap::fromImage(img).scaled(w,h,Qt::KeepAspectRatio));
                                            }
                                        );
}


//Variables to take pages
int static current, previous, nextt;

MainWindow::~MainWindow()
{
    delete ui;
}

    /*
                                                DISPLAYING FUNCTION
        This function will take the current page when a specific button was clicked, it will cacth the number page
        then it will be send to this function, it will manage all the process of displaying the images, take the url
        get the name of each movie and by the help of a list the link will be send through the manger to the newtworks
        funtions in order to take the html, catch the poster url and displaying in the button
    */

void MainWindow::Displaying(int getpage){


    clock_t begin = clock();  //THis line will start to count the time of the present method

    QString reciever;  //This pointer is assign in order to receive teh data from the csv

    List <QString> images;   //List to take the urls returned from the csv class
    List <QString> posima;  //Write the position (id) of each image

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

    //Variables to count and extract the exact positions from one specific cell
    int pos = current;  //Take the current page
    int slicer = pos*9 - 9;  //Give the multiple of 9 in order to count from that page
    int past = previous*9 -9; //Gives the number start from the previous page
    int follow = nextt*9 -9;  //Gives the number start from the next page
    int index = 0;   //To count the labels


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
        //options[index]->setText(GetPage(ui->lineselect->text(),slicer));

        //take(reciever);

        images.add_end(reciever);
        posima.add_end(QString::number(slicer));

        slicer++;
        past++;
        follow++;
        index++;
   }

    /*
            MANAGER SECTION
       The images list will take the url of each movie contained in the provided csv file
       then each link stored in the list will be send to an specifc manager, because
       each of them is assocaite the one button
    */

    //Manager for movie
    request.setUrl(QUrl(images.getbyposicion(0)));
    manager->get(request);

    //Manager for movie 2
    request2.setUrl(QUrl(images.getbyposicion(1)));
    manager2->get(request2);

    //Manager for movie 3
    request3.setUrl(QUrl(images.getbyposicion(2)));
    manager3->get(request3);

    //Manager for movie 4
    request4.setUrl(QUrl(images.getbyposicion(3)));
    manager4->get(request4);

    ////Manager for movie 5
    request5.setUrl(QUrl(images.getbyposicion(4)));
    manager5->get(request5);

    //Manager for movie 6
    request6.setUrl(QUrl(images.getbyposicion(5)));
    manager6->get(request6);

    //Manager for movie 7
    request7.setUrl(QUrl(images.getbyposicion(6)));
    manager7->get(request7);

    //Manager for movie 8
    request8.setUrl(QUrl(images.getbyposicion(7)));
    manager8->get(request8);

    //Manager for movie 9
    request9.setUrl(QUrl(images.getbyposicion(8)));
    manager9->get(request9);


    //Storing in file index of position to pass to the new window
    QFile file( "file.txt" );  //Take the file name
    if ( file.open(QIODevice::ReadWrite) )  //Check if the file is open
    {

        //It will write the id if each movie
        QTextStream stream( &file );
        int j = 0;
        while(j < posima.size()){
            stream << posima.getbyposicion(j) << endl;
            j++;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //HERE IS WHERE THE CICLK MUST BE CREATED IN ORDER TO ACCESS THE MOVIE TITLE DATA


    //Once the link was taken from the csv file, the id are written and the manager catch the link
    //The clock will stop and show the execution of this function


    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC; // Print time
    qDebug() << "EXECUTION TIME";
    qDebug() << elapsed_secs;
}

//Method to give the first page, with the 9 posters on it
void MainWindow::on_btn1_clicked(){

    clock_t begin = clock();
    //Catch the number from the button to give the page
    QString thispage = ui->btn1->text();
    int sendpage = thispage.toInt();  //Convertion from QString to int
    Displaying(sendpage);  //The page will send to the Displaying method

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC; // Print time
    qDebug() << "EXECUTION TIME";
    qDebug() << elapsed_secs;
}


//Method to give the second page, with the 9 posters on it
void MainWindow::on_btn2_clicked(){

    //Catch the number from the button to give the page
    QString thispage = ui->btn2->text();
    int sendpage = thispage.toInt();  //Convertion from QString to int
    Displaying(sendpage);  //The page will send to the Displaying method
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
    //This will sende once the mouse's trackball will foward or backward

    //COnverstion of the steps
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;
    //qDebug() << numSteps;


    if (event->orientation() == Qt::Vertical) {
        numSteps++;

        //If the mouse goes backward will show a zero in the selected label
        if (numSteps > 0){
            Page(numSteps);
        }

        //If the mouse goes goward wwill show a zero in the selected label
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

//Pressing the file button in order to upload the csv to the program
void MainWindow::on_btnfile_clicked(){
    //Just make the elemts visbles in order to upload the file
    ui->lineselect->setVisible(true);
    ui->btnselect->setVisible(true);
}

void MainWindow::ShowInfo(int id){

     clock_t begin = clock(); //THis line will start to count the time of the present method


    //Elements visible to display the information related
    ui->lback->setVisible(true);
    ui->btnback->setVisible(true);
    ui->lmoviedisplay->setVisible(true);
    ui->lmovieinfo->setVisible(true);
    ui->btnback_2->setVisible(true);
    ui->ldirector_2->setVisible(true);

    //Movie name
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->ltitle->setText(Info(ui->lineselect->text(), id, 1));
    ui->ltitle->setVisible(true);
    ui->lmoviedisplay->setText(Info(ui->lineselect->text(), id, 1));

    //Director name
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->ldirector->setVisible(true);
    ui->ldirectorname->setText(Info(ui->lineselect->text(), id, 2));
    ui->ldirectorname->setVisible(true);

    //Year
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lyear->setText(Info(ui->lineselect->text(), id, 3));
    ui->lyear->setVisible(true);

    //Duration
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lduration->setText(Info(ui->lineselect->text(), id, 4));
    ui->lduration->setVisible(true);

    //Genere
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lgenere->setText(Info(ui->lineselect->text(), id, 5));
    ui->lgenere->setVisible(true);

    //Content
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lcontent->setText(Info(ui->lineselect->text(), id, 6));
    ui->lcontent->setVisible(true);

    //Country
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lcountry->setText(Info(ui->lineselect->text(), id, 7));
    ui->lcountry->setVisible(true);

    //Language
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->llanguage->setText(Info(ui->lineselect->text(), id, 8));
    ui->llanguage->setVisible(true);


    //Stars name
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lstars->setVisible(true);

    //Actor_1
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lactor1->setText(Info(ui->lineselect->text(), id, 9));
    ui->lactor1->setVisible(true);

    //Actor_2
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lactor2->setText(Info(ui->lineselect->text(), id, 10));
    ui->lactor2->setVisible(true);

    //Actor_3
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->lactor3->setText(Info(ui->lineselect->text(), id, 11));
    ui->lactor3->setVisible(true);

    //Movie Url
    /*
        This will get the position in the list related to catch the specific data
        it recieve that one will be displaying in the related label, remember
        that the file was convert into a matrix made by adyacents lists
        so the line "Info" will send three parameters, the file name to catch the data
        the id catch form the buttons which means the movie position in the row
        and the index which is the position of the request data and the one which is returned
    */
    ui->ldirector_2->setVisible(true);
    ui->ldirector_2->setText(Info(ui->lineselect->text(), id, 0));


    //Once the link was taken from the csv file, the id are written and the manager catch the link
    //The clock will stop and show the execution of this function
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC; // Print time
    qDebug() << "EXECUTION TIME";
    qDebug() << elapsed_secs;
}

  /*
            Buttons sender

       The id of each movie was written into a text file
       so by pressing each button it will catch tha id and at the same time
       it will be send to the Info displaying funtion
  */
void MainWindow::on_bmovie1_clicked(){

    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        ui->bmovie1->setVisible(true);
        QString m1 = file.readAll().mid(0,2);
        ShowInfo(m1.toInt());
    }
}

/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie2_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QString m1 = file.readAll().mid(3,5).left(2);
        ShowInfo(m1.toInt());
    }
}

/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie3_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QString m1 = file.readAll().mid(6,8).left(2);
        ShowInfo(m1.toInt());
    }
}

/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie4_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QString m1 = file.readAll().mid(9,11).left(2);
        ShowInfo(m1.toInt());
    }
}

/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie5_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QString m1 = file.readAll().mid(12,14).left(2);
        ShowInfo(m1.toInt());
    }
}

/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie6_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
       QString m1 = file.readAll().mid(15,17).left(2);
       ShowInfo(m1.toInt());
    }
}

/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie7_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QString m1 = file.readAll().mid(18,20).left(2);
        ShowInfo(m1.toInt());
    }
}


/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie8_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QString m1 = file.readAll().mid(21,23).left(2);
        ShowInfo(m1.toInt());
    }
}


/*
          Buttons sender

     The id of each movie was written into a text file
     so by pressing each button it will catch tha id and at the same time
     it will be send to the Info displaying funtion
*/
void MainWindow::on_bmovie9_clicked(){
    QFile file( "file.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
       QString m1 = file.readAll().mid(24,26).left(2);
       ShowInfo(m1.toInt());
    }
}


//This button will close the info labels
void MainWindow::on_btnback_clicked()
{
    ui->btnback->setVisible(false);
    ui->lback->setVisible(false);
    ui->lstars->setVisible(false);
    ui->ltitle->setVisible(false);
    ui->lmoviedisplay->setVisible(false);
    ui->lmovieinfo->setVisible(false);
    ui->ldirector->setVisible(false);
    ui->lcountry->setVisible(false);
    ui->lgenere->setVisible(false);
    ui->lduration->setVisible(false);
    ui->lyear->setVisible(false);
    ui->llanguage->setVisible(false);
    ui->lcontent->setVisible(false);
    ui->ldirectorname->setVisible(false);
    ui->lactor1->setVisible(false);
    ui->lactor2->setVisible(false);
    ui->lactor3->setVisible(false);
    ui->btnback_2->setVisible(false);
    ui->ldirector_2->setVisible(false);
}


//The purpose of this button it to redirect the user to the IMDB web site of the selected movie
void MainWindow::on_btnback_2_clicked()
{
    QString url = ui->ldirector_2->text();
    QDesktopServices::openUrl(url);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list.h>
#include <page.h>
#include <node.h>

#include <QString>
#include <QNetworkAccessManager>
#include <QFile>

namespace Ui {
class MainWindow;
}

class QNetworkAcessManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


void setName(const QString &name);


private slots:

    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btnnext_clicked();
    void on_btnprev_clicked();
    void on_btnnext_2_clicked();
    void on_btnprev_2_clicked();
    void wheelEvent(QWheelEvent *event);
    int Page(int parameter);
    void on_btnselect_clicked();
    void on_btnfile_clicked();
    //void readyRead();
    void Displaying(int getpage);
    //void managerFinished(QNetworkReply *reply);

    void on_bmovie1_clicked();

    void on_bmovie2_clicked();

    void on_bmovie3_clicked();

    void on_bmovie4_clicked();

    void on_bmovie5_clicked();

    void on_bmovie6_clicked();

    void on_bmovie7_clicked();

    void on_bmovie8_clicked();

    void on_bmovie9_clicked();

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    // You must save the file on the heap
    // If you create a file object on the stack, the program will crash.
    QFile *m_file;
    QNetworkAcessManager *mManager;

    //To display movie 1
   QNetworkAccessManager *manager;
   QNetworkRequest request;

   //To display movie 2
   QNetworkAccessManager *manager2;
   QNetworkRequest request2;

   //To display movie 3
   QNetworkAccessManager *manager3;
   QNetworkRequest request3;

   //To display movie 4
   QNetworkAccessManager *manager4;
   QNetworkRequest request4;

   //To display movie 5
   QNetworkAccessManager *manager5;
   QNetworkRequest request5;

   //To display movie 6
   QNetworkAccessManager *manager6;
   QNetworkRequest request6;

   //To display movie 7
   QNetworkAccessManager *manager7;
   QNetworkRequest request7;

   //To display movie 8
   QNetworkAccessManager *manager8;
   QNetworkRequest request8;

   //To display movie 9
   QNetworkAccessManager *manager9;
   QNetworkRequest request9;
};

#endif // MAINWINDOW_H

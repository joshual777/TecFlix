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
    void on_btnupload_clicked();
    void on_btnfile_clicked();
    void readyRead();
    void Mouse_Pressed();
    void Displaying(int getpage);
    void managerFinished(QNetworkReply *reply);

public slots:
    void SetImages(QString images);

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    // You must save the file on the heap
    // If you create a file object on the stack, the program will crash.
    QFile *m_file;
    QNetworkAcessManager *mManager;


      QNetworkAccessManager *manager;
        QNetworkRequest request;
};

#endif // MAINWINDOW_H

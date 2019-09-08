#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list.h>
#include <node.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



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
    void File(QString name);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

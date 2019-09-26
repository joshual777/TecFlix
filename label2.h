#ifndef LABEL2_H
#define LABEL2_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

class Label2 : public QLabel
{
    Q_OBJECT
public:
    Label2();
    explicit Label2(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *eve);

signals:
     void Mouse_Pressed2();

public slots:

};



#endif // LABEL_H

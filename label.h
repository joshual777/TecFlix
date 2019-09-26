#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label();
    explicit Label(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *ev);

signals:
     void Mouse_Pressed();

public slots:

};



#endif // LABEL_H

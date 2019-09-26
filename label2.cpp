#include "label2.h"
#include <QLabel>

//                                        LABEL CLASS
// The purpose of this class is to make the label clickable to open  new window


Label2::Label2(QWidget *parent) :
    QLabel(parent)
{

}




//The purpose of this method is to give the sign when a label was pressed
void Label2::mousePressEvent(QMouseEvent *eve){
    emit Mouse_Pressed2();
}



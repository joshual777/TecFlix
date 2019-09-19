#include "label.h"
#include <QLabel>

//                                        LABEL CLASS
// The purpose of this class is to make the label clickable to open  new window


Label::Label(QWidget *parent) :
    QLabel(parent)
{

}

//The purpose of this method is to give the sign when a label was pressed
void Label::mousePressEvent(QMouseEvent *ev){
    emit Mouse_Pressed();
}

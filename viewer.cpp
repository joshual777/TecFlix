#include "viewer.h"
#include "ui_viewer.h"
#include <QtDebug>
#include <QString>

Viewer::Viewer( QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Viewer)

{
    ui->setupUi(this);

    //Making the information labels invisible in a first entrance
    ui->lcountry->setVisible(false);
    ui->lgenere->setVisible(false);
    ui->lduration->setVisible(false);
    ui->lyear->setVisible(false);
    ui->lcontent->setVisible(false);
    ui->ldirectorname->setVisible(false);
    ui->lactor1->setVisible(false);
    ui->lactor2->setVisible(false);
    ui->lactor3->setVisible(false);


}

Viewer::~Viewer()
{
    delete ui;
}




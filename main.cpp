#include <QApplication>
#include "mainwindow.h"
#include <QStyle>
#include <viewer.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setPalette( app.style()->standardPalette() );
    MainWindow m;

    //QObject::connect(&m, SIGNAL(newTextEntered(const QString&)),
                 //        &v, SLOT(onNewTextEntered(const QString&)));

    m.setMinimumSize(600,600);
    m.setMaximumSize(600,800);

    m.show();
    return app.exec();
}

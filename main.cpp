#include <QApplication>
#include "mainwindow.h"
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("plastique");
    app.setPalette( app.style()->standardPalette() );
    MainWindow m;
    m.setMinimumSize(600,600);
    m.setMaximumSize(600,800);
   // m.setCentralWidget();

    m.show();
    return app.exec();
}

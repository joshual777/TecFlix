#include "takeurl.h"


#include <stdlib.h>
#include <QCoreApplication>
#include <QtDebug>
#include <QWheelEvent>
#include <QStringList>
#include <qfile.h>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <curl/curl.h>
#include <QNetworkReply>
#include <QtNetwork>
#include <functional>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <list.h>
#include <list.cpp>



takeurl::takeurl()
{

}
void HtmlGet(const QUrl &url, const std::function<void(const QString&)> &fun) {
   QScopedPointer<QNetworkAccessManager> manager(new QNetworkAccessManager);
   QNetworkReply *response = manager->get(QNetworkRequest(QUrl(url)));
   QObject::connect(response, &QNetworkReply::finished, [response, fun]{
      response->deleteLater();
      response->manager()->deleteLater();
      if (response->error() != QNetworkReply::NoError) return;
      auto const contentType =
            response->header(QNetworkRequest::ContentTypeHeader).toString();
      static QRegularExpression re("charset=([!-~]+)");
      auto const match = re.match(contentType);
      if (!match.hasMatch() || 0 != match.captured(1).compare("utf-8", Qt::CaseInsensitive)) {
         qWarning() << "Content charsets other than utf-8 are not implemented yet:" << contentType;
         return;
      }
      auto const html = QString::fromUtf8(response->readAll());
      fun(html); // do something with the data
   }) && manager.take();
}


QString SendImage(QString inputurl ){

   //qDebug() << in + "JOSHUA";

}
void Take(QString element){

    if(element.contains("https")){
        //qDebug() <<element;
        HtmlGet({element.remove(4)}, [](const QString &body){
            //QString arra [1];

            QString sender;
            List <QString> line;
            QRegExp rx("https");// match a comma or a space
            QStringList list = body.split(rx, QString::SkipEmptyParts);
            //arra[0] = "https" + list.takeAt(14).left(list.takeAt(14).lastIndexOf('@'))+ "@._V1_.jpg";
            line.add_end("https" + list.takeAt(13).left(114));
            sender = line.getbyposicion(0);
            SendImage(sender);
            qDebug()<< line.getbyposicion(0);
            //return sender;
       });
        qDebug() << "A";
    }
    else{
        if (element.insert( 4, "s" ).contains("https")){
            //qDebug() << element.remove(4);
            HtmlGet({element.remove(4)}, [](const QString &body){
                List <QString> line;
                QString sender;
                //QString arra [1];
                QRegExp rx("https");// match a comma or a space
                QStringList list = body.split(rx, QString::SkipEmptyParts);
                //arra[0] = "https" + list.takeAt(13).left(list.takeAt(13).lastIndexOf('@'))+ "@._V1_.jpg";
                line.add_end("https" + list.takeAt(13).left(114));
                line.getbyposicion(0);
                sender = line.getbyposicion(0);
                SendImage(sender);
                qDebug()<< line.getbyposicion(0);
           });
        }
        qDebug() << "B";
    }
}

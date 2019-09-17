#ifndef HTML_H
#define HTML_H



#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <functional>

class html
{
public:
    html();
    ~html();

    void htmlGet(const QUrl &url, const std::function<void(const QString&)> &fun);
};



#endif // HTML_H

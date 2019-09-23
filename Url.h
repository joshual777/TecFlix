#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QString>

class Download
{
public:
    Download();
     ~Download();


    QString SendImage(QString url);
    void TakeURL(QString element);
};

#endif // DOWNLOAD_H

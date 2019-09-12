#ifndef PAGE_H
#define PAGE_H

#include <QString>

class page
{
public:
    page();
    ~page();


    QString chargefile(QString);
    QString *searchfile(QString, int);


};

#endif // PAGE_H

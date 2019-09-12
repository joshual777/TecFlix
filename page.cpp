#include "page.h"

#include <stdlib.h>
#include <QCoreApplication>
#include <QtDebug>
#include <QStringList>
#include <qfile.h>
#include <QTextStream>
#include <QDebug>


page::page()
{

}


QString * chargefile(QString file){

    QFile *m_file;
    QStringList wordList, longer;
    int colums, totalrows, amount;

     m_file = new QFile(file);
     if (m_file->open(QIODevice::ReadOnly))
     {
         //File opened successfully

         //Variables to manage the file
         QString data;  //Read the whole csv file
         QString size;  //Read just the first line in order to take the main information

         size = m_file->readLine();    //Size read the first line
         data = m_file->readAll();  //Reading the file

         longer = size.split(','); //Sparating the first row when finds a ','
         wordList = data.split(','); //Separating the file when finds a ","

         colums = longer.length() - 1; //This variable gives me the amount of colums
         totalrows = wordList.length() /colums +1; //This variable gives the amount of rows in the csv
         amount = wordList.length(); //Variable who has the amount of the whole csv


         //Monitorizing the varibales
         qDebug() << colums;
         qDebug() << totalrows;
         qDebug() << amount;

         //The array can  manage the whole csv in bigger cases will happen the same
         //but in order to work better it will be segment in fractions of 1200 movies to manage easily
         //file in eficienttly


         /////////////////////////////////////////////////////////////////////////////////////////////////////

         //Array to sending data
         static QString  sender[9];

         // dynamically allocate memory of size M*N
         QString* A = new QString[totalrows * colums];

         int counter = 0;

         // assign values to allocated memory
         for (int i = 0; i < 1000; i++){
             //qDebug() << i;
             for (int j = 0; j < colums; j++){
                 //qDebug() << j;
                 *(A + i*colums + j) = wordList[counter];
                 counter++;
                 //qDebug() << *(A + i*colums + j);
            }
         }

         for (int b = 0; b <= 9; b++){
             sender[b] = (A +b*colums)[11];
             qDebug() << (A + b*colums)[11];
             qDebug() << sender[b];
            return sender;
         }



//         // deallocate memory
//         delete[] A;
     }
}

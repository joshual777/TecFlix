#include "page.h"

#include <stdlib.h>
#include <QCoreApplication>
#include <QtDebug>
#include <QStringList>
#include <qfile.h>
#include <QTextStream>
#include <QDebug>

#include <list.h>
#include <list.cpp>


//                                  PAGE CLASS
//This class manages the whole processes related to the csv reading and split their elements
//in order to arrange them into a matrix and give and specific element by a given request

page::page()
{

}


//CHARGE FILE
//This file allows me to place all the metadada into an array, in order to access to its cells for important information
QString chargefile(QString file){

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


         //Working with the list
         List <QString> line;


         int counter = 0;  //Counter variable to add elements to the list

         // assign values to allocated memory
         for (int i = 1; i <= 100; i++){
             //qDebug() << i;
             for (int j = 1; j <= colums; j++){
                 //qDebug() << j;
                 //qDebug() << counter;
                 line.add_end(wordList[counter]);  //Adding elements to the single linked list
                 counter++;   //Incrementing the counter to take the next element
            }
         }

     }
}

//SEARCH
//This method allows me to seach for an specific element into the metadata, for example movies, actors and the movie link
QString Search(QString tosearch, int page){
    QFile *m_file;
    QStringList wordList, longer;
    int colums, totalrows, amount;

     m_file = new QFile(tosearch);
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

         //The array can  manage the whole csv in bigger cases will happen the same
         //but in order to work better it will be segment in fractions of 1200 movies to manage easily
         //file in eficienttly

         /////////////////////////////////////////////////////////////////////////////////////////////////////////

         //Working with the list
         List <QString> line;

         //qDebug()<< page;
         int counter = 0;  //Counter variable to add elements to the list

         // assign values to allocated memory
         for (int i = 1; i <= 9*page; i++){
             //qDebug() << i;
             for (int j = 1; j <= colums; j++){
                 //qDebug() << j;
                 //qDebug() << counter;
                 line.add_end(wordList[counter]);  //Adding elements to the single linked list
                 counter++;   //Incrementing the counter to take the next element
            }
         }
         return line.getbyposicion(page*27-10);  //Returning the node with the link given in the csv as QString
     }
}


//NOTE ADAPT THIS FUNTION TO SSITCH CASE IN ORDER TO DISPALY INFO
//GetPage
//This mehtod gives the page by an given request
QString GetPage(QString tosearch, int page){
    QFile *m_file;
    QStringList wordList, longer;
    int colums, totalrows, amount;

     m_file = new QFile(tosearch);
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


         /////////////////////////////////////////////////////////////////////////////////////////////////////////

         //Working with the list
         List <QString> line;

         //qDebug()<< page;
         int counter = 0;  //Counter variable to add elements to the list

         // assign values to allocated memory
         for (int i = 1; i <= 9*page; i++){
             //qDebug() << i;
             for (int j = 1; j <= colums; j++){
                 //qDebug() << j;
                 //qDebug() << counter;
                 line.add_end(wordList[counter]);  //Adding elements to the single linked list
                 counter++;   //Incrementing the counter to take the next element
            }
         }
         return line.getbyposicion(page*27-16);  //Returning the node with the link given in the csv as QString
     }
}



//ReturnInfo
//This method retunr the info related to the selected movie
QString Info(QString tosearch, int page, int id){
    QFile *m_file;
    QStringList wordList, longer;
    int colums, totalrows, amount;

     m_file = new QFile(tosearch);
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


         /////////////////////////////////////////////////////////////////////////////////////////////////////////

         //Working with the list
         List <QString> line;

         //qDebug()<< page;
         int counter = 0;  //Counter variable to add elements to the list

         // assign values to allocated memory
         for (int i = 1; i <= 1000; i++){
             //qDebug() << i;
             for (int j = 1; j <= colums; j++){
                 //qDebug() << j;
                 //qDebug() << counter;
                 line.add_end(wordList[counter]);  //Adding elements to the single linked list
                 counter++;   //Incrementing the counter to take the next element
            }
         }
         //return line.getbyposicion(page*27-16);  //Returning the node with the link given in the csv as QString

         switch (id) {


         //Movie URL
         case 0:{
             return line.getbyposicion(page*27-10);  //Returning the node with the link given in the csv as QString
         }

         //Return the movie name
         case 1:{
             return line.getbyposicion(page*27-16);  //Returning the node with the link given in the csv as QString
         }
          //Return the director name
         case 2:{
             return line.getbyposicion(page*27-26);  //Returning the node with the link given in the csv as QString
         }

         //Return the year data
         case 3:{
             return line.getbyposicion(page*27-4);  //Returning the node with the link given in the csv as QString
         }

         //Return the duration data
         case 4:{
             return line.getbyposicion(page*27-24);  //Returning the node with the link given in the csv as QString
         }

        //Return genere data
         case 5:{
             return line.getbyposicion(page*27-18);  //Returning the node with the link given in the csv as QString
         }

         //Return the content data
         case 6:{
             return line.getbyposicion(page*27-6);  //Returning the node with the link given in the csv as QString
         }

         //Return Country data
         case 7:{
             return line.getbyposicion(page*27-7);  //Returning the node with the link given in the csv as QString
         }

        //Return language data
         case 8:{
             return line.getbyposicion(page*27-8);  //Returning the node with the link given in the csv as QString
         }

         //Return actor1 data
         case 9:{
             return line.getbyposicion(page*27-17);  //Returning the node with the link given in the csv as QString
         }

         //Return actor2 data
         case 10:{
             return line.getbyposicion(page*27-21);  //Returning the node with the link given in the csv as QString
         }

         //Return actor3 data
         case 11:{
             return line.getbyposicion(page*27-13);  //Returning the node with the link given in the csv as QString
         }






         }
     }
}




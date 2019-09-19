#ifndef LIST_H
#define LIST_H

#include <fstream>
#include <iostream>
#include <QString>
#include <stdlib.h>

#include "node.h"
#include "node.cpp"

using namespace std;

template <class T>

class List
{
public:
    List();
    ~List();

    void add_head(T);
    void del_by_position(int);
    void intersection(List);
    int size();
    T getbyposicion(int);


private:
    Node<T> *m_head;
    int m_num_nodes;
};

#endif //LIST_H

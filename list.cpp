#include "list.h"
#include <QString>

//                       LIST CLASS
//A generic single linked list to store data fron the csv
//ONLY THE important elements are here for the project

// Constructor por defecto
template<typename T>
List<T>::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}


// Insertar at the end
template<typename T>
void List<T>::add_end(T data_)
{
    Node<T> *new_node = new Node<T> (data_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_num_nodes++;
}



//Deletes an element from the single linked list by a given position
template<typename T>
void List<T>::del_by_position(int pos)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = temp->next;

    if (pos < 1 || pos > m_num_nodes) {
        cout << "Out of Range " << endl;
    } else if (pos == 1) {
        m_head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}



//Get a element from a single linked list by a given position
template<typename T>
T List<T>::getbyposicion(int posicion)
{
    Node<T> *temp = m_head;
    T elem;
    for (int i=0; i<this->size(); i++ ){
        if (i==posicion) {
            elem=temp->data;
            return elem;
        }
        else{
            temp = temp->next;
        }
    }
}

//Gives the list size
template<typename T>
int List<T>::size(){
    Node<T> *temp = m_head;
    int tam=0;

    if (!m_head) {
        return tam;
    } else {
        while (temp) {
            tam+=1;
            if (!temp->next) return tam;
            temp = temp->next;
        }
    }
    return tam;
}




template<typename T>
List<T>::~List() {}

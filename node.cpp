#include "node.h"
using namespace std;


//                                       NODE CLASS


//Default Constructor
template<typename T>

Node<T>::Node()
{
    data = NULL;
    next = NULL;
}

//Parameter Constructor
template<typename T>
Node<T>::Node(T data_)
{
    data = data_;
    next = NULL;
}

//Delete all nodes
template<typename T>
void Node<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}

//Print a node
template<typename T>
void Node<T>::print()
{
    cout << data << "-> ";
}

template<typename T>
Node<T>::~Node() {}

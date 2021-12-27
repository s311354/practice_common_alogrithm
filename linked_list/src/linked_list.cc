#include "./linked_list.h"

namespace common
{

template <class T>

LinkedList<T>::~LinkedList() {
    ListElement<T>* current = head;
    ListElement<T>* next = nullptr;

    while (current) {
        next = current->GetNext();
        delete current;
        current = next;
    }
}







} /* common */ 

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

template <class T>
int LinkedList<T>::Size() {
    int size = 0;

    auto* current = head;
    while (current) {
        current = head->GetNext();
        size ++;
    }
}

template <class T>
const T LinkedList<T>::Front() {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    return head->GetData();
}

template <class T>
const T LinkedList<T>::Back() {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    } 

    auto* current = head;
    while (current->GetNext()) {
        current = head->GetNext();
    }

    return current->GetData();
}

template <class T>
void LinkedList<T>::PushFront(T value) {
    auto* node = LinkedList<T>(value); 

    node->SetNext(head);

    head = node;
}

template <class T>
const T LinkedList<T>::PopFront() {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    } 

    ListElement<T> *node = head;
    T value = node->GetData();
    head = head->GetNext();

    delete node;
    return value;
}

template <class T>
void LinkedList<T>::PushBack(T value) {
    auto* node = new ListElement<T>(value);
    node->SetNext(nullptr);

    if (head == nullptr) {
        head = node;
        return;
    }

    ListElement<T> * current = head;
    while (current->GetNext()) {
        current = current->GetNext();
    }

    current->SetNext(node);
}

template <class T>
const T LinkedList<T>::PopBack() {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto* current = head;
    ListElement<T>* prev = nullptr;

    // Pop Back
    while (current->GetNext()) {
        prev = current;
        current = current->GetNext();
    }

    T value = current->GetData();

    if(prev = nullptr) {
        head = nullptr;
    } else {
        prev->SetNext(nullptr);
    }

    delete current;

    return value;
}

template <class T>
bool LinkedList<T>::Empty() const {
   return head == nullptr;
}

template <class T>
const T& LinkedList<T>::ValueAt(int index) const {
    auto * current = head;

    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->GetNext();
    }

    if(current == nullptr) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    return current->GetData();
}

template <class T>
void LinkedList<T>::Insert(int index, T value) {
    auto * current = head;
    ListElement<T> * prev = nullptr;

    for (int i = 0; i < index && current != nullptr; ++i) {
        prev = current;
        current = current->GetNext();
    }

    if(current == nullptr) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto * node = ListElement<T>(value);

    if(current== nullptr) {
        node->SetNext(head);
        head = node;
    } else{
        node->SetNext(prev->GetNext());
        prev->SetNext(node);
    }
}



} /* common */ 

#include "./linked_list.h"

namespace common
{

// explicit instantiation
template class LinkedList<int>;
template class LinkedList<std::string>;

// explicit instantiation
template int LinkedList<int>::Size();
template int LinkedList<std::string>::Size();

template <class T>
int LinkedList<T>::Size() {

    int size = 0;

    auto* current = head;
    while (current) {
        current = current->GetNext();
        size ++;
    }

    return size;
}


// explicit instantiation
template const int LinkedList<int>::Front();

template <class T>
const T LinkedList<T>::Front() {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    return head->GetData();
}

// explicit instantiation
template const int LinkedList<int>::Back();

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

// explicit instantiation
template void LinkedList<int>::PushFront(int value);
template void LinkedList<std::string>::PushFront(std::string value);

template <class T>
void LinkedList<T>::PushFront(T value) {
    auto* node = new ListElement<T>(value); 

    node->SetNext(head);

    head = node;
}

// explicit instantiation
template const int LinkedList<int>::PopFront();

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

// explicit instantiation
template void LinkedList<int>::PushBack(int value);

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

// explicit instantiation
template const int LinkedList<int>::PopBack();

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

    if(prev == nullptr) {
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


// explicit instantiatoin
template const int& LinkedList<int>::ValueAt(int index) const;

template <class T>
const T& LinkedList<T>::ValueAt(int index) const {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

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

// explicit instantiatoin
template void LinkedList<int>::Insert(int index, int value);

template <class T>
void LinkedList<T>::Insert(int index, T value) {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto * current = head; // asterisk (*), the dereference operator: dereference the pointer prev to access the LinkedList object it refers to
    ListElement<T> * prev = nullptr;

    int i;
    for (i = 0; i < index && current != nullptr; ++i) {
        prev = current;
        current = current->GetNext();
    }

    if(i != index) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto * node = new ListElement<T>(value);

    if(prev == nullptr) {
        node->SetNext(head);
        head = node;
    } else {
        node->SetNext(prev->GetNext());
        prev->SetNext(node);
    }
}

// explicit instantiatoin
template void LinkedList<int>::Erase(int index);

template <class T>
void LinkedList<T>::Erase(int index) {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    ListElement<T>* prev = nullptr;
    auto * current = head;

    for (int i = 0; i < index && current != nullptr; ++i) {
        prev = current;
        current = current->GetNext();
    }

    if(current == nullptr) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }


    if (prev == nullptr) {
        head = current->GetNext();
    } else {
        prev->SetNext(current->GetNext());
        head = prev;
    }

    delete current;
}

template void LinkedList<int>::RemoveValue(int value);

template <class T>
void LinkedList<T>::RemoveValue(T value) {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    ListElement<T>* prev = nullptr;
    auto * current = head;

    while (current) {
        if (current->GetData() == value) {
            if(prev == nullptr) {
                head = current->GetNext();
            } else {
                prev->SetNext(current->GetNext());
                head = prev;
            }
            delete current;
            break;
        }

        prev = current;
        current = current->GetNext();
    }
}

// explicit instantiatoin
template void LinkedList<int>::Reverse();

template <class T>
void LinkedList<T>::Reverse() {
    if(head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }
    ListElement<T>* prev = nullptr;
    auto * current = head;
    ListElement<T>* next = nullptr;

    while (current != nullptr) {
        next = current->GetNext();
        current->SetNext(prev);
        prev = current;
        current = next;
    }

    head = prev;
}

// explicit instantiation
template const int LinkedList<int>::ValueNFromEnd(int n);

template <class T>
const T LinkedList<T>::ValueNFromEnd(int n) {
    if( n < 1 || head == nullptr) {
        std::cout << "List is empty" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto * current = head;
    auto * match = head;

    int i;
    for (i = 0; i < n && current != nullptr ; ++i) {
        current = current->GetNext();
    }

    if(i != n) {
        std::cout << "Index out of bounds" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (current) {
        match = match->GetNext();
        current = current->GetNext();
    }

    return match->GetData();
}

// explicit instantiation
template void LinkedList<int>::PrintDebug() const;

template <class T>
void LinkedList<T>::PrintDebug() const {
    auto * current = head;

    std::cout << " " << std::endl;
    while (current) {
        std::cout << current->GetData() << " ---> " ;
        current = current->GetNext();
    }
    std::cout << " " << std::endl;
}

} /* common */ 

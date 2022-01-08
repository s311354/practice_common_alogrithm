#include "./queue_linked_list.h"

namespace common {

// explicit instantiation
template class QueueLinkedList<int>;

template <class T>
QueueLinkedList<T>::~QueueLinkedList()
{
    ListElement<T>* current = head;
    ListElement<T>* temp = nullptr;

    while (current) {
        temp = current;
        current = current->GetNext();
        delete temp;
    }
};

// explicit instantiation
template void QueueLinkedList<int>::Enqueue(int value);

template <class T>
void QueueLinkedList<T>::Enqueue(T value)
{
    auto * p = new ListElement<T>(value);
    p->SetData(value);
    p->SetNext(nullptr);

    if(Empty()) {
        head = tail = p;
    } else {
        head->SetNext(p);
        tail = p;
    }
}

template const int QueueLinkedList<int>::Dequeue();

template <class T>
const T QueueLinkedList<T>::Dequeue()
{
    if(Empty()) {
        std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
        exit(EXIT_FAILURE);
    }

    T value = head->GetData();

    ListElement<T>* temp = head;

    if (head == tail)
        tail = head->GetNext();

    head = head->GetNext();
    delete temp;

    return value;
}

// explicit instantiation
template bool QueueLinkedList<int>::Empty() const;

template <class T>
bool QueueLinkedList<T>::Empty() const
{
    return head == nullptr;
}

template <class T>
void QueueLinkedList<T>::PrintDebug() const
{
    ListElement<T>* current = head;

    std::cout << "Queue elements: " << std::endl;

    while (current) {
        std::cout << current->GetData() << " < ";
        current = current->GetNext();
    }

    std::cout << "" << std::endl;
}


} /* namespace common */

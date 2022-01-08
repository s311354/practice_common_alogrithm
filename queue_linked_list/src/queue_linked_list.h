#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H
#include <iostream>
#include "./list_element.h"

namespace common {


template <class T>
class QueueLinkedList
{
private:
    ListElement<T>* head;
    ListElement<T>* tail;

public:
    QueueLinkedList() : head(nullptr), tail(nullptr) {} ;
    QueueLinkedList(const QueueLinkedList &) = delete;
    QueueLinkedList &operator=(const QueueLinkedList &) = delete;
    virtual ~QueueLinkedList();

    // Add value to queue
    void Enqueue(T value);
    // Remove least recently added item from queue, returning its value
    const T Dequeue();
    // Return ture if queue is empty
    bool Empty() const;
    // Outputs the items in the queue, least recently added first
    void PrintDebug() const;
};

} /* namespace common */
#endif /* QUEUE_LINKED_LIST_H */

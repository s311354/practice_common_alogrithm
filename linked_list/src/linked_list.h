#include <iostream>
#include <stdlib.h>
#include "./list_element.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace common {

template <class T>
class LinkedList
{
private:
    ListElement<T> *head;

public:
    //
    explicit LinkedList(): head(nullptr) {};

    LinkedList(const LinkedList &) {};
    // user-defined conversion function: conversion function is declared like a non-static member function or member function template with no parameters,
    // no explicit return type
    LinkedList &operator=(const LinkedList&);

    ~LinkedList() {
        ListElement<T>* current = head;
        ListElement<T>* next = nullptr;

        while (current) {
            next = current->GetNext();
            delete current;
            current = next;
        }
    };


    // Return the number of data element in list
    int Size();
    // Return value of front item
    const T Front();
    // Return value of end item
    const T Back();
    // Adds an item to the front of the list
    void PushFront(T value);
    // Removes front item, returning its value
    const T PopFront();
    // Push item end item and returns its value
    void PushBack(T value);
    // Removes end item, returning its value
    const T PopBack();
    // Return true if list is empty
    bool Empty() const;
    // Return the value of the nth item, indexed starting at 0
    const T &ValueAt(int index) const;
    // Insert value at index, so current item at that index is pointed to
    // by new item at index. Indexs start at 0
    void Insert(int index, T value);
    // Erase node at given index, Indexes start at 0
    void Erase(int index);
    // Removes the first item in the list with the given value
    void RemoveValue(T value);
    // Reverse the items stored in the list
    void Reverse();
    // Return the value of the node at nth position from the end of the list (Last position would be 1, second to last is 2, etx.)
    const T ValueNFromEnd(int n);

    // Prints the data stored in the list
    void PrintDebug() const;
};

} /* namespace common */
#endif /* LINKED_LIST_H */

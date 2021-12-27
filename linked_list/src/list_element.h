#include <iostream>
#include <stdlib.h>

#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

namespace common {

template <class T>
class ListElement
{
private:
    ListElement<T>* next;
    T data;

public:
    ListElement(const T &value): next(nullptr), data(value) {};
    ListElement(const ListElement &) {};
    ListElement &operator=(const ListElement &);
    virtual ~ListElement() {};

    const T&GetData() const { return data; };
    ListElement<T> *GetNext() const { return next; };

    void SetData(const T & datain) { data = datain; };
    void SetNext(ListElement<T>* elem) { next = elem; };
};

} /* namespace common */
#endif /* LIST_ELEMENT_H */

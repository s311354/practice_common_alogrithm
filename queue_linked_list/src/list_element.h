#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H
#include <iostream>

namespace common {

template <class T>
class ListElement
{
private:
    ListElement<T> *next;
    T data;

public:
    ListElement(const T &value) : next(nullptr), data(value) {};
    ListElement(const ListElement &) = delete;
    ListElement &operator=(const ListElement &) = delete;
    virtual ~ListElement() {};

    const T &GetData() const { return data; };
    ListElement<T> * GetNext() const {return next;};
    void SetData(const T &inputdata) { data = inputdata; };
    void SetNext(ListElement<T>* elem) { next = elem; };

};

} /* namespace common */
#endif /* LIST_ELEMENT_H */

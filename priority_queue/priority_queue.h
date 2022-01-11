#include <iostream>

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

namespace common {

typedef struct PriorityQueueElement {
    int key;
    std::string value;
} PQElement;

class PriorityQueue
{
private:
    int size = 0;
    int capacity_queue = 0;
    PQElement * pelement;

    // Propagates elements up the tree until the parent node's heap property is satisfied
    void SiftUp(int index);
    // Swap 2 queue elements with given indices
    void Swap(const int index1, const int index2);
    // Propagates the given node index down the tree until the subtree's heap property is satisfied
    void SiftDown(int index);

public:
    explicit PriorityQueue(const int size);
    PriorityQueue(const PriorityQueue &)=  delete;
    PriorityQueue&operator=(const PriorityQueue &) = delete;
    virtual ~PriorityQueue();

    // Adds the given key and value to the queue
    void Insert(const int key, const std::string value);
    // Remove the node with the given index
    void Remove(int index);
    // Returns the number of items stored in the queue
    int GetSize();
    // Return ture if queue is empty
    bool IsEmpty();
    // Returns the maximum key and value associated with it
    PQElement *GetMax();
    // Returns the maximum key and value associated with it, removing it from the queue
    PQElement *ExtractMax();
    // Output the contents of the queue
    void PrintDebug();

};

void heapify(int *numbers, int count);
void precolate_down(int *numbers, int count,int index);
void heap_sort(int *numbers, int count);
void print_heap(int *numbersi, int count);



} /* namespace common */

#endif /* PRIORITY_QUEUE_H */

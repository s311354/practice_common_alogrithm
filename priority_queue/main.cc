#include <iostream>
#include "./priority_queue.h"

int main(int argc, char *argv[])
{
    common::PriorityQueue priorityqueue(10);

    assert (priorityqueue.IsEmpty());
    assert (priorityqueue.GetSize() == 0);


    priorityqueue.Insert(10,"Hello");

    priorityqueue.Insert(300,"c++");

    priorityqueue.Insert(444,"Taiwan");

    common::PQElement* maxqueue = priorityqueue.ExtractMax();

    std::cout << "First priority: " << maxqueue->key << " : value: " << maxqueue->value << std::endl;

    std::cout <<  "======================" << std::endl;
    priorityqueue.PrintDebug();

    std::cout <<  "======================" << std::endl;


    int to_sort[10] = {613, 55, 8721, 472, 94, 72, 74, 8, 61, 356};


    common::heapify(to_sort, 10);


    common::print_heap(to_sort, 10);


    return 0;
}

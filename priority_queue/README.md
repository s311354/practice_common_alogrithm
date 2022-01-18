## Overview of Priority Queues ##

#### The concept of priority queue ####
In real life, we often encounter scenarios that involve queuing, such as standing in line at a gorcery store or at the movies. In these "first come, first served" situations, the first person to arrive is the first person served.

However, there are other scenarios where the first person to arrive is not hte first person served: when considering patients in an emergenct room, or when boarding an airplane... , etc. Here, the scenario is more of a "first come, most-important served" situation. Thus, we want to design a datatype that is tailored to support the following three operations as efficiently as possible:

<ul>
 <li>Add an item, with a given priority, into the data structure: key</li>
 <li>Remove the most important item from the data structure</li>
 <li>Giv the number of otems in the data structure</li>
</ul>

#### The concept of heap data structure ####

The heap is a specialized tree-based data structure which  is essentially an almost complete tree that satisfies the heap property. And it is also one maximally efficient implementation of an abstract data type called a priority queue, and in fact, priority queues are often referred to ad "heaps".

#### The concept of heapify procedure ####

The heapify procedure can be thought of as building a heap from the bottom up by successively sifting downward to establish the heap property. An alternative version that builds the heap top-down and sifts upward may be simpler to understand. In this implementation, it adopts first method which's time complexity is O(n) that is less than the second method.

#### Reference ####
[1] [cplusplus: priority queue](https://www.cplusplus.com/forum/general/146188/)

[2] [stack overflow: siftUp and siftDown operation in heap for heapifying an array](https://stackoverflow.com/questions/34329942/siftup-and-siftdown-operation-in-heap-for-heapifying-an-array)

[3] [Wiki: Heapsort](https://en.wikipedia.org/wiki/Heapsort)

[4] [Northeastern.edu: Lecture 29: Priority Queues and Heapsort](https://course.ccs.neu.edu/cs2510h/lecture29.html#%28part._.Heapsort%29)

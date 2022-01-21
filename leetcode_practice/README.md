## Overview of Common Alogrithm ##

#### The basic concept of bewteen c++98 and c++11 ####

C++11 is the second major version of C++ and the most important update since C++98. A large number of changes were introduced to both standardize existing practices and imporve the abstractions available to the C++ programmers. Since 2011, currently, C++ updates every 3 years regularly.

#### The concept of Assertions ####

The form of assert that checks a Bollean condition can be invaluable. Assertions are also useful checks on an algorithm's operation. Assertions check for things that should never happen. But. don't use assertions in place of real error handling because most assert implementations will terminate the process when an assertion fails, there's no reason why versions you write should. If you need to free resources, catch the assertions's exception or trap the exit, and run your own error handler

During testing,your first line of defense is checking for any possible error, and your second is using assertions to try to detect those you've missed. Once the code has beem tested and shipped, assertions are no longer needed, and should be truned off to make the code run faster.

#### The concept of queue and stack ####

The std::queue class is a container adaptor that gives the programmer tha functionality of a queue- specifically, a FIFO data structure. The queue pushes the elements on the back of the underlying container and pops them from the front. (key member functions: std::queue.front(), std::queue.back(), std::queue.push(), std::queue.pop(), ...)

The std::stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO data structure. The stack pushes and pops the element from the back of the underlying container, known as the top of the stack. (key member functions: std::stack.top(), std::stack().push, std::stack.pop(), ...)

#### The concept of vector ####

The std::vector<T>'s elements are stroed contiguously, which means that elements can be accessed not only through iterators, but also using offsets to regular points to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an element of an arry. (key member functions: std::vector<T>.assign(...), std::vector<T>.front(), std::vector<T>.back(), std::vector<T>.push_back(), std::vector<T>.pop_back(), std::vector<T>.at(pos), ...)

#### The concept of Library Containers (STL) ####

A container is a holder object that stores a collectionn of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.

Many containers have several member functions in common, and shared functionalities. The decision of which type of container to use to use for a specific need does not generally depend only on the functionality offered by the container, but also on the efficiency of some of its members.

Overview of container:
<table>
 <tr>
  <th>Type</th>
  <th>Containers</th>
 </tr>
 <tr>
  <td>Sequence Containers</td>
  <td>std::array, std::vector, std::deque, std::forward_list, std::list</td>
 </tr>
 <tr>
  <td>Container Adaptors</td>
  <td>std::stack, std::queue, std::priority_queue</td>
 </tr>
 <tr>
  <td>Associative Containers</td>
  <td>std::set, std::multiset, std::map, std::multiap</td>
 </tr>
 <tr>
  <td>Unorderred Associative Container</td>
  <td>std::unordered_set, std::unordered_mulitset, std::undered_map, std::unordered_mulitmap</td>
 </tr>
</table>



#### Reference ####

[1] [cplusplus: Q/A -std=c++11 or -std=c++98](https://www.cplusplus.com/forum/unices/172313/)

[2] [History of C++](https://en.cppreference.com/w/cpp/language/history)

[3] [cplusplus: C++11](https://en.cppreference.com/w/cpp/11)

[4] [Working Draft, Standard for Programming Language C++](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf)

[5] [Library Containers](https://www.cplusplus.com/reference/stl/)

[6] cppreference: [std::queue](https://en.cppreference.com/w/cpp/container/queue), [std::stack](https://en.cppreference.com/w/cpp/container/stack), [std::vector](https://en.cppreference.com/w/cpp/container/vector), [std::map](http://en.cppreference.com/w/cpp/container/map)

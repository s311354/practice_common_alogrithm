## Overview of Common Alogrithm ##

#### The basic concept of bewteen c++98 and c++11 ####

C++11 is the second major version of C++ and the most important update since C++98. A large number of changes were introduced to both standardize existing practices and imporve the abstractions available to the C++ programmers. Since 2011, currently, C++ updates every 3 years regularly.

#### The concept of Assertions ####

The form of assert that checks a Bollean condition can be invaluable. Assertions are also useful checks on an algorithm's operation. Assertions check for things that should never happen. But. don't use assertions in place of real error handling because most assert implementations will terminate the process when an assertion fails, there's no reason why versions you write should. If you need to free resources, catch the assertions's exception or trap the exit, and run your own error handler

During testing,your first line of defense is checking for any possible error, and your second is using assertions to try to detect those you've missed. Once the code has beem tested and shipped, assertions are no longer needed, and should be truned off to make the code run faster.


=========== To be continued…. ==========

#### Reference ####

[1] [cplusplus: Q/A -std=c++11 or -std=c++98](https://www.cplusplus.com/forum/unices/172313/)

[2] [History of C++](https://en.cppreference.com/w/cpp/language/history)

[3] [cplusplus: C++11](https://en.cppreference.com/w/cpp/11)

[4] [Working Draft, Standard for Programming Language C++](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3337.pdf)

## Overview of Binary Search ##

#### The concept of binary search algorithm ####
Binary search is a search algorithm that finds the poistion of a target value whithin a sorted array or data structure. Binary search compares the target value to the middle element of that array or data structure.

Note: 
- Balanced v.s Unbalanced Binary
- Poreorder traversing v.s Inorder traversing v.s Postorder traversing
- the average time complexity for searching for a value in a binary search tree is O(log n)
- the average time cimplexity for inserting a value into a binary search tree is O(n)

The common use case for a tree:
- make it easy to search for information
- represent hierarchical data
- implementing indexing in databases


#### The concept of struct and class declarations ####
For C program, a struct is a type consisting of a sequence of members whose storage is allocated in an ordered sequence. (as opposed to union, which is a type consisting of a sequence of members whose storage overlaps) Within a struct object, addresses of its elements increase in order in which the members were defined. 

For C++ program, classes and structs are user-defined types, defined by class-specifier.

#### The concept of pointer and reference ####
A pointer is an object that stores the address, or location in memory, of some other object. That is, it is a reference to some other value. A pointer is a type of thing, the same way an integer or string is a type of thing. In addition, a pointer exist so that you can dereference it to set or get the addressed value.

<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">int x = 0;
int* px = &x;
*px = 42; // dereference px -> x</span></code></pre></div>

Reference is another value which eliminates nearly all the problems that come with pointers. It is still possible to mess up, but not easily.

<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">int x = -7;
int & y = x;
y = 12; // exact same thing as x = 12;</span></code></pre></div>

Note that if you can resolve the name inline then you can simply have both names for the same value in your symbol lookup table. (this is an excellent optimization!). Otherwise, you'll need to generate object code that actually used a pointer to do the dirty work.

#### Reference ####
[1] [cppreference: Struct declaration](https://en.cppreference.com/w/c/language/struct)

[2] [cppreference: Class declaration](https://en.cppreference.com/w/cpp/language/class)

[3] [cppreference: Union declaration](https://en.cppreference.com/w/c/language/union)

[4] [Wiki: Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)

[5] [cplusplus: Pass-by-value vs Pass-by-reference](https://www.cplusplus.com/faq/beginners/call-by/)

[6] [cplusplus: Pointer and References](https://www.cplusplus.com/faq/beginners/pointers-and-references/)

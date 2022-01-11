## Overview of Linked List ##

#### The concept of Templates ####

A template is a C++ entity that defines class (class template) or function (function template). When a class template specialization is referenced in context that requires a complete objecttype, or when a function template specialization is referenced in context that requires a function to exist, the template is instantiated, unless the template was already explicitly specialized or explicitly instantiated.

It is worth mentioning that we need to avoid linker error with template classes or functions when compiling and trying to linking .cpp files. One of solution for this is to leave the definition of the template function or class in the .cpp file. [Linker Error][linkererror] describes more details.

The simple example:
<div class="language-shell highlighter-rouge"><pre class="highlight"><code class="hljs ruby"><span class="nb">// linked_list.cc
...
template class LinkedList<int>;
template class LinkedList<std::string>;
...

// linked_list.h
template <class T> class LinkedList { ... };</span></code></pre></div>

#### The concept of Member access operators ####

<font size="3" face="Courier New">
<table>
 <tr>
  <th>Operator</th>
  <th>Operator name</th>
  <th>Example</th>
  <th>Description</th>
 </tr>
 <tr>
  <td>*</td>
  <td>pointer dereference</td>
  <td>*a</td>
  <td>deference the pointer a to access the object or function it refers to</td>
 </tr>
 <tr>
  <td>&</td>
  <td>address of</td>
  <td>&a</td>
  <td>create a pointer that refers to the object or function a</td>
 </tr>
</table>
</font>

#### Reference ####
[1] [Member access operators](https://en.cppreference.com/w/c/language/operator_member_access)

[2] [How can I avoid linker errors with my template functions?](https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl)

[3] [cppreference: Templates](https://en.cppreference.com/w/cpp/language/templates)

[Linker Error][linkererror]

[linkererror]:https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl "https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl"

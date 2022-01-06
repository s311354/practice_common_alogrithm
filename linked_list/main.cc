#include <iostream>
#include <forward_list>
#include <vector>
#include "src/linked_list.h"
#include "src/linked_list.cc"

void stdlib_forward_list_experiment();

int main(int argc, char *argv[])
{
   common::LinkedList<int> lists;

   lists.PushFront(4);
   lists.PushFront(9);

   std::cout << "Size of int list is: " << lists.Size() << std::endl;

   common::LinkedList<std::string> stringlists;

   stringlists.PushFront("string 1");
   stringlists.PushFront("another");
   stringlists.PushFront("and another");

   std::cout << "Size of string list is: " << stringlists.Size() << std::endl;

    stdlib_forward_list_experiment();

    return 0;
}

void stdlib_forward_list_experiment() {

    std::cout << " Standard Library's forward_list (single-linked list) " << std::endl;

    std::forward_list<int> lists {100, 200, 300};

    std::cout << "Items: " << std::endl;
    for (auto &item : lists) {
        std::cout << item << std::endl;
    }

    std::cout << "Get Items by using Iterator" << std::endl;
    for (auto it = lists.begin();  it != lists.end() ; ++ it) {
        std::cout << *it << std::endl;
    }

    auto it = lists.begin();
    it = lists.erase_after(it);

    std::cout << "Get Items by using Iterator After erase_after" << std::endl;
    for (auto it = lists.begin();  it != lists.end() ; ++ it) {
        std::cout << *it << std::endl;
    }
}

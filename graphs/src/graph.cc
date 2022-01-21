#include "./graph.h"
#include <iostream>

namespace common {


bool Convert::isValidChar(char achar)
{
    return ( (achar - 'a' > 0 and achar - 'z' < 0 ) or (achar - 'A' > 0 and achar - 'Z' < 0));
}


int Convert::str2num(std::string name)
{
    int id = 0, assiinum = 0;
    int power = 10;

    for (auto elem : name) {

        if (!isValidChar(elem)) continue;

        assiinum = elem - 'a';

        while (assiinum >= power) 
            power *= 10;

        if (!id) {
            id = assiinum;
        } else {
            id = assiinum + id*power;
        }
    }

    return id;
}

std::string Convert::num2str(int id)
{
    std::string name;

    while (id > 0) {
        char achar = id%100 + 'a';
        std::cout <<  achar << std::endl;
        name.insert(name.begin(), achar);
        id = id/100;
    }

    return name;
}



} /* namespace common */

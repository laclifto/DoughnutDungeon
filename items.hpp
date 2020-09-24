/*********************************************************************
 ** Program Filename: items.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: items struct definition
 *********************************************************************/

#ifndef items_hpp
#define items_hpp

#include <iostream>
#include <string>

struct Items
{
    std::string identity;
    int value;
    bool canBeEaten;
    bool deleted;
    Items();
    Items(std::string, bool, int);
};

#endif /* items_hpp */

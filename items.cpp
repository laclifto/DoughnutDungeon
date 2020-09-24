/*********************************************************************
 ** Program Filename: items.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: items struct implementation
 *********************************************************************/

#include "items.hpp"

/***********************************************************************
 *                          CONSTRUCTOR
 ************************************************************************/

Items::Items()
{
    identity = " ";
    value = 0;
    canBeEaten = false;
    deleted = false;
}

Items::Items(std::string i, bool e, int v)
{
    identity = i;
    canBeEaten = e;
    value = v;
    deleted = false;
}
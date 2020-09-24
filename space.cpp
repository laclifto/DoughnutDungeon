/*********************************************************************
 ** Program Filename: space.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: space class implementation, base class
 *********************************************************************/

#include "space.hpp"

/*********************************************************************
 **                         CONSTRUCTOR
 *********************************************************************/
Space::Space()
{
    identity = " ";
    next = NULL;
    back = NULL;
    left = NULL;
    right = NULL;
    userInt = 0;
    beenHereBefore = false;
}

/*********************************************************************
 **                         ACCESSOR
 *********************************************************************/
int Space::getUserInt()
{
    return userInt;
}

int Space::getMoveWay()
{
    return moveWay;
}

Space* Space::getNext()
{
    return next;
}

Space* Space::getBack()
{
    return back;
}

Space* Space::getRight()
{
    return right;
}

Space* Space::getLeft()
{
    return left;
}

std::string Space::getIdentity()
{
    return identity;
}

/*********************************************************************
 **                         MUTATOR
 *********************************************************************/
void Space::setUserInt(int s)
{
    userInt = s;
}

void Space::setMoveWay(int m)
{
    moveWay = m;
}
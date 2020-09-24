/*********************************************************************
 ** Program Filename: space.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: space class definition, base class
 *********************************************************************/

#ifndef space_hpp
#define space_hpp

#include <iostream>
#include <string>
#include "player.hpp"
#include "items.hpp"
#include "npc.hpp"


class Space
{
protected:
    Space* next;
    Space* back;
    Space* right;
    Space* left;
    std::string identity;
    friend class spaceList;
    int userInt;
    int moveWay;
    char userChar;
    bool beenHereBefore;
    
public:
    Space();
    int getUserInt();
    void setUserInt(int);
    int getMoveWay();
    void setMoveWay(int);
    std::string getIdentity();
    Space* getNext();
    Space* getBack();
    Space* getRight();
    Space* getLeft();
    virtual void displayMenu(Player&) = 0;
    virtual void play(Player&) = 0;
    virtual void displayWelcome(Player&) = 0;
};

#endif /* space_hpp */

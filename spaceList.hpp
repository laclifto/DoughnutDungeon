/*********************************************************************
 ** Program Filename: spaceList.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: space linked list class definition
 *********************************************************************/

#ifndef spaceList_hpp
#define spaceList_hpp

#include <iostream>
#include "space.hpp"
#include "startRoom.hpp"
#include "ratRoom.hpp"
#include "treasureRoom.hpp"
#include "ironMaiden.hpp"
#include "secretGarden.hpp"
#include "musicalMinotaur.hpp"
#include "player.hpp"
#include "dropRoom.hpp"
#include "waterfallRoom.hpp"
#include "dragonRoom.hpp"

class spaceList
{
private:
    Space* playerLocation;
    Space* head;
    Space* tail;
    
public:
    spaceList();
    ~spaceList();
    void moveRooms(Player&);
    //void move(Player&);
    
};

#endif /* spaceList_hpp */

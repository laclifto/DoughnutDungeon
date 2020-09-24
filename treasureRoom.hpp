/*********************************************************************
 ** Program Filename: treasureRoom.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: treasureRoom class definition
 *********************************************************************/

#ifndef treasureRoom_hpp
#define treasureRoom_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"

class treasureRoom : public Space
{
private:
    bool chestOpened;
    
public:
    treasureRoom();
    void displayMenu(Player&);
    void play(Player&);
    void treasureChest(Player&);
    void displayWelcome(Player&);
};

#endif /* treasureRoom_hpp */

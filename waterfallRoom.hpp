/*********************************************************************
 ** Program Filename: waterfallRoom.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: waterfallRoom class definition
 *********************************************************************/

#ifndef waterfallRoom_hpp
#define waterfallRoom_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"
#include "utils.hpp"

class waterfallRoom : public Space
{
private:
    
public:
    waterfallRoom();
    void displayMenu(Player&);
    void play(Player&);
    void displayWelcome(Player&);
};

#endif /* waterfallRoom_hpp */

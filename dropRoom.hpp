/*********************************************************************
 ** Program Filename: dropRoom.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: dropRoom class definition
 *********************************************************************/


#ifndef dropRoom_hpp
#define dropRoom_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"
#include "utils.hpp"

class dropRoom : public Space
{
private:
    
public:
    dropRoom();
    void displayMenu(Player&);
    void play(Player&);
    void displayWelcome(Player&);
};

#endif /* dropRoom_hpp */

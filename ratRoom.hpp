/*********************************************************************
 ** Program Filename: ratRoom.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: ratRoom class definition
 *********************************************************************/

#ifndef ratRoom_hpp
#define ratRoom_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"

class ratRoom : public Space
{
private:
    
public:
    ratRoom();
    void displayMenu(Player&);
    void play(Player&);
    void battle(Player&);
    void ratHole(Player&);
    void displayWelcome(Player&);
};

#endif /* ratRoom_hpp */

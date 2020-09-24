/*********************************************************************
 ** Program Filename: dragonRoom.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: dragonRoom class definition
 *********************************************************************/

#ifndef dragonRoom_hpp
#define dragonRoom_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"
#include "utils.hpp"
#include "dragon.hpp"

class dragonRoom : public Space
{
private:
    
    
public:
    dragonRoom();
    void displayMenu(Player&);
    void play(Player&);
    void battle(Player&);
    void displayWelcome(Player&);
};

#endif /* dragonRoom_hpp */

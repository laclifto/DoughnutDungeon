/*********************************************************************
 ** Program Filename: ironMaiden.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: ironMaiden class definition
 *********************************************************************/
#ifndef ironMaiden_hpp
#define ironMaiden_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"
#include "utils.hpp"

class ironMaiden : public Space
{
private:
    bool zombieSpawn;
    
public:
    ironMaiden();
    void displayMenu(Player&);
    void play(Player&);
    void maidenLuck(Player&);
    void battle(Player&);
    void displayWelcome(Player&);
    
};
#endif /* ironMaiden_hpp */

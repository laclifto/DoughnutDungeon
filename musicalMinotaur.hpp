/*********************************************************************
 ** Program Filename: musicalMinotaur.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: musicalMinotaur class definition
 *********************************************************************/

#ifndef musicalMinotaur_hpp
#define musicalMinotaur_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"
#include "utils.hpp"
#include "minotaur.hpp"

class musicalMinotaur : public Space
{
private:
    bool hasComeToLife;
    
public:
    musicalMinotaur();
    void displayMenu(Player&);
    void play(Player&);
    void battle(Player&);
    void displayWelcome(Player&);
};

#endif /* musicalMinotaur_hpp */

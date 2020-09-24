/*********************************************************************
 ** Program Filename: startRoom.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: startRoom class definition
 *********************************************************************/

#ifndef startRoom_hpp
#define startRoom_hpp

#include <iostream>
#include "space.hpp"
#include "utils.hpp"


class startRoom : public Space
{
private:
    
public:
    startRoom();
    void displayMenu(Player&);
    void displayWelcome(Player&);
    void play(Player&);
};

#endif /* startRoom_hpp */

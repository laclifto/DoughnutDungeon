/*********************************************************************
 ** Program Filename: dragon.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: dragon class definition
 *********************************************************************/
#ifndef dragon_hpp
#define dragon_hpp

#include <iostream>
#include "utils.hpp"
#include "npc.hpp"

class Dragon : public NPC
{
private:

public:
    Dragon();
    int attack();
};

#endif /* dragon_hpp */

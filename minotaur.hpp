/*********************************************************************
 ** Program Filename: minotaur.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: minotaur class definition
 *********************************************************************/
#ifndef minotaur_hpp
#define minotaur_hpp

#include <iostream>
#include "utils.hpp"
#include "npc.hpp"

class Minotaur : public NPC
{
private:

public:
    Minotaur();
    int attack();
};

#endif /* minotaur_hpp */

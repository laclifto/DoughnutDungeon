/*********************************************************************
 ** Program Filename: npc.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: npc class definition - npc(non player character) base class
 *********************************************************************/

#ifndef npc_hpp
#define npc_hpp

#include <iostream>
#include "utils.hpp"

class NPC
{
protected:
    int damage;
    int totalDamage;
    int health;
    int atk;
    
public:
    NPC();
    NPC(int, int);
    virtual ~NPC() {};
    virtual int attack();
    bool isDead();
    void takeDamage(int);
    int getHealth();
};


#endif /* npc_hpp */

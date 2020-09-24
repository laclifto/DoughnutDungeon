/*********************************************************************
 ** Program Filename: npc.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: npc class implementation - npc(non player character) base class
 *********************************************************************/
#include "npc.hpp"

/***********************************************************************
 *                          CONSTRUCTORS
 ************************************************************************/
NPC::NPC(int h, int a)
{
    health = h;
    atk= a;
}

NPC::NPC()                              //default constructor
{
    health = 0;
    atk = 0;
}

/***********************************************************************
 *                          ACCESSOR
 ************************************************************************/
int NPC::getHealth()
{
    return health;
}


/*********************************************************************
 ** Function: isDead
 ** Description: returns true if npc is dead, otherwise false
 ** Parameters: none
 *********************************************************************/
bool NPC::isDead()
{
    if (health <= 0)
        return true;
    else
        return false;
}

/*********************************************************************
 ** Function: attack
 ** Description: generates attack roll for player
 ** Parameters: none
 *********************************************************************/
int NPC::attack()
{
    return randomNum(atk) + 1;
}

/*********************************************************************
 ** Function: takeDamage
 ** Description: takes damage and applies to health
 ** Parameters: integer
 *********************************************************************/
void NPC::takeDamage(int d)
{
    health -= d;
}













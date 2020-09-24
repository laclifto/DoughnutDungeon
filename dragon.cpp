/*********************************************************************
 ** Program Filename: dragon.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: dragon class implementation
 *********************************************************************/

#include "dragon.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
Dragon::Dragon()
{
    health = 12;
    atk = 8;
}


/*********************************************************************
 ** Function: attack
 ** Description: orchestrates dragon attack, has 10% chance of increased
                        damage
 ** Parameters: none
 *********************************************************************/
int Dragon::attack()
{
    damage = 0;                        //reset damage accumulator
    
    damage = randomNum(atk);
    
    if (damage == 5)
    {
        std::cout << "Flametongue attack! Damage increased by 3!" << std::endl;
        damage +=3;
    }
    
    std::cout << "Dragon does  " << damage << " damage! " << std::endl;
    
    return damage;
}









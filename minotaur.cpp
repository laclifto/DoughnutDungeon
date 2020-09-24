/*********************************************************************
 ** Program Filename: minotaur.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: minotaur class implementation
 *********************************************************************/
#include "minotaur.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
Minotaur::Minotaur()
{
    health = 8;
    atk = 7;
}


/*********************************************************************
 ** Function: attack
 ** Description: orchestrates dragon attack, has 10% chance of increased
 damage
 ** Parameters: none
 *********************************************************************/
int Minotaur::attack()
{
    int damage = randomNum(atk);
    

    if (damage == 10)
    {
        std::cout << "Violin attack! Ah, the majestic sound of being smacked in the face";
        std::cout << " by a beautiful instrument... Damage increased by 2." << std::endl;
        damage +=2;
        return damage;
    }
    else
    {
        std::cout << "Minotaur deals " << damage << " damage!" << std::endl;
        return damage;
        
    }
}


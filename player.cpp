/*********************************************************************
 ** Program Filename: player.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: player struct implementation
 *********************************************************************/

#include "player.hpp"

/***********************************************************************
 *                          CONSTRUCTOR
 ************************************************************************/
Player::Player()                            //sets base stats for player
{
    hp = 20;
    atk = 6;
    armor = 1;
    hunger = 0;
    counter = 0;
}

/***********************************************************************
 *                          ACCESSOR
 ************************************************************************/
int Player::getHealth()
{
    return hp;
}

/***********************************************************************
 *                          MUTATOR
 ************************************************************************/
void Player::setHealth(int h)
{
    hp = h;
}
/*********************************************************************
 ** Function: attack
 ** Description: generates attack roll for player
 ** Parameters: none
 *********************************************************************/
int Player::attack()
{
    return randomNum(atk) + 1;
}

/*********************************************************************
 ** Function: playerStats
 ** Description: displays stats for player
 ** Parameters: none
 *********************************************************************/
void Player::playerStats()
{
    std::cout << "Current player stats: " << std::endl;
    std::cout << "Health points: " << hp << std::endl;
    std::cout << "Armor: " << armor << std::endl;
    std::cout << "Attack: up to " << atk << std::endl;
    std::cout << "Hunger: " << hunger << std::endl;
    std::cout << "When health points = zero or hunger = twelve, the game will end. ";
    std::cout << std::endl;
    std::cout << "Hunger increases by 1 each time you enter a new room.";
    std::cout << std::endl << std::endl;
}

/*********************************************************************
 ** Function: isDead
 ** Description: checks for player death
 ** Parameters: none
 *********************************************************************/
bool Player::isDead()
{
    if (hp <= 0)
        return true;
    else if (hunger >= 11)
    {
        std::cout << "You have died of hunger! " << std::endl;
        return true;
    }
    else
        return false;
}

/*********************************************************************
 ** Function: addToKnapsack
 ** Description: adds items to players knapsack
 ** Parameters: none
 *********************************************************************/
void Player::addToKnapsack(Items i)
{
    if(counter == 24)
    {
        std::cout << "Your knapsack is full! You must use some of your items before ";
        std::cout << "more can be added." << std::endl;
    }
    else
    {
        knapsack[counter] = i;
        counter++;
    }
}

/*********************************************************************
 ** Function: checkForFood
 ** Description: checks to see if any knapsack items are edible. if so,
 **                 allows option to eat, "deletes" item
 ** Parameters: none
 *********************************************************************/
void Player::checkForFood()
{
    char choice = 'y';
    bool flag = false;
    for (int i = 0; i < counter; i++)
    {
        while(!knapsack[i].deleted && knapsack[i].canBeEaten && choice == 'y')
        {

            flag = true;
            std::cout << "Item " << i+1 << ": " << knapsack[i].identity;
            std::cout << " can be eaten. Would you like to eat it now? Enter y/n";
            std::cout << std::endl;
            choice = validateYN();
            if (choice == 'y')
            {
                hunger -= knapsack[i].value;
                std::cout << "That item decreased hunger by " << knapsack[i].value ;
                std::cout << " points. " << std::endl;
                knapsack[i].deleted = true;
                
            }
            std::cout << "Would you like to continue searching for food? Enter y/n";
            std::cout << std::endl;
            choice = validateYN();
            if (choice == 'y')
                flag = false;
            
            std::cout << std::endl << std::endl;
        }
        

    }
    if (!flag)
    {
        std::cout << "Your bag does not contain any edible items." << std::endl;
    }
}

/*********************************************************************
 ** Function: viewKnapsack
 ** Description: displays items in players knapsack
 ** Parameters: none
 *********************************************************************/
void Player::viewKnapsack()
{
    if(counter == 0 || allItemsDeleted())
        std::cout << "Your knapsack is currently empty." << std::endl;
    else
    {
    
        for (int i = 0; i < counter; i++)
        {
            if(!knapsack[i].deleted)
            {
                std::cout << "Item " << i+1 << ": " << knapsack[i].identity;
                std::cout << std::endl << std::endl;
            }
        }
        std::cout << "Would you like to search your bag for edible items? Enter y/n";
        std::cout << std::endl;
        char choice = validateYN();
        if (choice == 'y')
        {
            checkForFood();
        }
    }
}

/*********************************************************************
 ** Function: checkForItem
 ** Description: returns true if knapsack has item matching description
 **                 passed
 ** Parameters: string
 *********************************************************************/
bool Player::checkforItem(std::string name)
{
    bool hasItem = false;
    
    for (int i = 0; i < counter; i++)
    {
        if (knapsack[i].identity == name)
            hasItem = true;
    }
    return hasItem;
 
}

/*********************************************************************
 ** Function: allItemsDeleted
 ** Description: returns true if all Items in knapsack have been deleted
 ** Parameters: none
 *********************************************************************/
bool Player::allItemsDeleted()
{
    bool flag = true;
    for (int i = 0; i < counter; i++)
    {
        if (knapsack[i].deleted == false)
            flag = false;
    }
    return flag;
}

/*********************************************************************
 ** Function: takeDamage
 ** Description: decrements players health by amount of damage passed
 ** Parameters: integer
 *********************************************************************/
void Player::takeDamage(int d)
{
    int damage = d - armor;
    
    if (damage > 0)
        hp -= (d - armor);
}

/*********************************************************************
 ** Function: takeHunger
 ** Description: increments players hunger by amount of integer passed
 ** Parameters: integer
 *********************************************************************/
void Player::takeHunger(int h)
{
    hunger += h;
}

/*********************************************************************
 ** Function: multiplyAttack
 ** Description: multiplies attack by number of times passed
 ** Parameters: integer
 *********************************************************************/
void Player::multiplyAttack(int a)
{
    atk *= a;
}

/*********************************************************************
 ** Function: incrementArmor
 ** Description: increments players armor by 1 each time called
 ** Parameters: none
 *********************************************************************/
void Player::incrementArmor()
{
    armor++;
}













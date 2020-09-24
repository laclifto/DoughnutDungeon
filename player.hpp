/*********************************************************************
 ** Program Filename: player.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: player struct definition
 *********************************************************************/
#ifndef player_hpp
#define player_hpp

#include <iostream>
#include "utils.hpp"
#include "items.hpp"

class Player
{
private:
    int hp;         //health points
    int atk;
    int armor;
    int hunger;     //begins at 6. is reduced by one on entering new room. game ends if
                    //reaches zero
    int counter;
    Items knapsack[25];
    bool beentoDropRoom;
 
public:
    Player();
    int attack();
    void takeDamage(int);
    void takeHunger(int);
    void playerStats();
    bool isDead();
    int getHealth();
    void setHealth(int);
    void multiplyAttack(int);
    void incrementArmor();
    void viewKnapsack();
    void addToKnapsack(Items);
    Items removeFromKnapsack(int);
    bool checkforItem(std::string);
    void checkForFood();
    bool allItemsDeleted();
};

#endif /* player_hpp */

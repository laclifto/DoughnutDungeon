/*********************************************************************
 ** Program Filename: ironMaiden.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: ironMaiden class implementation
 *********************************************************************/

#include "ironMaiden.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in room, displays initial explanation. proceeds to room display
 menu */

ironMaiden::ironMaiden()
{
    identity = "Iron Maiden Room";
    zombieSpawn = false;
}
/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu 
 ** Parameters: none
 *********************************************************************/
void ironMaiden::displayWelcome(Player& player)
{
    if (!beenHereBefore)
    {
        beenHereBefore = true;
        
        std::cout << std::endl;
        std::cout << "You enter a room with an iron maiden in each corner. " ;
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "You have returned to the room with the iron maidens. " ;
        std::cout << std::endl;

    }
    displayMenu(player);

}
/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void ironMaiden::displayMenu(Player &player)
{
    std::cout << std::endl;
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Return to treasure room - enter 1" << std::endl;
    std::cout << "I'm feeling lucky! Roll a random number";
    std::cout << " between 1 and 4 to choose which iron maiden";
    std::cout << " to inspect - enter 2" << std::endl;
    std::cout << "View items in knapsack - enter 3" << std::endl;
    std::cout << "View current player stats - enter 4" << std::endl;
    std::cout << "Quit - enter 0" << std::endl;
    
    userInt = validateInt();
    play(player);
}

/*********************************************************************
 ** Function: play
 ** Description: accepts user choice from menu and outputs current response
 ** Parameters: none
 *********************************************************************/
void ironMaiden::play(Player &player)
{
    
    while (userInt < 0 || userInt > 4)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 4." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        case 1: std::cout << "Returning to treasure room." << std::endl;
            moveWay = 4;
            break;
        case 2: maidenLuck(player);
            std::cout << std::endl << std::endl;
            break;
        case 3: player.viewKnapsack();
            displayMenu(player);
            break;
        case 4: player.playerStats();
            displayMenu(player);
            break;
        case 0: std::cout << "Quitter." << std::endl;
            moveWay = 0;
            break;
    }
    
}

/*********************************************************************
 ** Function: maidenLuck
 ** Description: rolls random iron maiden room event
 ** Parameters: none
 *********************************************************************/
void ironMaiden::maidenLuck(Player& player)
{
    int luck = randomNum(4);
    
    switch (luck)
    {
        case 0 : std::cout << "You're inexplicably pulled in. The spikes graze you ";
            std::cout << "as you dive back out at the last moment. You lose 1 HP." ;
            std::cout << std::endl << std::endl;
            player.takeDamage(1);
            displayMenu(player);
            break;
        case 1: std::cout << "AHHHHH! Oh. It's empty. Except for a little spider ";
            std::cout << "that you totally weren't afraid of." << std::endl;
            displayMenu(player);
            break;
        case 2:
            if (!zombieSpawn)
            {
                zombieSpawn = true;
                std::cout << "There's an undead in here! With holes! It's a....";
                std::cout << "SWISS CHEESE ZOMBIE!!" << std::endl;
                std::cout << "*******BATTLE BEGINS*******" << std::endl;
                battle(player);
            }
            else
            {
                std::cout << "Oh. It's the one that had the zombie in it. It's all ";
                std::cout << "gross now. Ew." << std::endl;
                displayMenu(player);
            }
            break;
        case 3: std::cout << "Apparently there's a secret passage in here...";
            moveWay = 1;
            std::cout << std::endl;
            break;
    }
}

/*********************************************************************
 ** Function: battle
 ** Description: modulates battle between player and zombie
 ** Parameters: none
 *********************************************************************/
void ironMaiden::battle(Player &player)
{
    int damage;
    NPC zombie(5, 6);
    
    std::cout << "Zombie attacks first! " << std::endl;
    
    while (!player.isDead() && !zombie.isDead())
    {
        damage = randomNum(6);
        std::cout << "Zombie deals " << damage << " damage!" << std::endl;
        player.takeDamage(damage);
        std::cout << "Player health points: " << player.getHealth() << std::endl;
        std::cout << "Player attacks! ";
        damage = player.attack();
        std::cout << "Player does " << damage << " damage!" << std::endl;
        zombie.takeDamage(damage);
        std::cout << "Zombie health points: " << zombie.getHealth() << std::endl << std::endl;
    }
    
    if (player.isDead())                    //if player is killed by rat
    {
        std::cout << "Game Over. You were killed by a swiss cheese zombie, dude. ";
        std::cout << std::endl;
        return;
    }
    else
    {
        std::cout << "Congratulations on your victory against the holey zombie. ";
        std::cout << std::endl;
        std::cout << "The zombie dropped a chest plate. This will increase your armor";
        std::cout << " by 1. Would you like to put it on? Enter y/n" << std::endl;
        userChar = validateYN();
        if(userChar == 'y')
            player.incrementArmor();
        
        displayMenu(player);
    }
}



















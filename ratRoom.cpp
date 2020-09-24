/*********************************************************************
 ** Program Filename: ratRoom.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: startRoom class implementation
 *********************************************************************/

#include "ratRoom.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/

ratRoom::ratRoom()
{
    identity = "Rat Room";
}

/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu or battle as appropriate
 ** Parameters: none
 *********************************************************************/
void ratRoom::displayWelcome(Player& player)
{
    if(!beenHereBefore)
    {
        beenHereBefore = true;
        std::cout << std::endl;
        std::cout << "Before you can adequately inspect the room, ";
        std::cout << " you are ambushed by a large mutant rat." << std::endl;
        std::cout << "***************BATTLE BEGINS****************" << std::endl;
        
        battle(player);
    }
    else
    {
        std::cout << "You have returned to the room in which you battled the rat.";
        std::cout << "The rat's corpse remains lying in the middle of the room.";
        std::cout << std::endl;
        displayMenu(player);
    }

}

/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void ratRoom::displayMenu(Player &player)
{
    std::cout << "Would you like to: : " << std::endl;
    std::cout << "Investigate hole in the wall - enter 1" << std::endl;
    std::cout << "Return to starting room - enter 2" << std::endl;
    std::cout << "Take left path - enter 3" << std::endl;
    std::cout << "Take right path - enter 4" << std::endl;
    std::cout << "Examine rat corpse - enter 5" << std::endl;
    std::cout << "View items in knapsack - enter 6" << std::endl;
    std::cout << "View current player stats - enter 7" << std::endl;
    std::cout << "Quit - enter 0 " << std::endl;
    
    userInt = validateInt();
    play(player);
    
}

/*********************************************************************
 ** Function: play
 ** Description: accepts user choice from menu and outputs current response
 ** Parameters: none
 *********************************************************************/
void ratRoom::play(Player &player)
{
    while (userInt < 0 || userInt > 7)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 7." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        case 1: ratHole(player);
            break;
        case 2: std::cout << "Returning to previous room." << std::endl;
            moveWay = 1;
            break;
        case 3: std::cout << "You walk down the path to the left. " << std::endl;
            std::cout << std::endl;
            moveWay = 5;
            break;
        case 4: std::cout << "You walk down the path to the right.";
            std::cout << std::endl;
            moveWay = 4;
            break;
        case 5: std::cout << "You feel remorse. You're not a psychopath." << std::endl;
                displayMenu(player);
            break;
        case 6: player.viewKnapsack();
            displayMenu(player);
            break;
        case 7: player.playerStats();
            displayMenu(player);
            break;
        case 0: std::cout << "Quitter." << std::endl;
            moveWay = 0;
            break;
    }
}

/*********************************************************************
 ** Function: ratHole
 ** Description: generates random effect from reaching into rat hole
 ** Parameters: none
 *********************************************************************/
void ratRoom::ratHole(Player& player)
{
    int random = randomNum(6) + 1;
    if(random == 1)
    {
        std::cout << "You are pulled through the rat hole by an unknown force ";
        std::cout << "into a new room. " << std::endl << std::endl;
        moveWay = 2;
    }
    else if (random == 2 || random == 3)
    {
        std::cout << "The rat's companion exacts revenge in the form of a bite!" << std::endl;
        std::cout << "You learn not to stick your hands into rat holes." << std::endl;
        std::cout << "HP decreased by 1." << std::endl << std::endl;
        player.takeDamage(1);
        displayMenu(player);
    }
    else
    {
        std::cout << "You have acquired the rat's lunch. " << std::endl;
        std::cout << "Guess he's not going to be needing it..." <<std::endl;
        std::cout << "Eat cheese now? Restores 2 hunger. Enter y/n"<<std::endl;
        userChar = validateYN();
        if(userChar == 'y')
            player.takeHunger(-2);
        else
        {
            std::cout << "Stow the cheese in your knapsack? Enter y/n";
            std::cout << std::endl << std::endl;
            userChar = validateYN();
            if (userChar == 'y')
            {
                Items cheese("cheese", true, 2);
                player.addToKnapsack(cheese);
            }
        }
        displayMenu(player);
    }
}

/*********************************************************************
 ** Function: battle
 ** Description: modulates battle between player and rat
 ** Parameters: none
 *********************************************************************/
void ratRoom::battle(Player &player)
{
    int damage;
    NPC rat(5, 6);
        
    std::cout << "Rat attacks first! " << std::endl;

    while (!player.isDead() && !rat.isDead() > 0)
    {
        damage = rat.attack();
        std::cout << "Rat deals " << damage << " damage!" << std::endl;
        player.takeDamage(damage);
        std::cout << "Player health points: " << player.getHealth() << std::endl;
        std::cout << "Player attacks! ";
        damage = player.attack();
        std::cout << "Player does " << damage << " damage!" << std::endl;
        rat.takeDamage(damage);
        std::cout << "Rat health points: " << rat.getHealth() << std::endl << std::endl;
    }
    
    if (player.isDead())                    //if player is killed by rat
    {
        std::cout << "Game Over. You were killed by a rat, dude. " << std::endl;
        return;
    }
    else
    {
        std::cout << "The mutant rat's corpse lies in the middle of the room. " << std::endl;
        std::cout << "Now that you have a moment to rest, you investigate the room. ";
        std::cout << "There appears to be a hole in the wall. While you aren't small enough ";
        std::cout << "to fit in the hole, your arm might fit. " << std::endl;
        std::cout << "Also, there appear to be two exits." << std::endl << std::endl;
        displayMenu(player);
    }
    
}
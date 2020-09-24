/*********************************************************************
 ** Program Filename: treasureRoom.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: treasureRoom class implementation
 *********************************************************************/

#include "treasureRoom.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in room, displays initial explanation. proceeds to room display
 menu */

treasureRoom::treasureRoom()
{
    chestOpened = false;
    identity = "Treasure Room";
}

/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu 
 ** Parameters: none
 *********************************************************************/
void treasureRoom::displayWelcome(Player& player)
{
    if(!beenHereBefore)
    {
        beenHereBefore = true;
        std::cout << std::endl;
        std::cout << "The room contains a chest. There's a mid-sized hole in the wall " ;
        std::cout << "on your left. Ahead of you is a door that is ajar." << std::endl;
        std::cout << std::endl;

    }
    else
    {
        std::cout << "You have returned to the room with the treasure chest.";
        std::cout << std::endl;
    }
    
    displayMenu(player);
}


/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void treasureRoom::displayMenu(Player &player)
{
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Open the chest - enter 1" << std::endl;
    std::cout << "Inspect hole in the wall - enter 2" << std::endl;
    std::cout << "Return to starting room - enter 3" << std::endl;
    std::cout << "Open door and proceed down hallway - enter 4" << std::endl;
    std::cout << "View items in knapsack - enter 5" << std::endl;
    std::cout << "View current player stats - enter 6" << std::endl;
    std::cout << "Quit - enter 0" << std::endl;
    
    userInt = validateInt();
    play(player);
}

/*********************************************************************
 ** Function: play
 ** Description: accepts user choice from menu and outputs current response
 ** Parameters: none
 *********************************************************************/
void treasureRoom::play(Player &player)
{
    
    while (userInt < 0 || userInt > 6)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 6." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        /* if chest has not been opened, display. if has been, prompt user for new choice*/
        case 1: treasureChest(player);
                displayMenu(player);
            break;
        case 2: std::cout << "It smells like rats. Hmmm.... ";
            std::cout << std::endl << std::endl;
            displayMenu(player);
            break;
        case 3: std::cout << "Returning to starting room. " << std::endl;
            std::cout << std::endl;
            moveWay = 4;
            break;
        case 4: std::cout << "Proceeding through the doorway." << std::endl;
            moveWay = 1;
            break;
        case 5: player.viewKnapsack();
                displayMenu(player);
            break;
        case 6: player.playerStats();
                displayMenu(player);
            break;
        case 0: std::cout << "Quitter." << std::endl;
            moveWay = 0;
            break;
    }
    
}
/*********************************************************************
 ** Function: treasureChest
 ** Description: awards sword if chest has not been previously opened.
 **                 otherwise, reminds user chest has already been opened
 ** Parameters: none
 *********************************************************************/
void treasureRoom::treasureChest(Player& player)
{
    if (!chestOpened)
    {
        std::cout << "Congratulations. You receive a sword!" << std::endl;
        std::cout<< "Your attack points are doubled." << std::endl << std::endl;
        player.multiplyAttack(2); 
        chestOpened = true;
    }
    else
    {
        std::cout << "You've already opened that chest. ";
        std::cout << "There's nothing left in it. " << std::endl << std::endl;
    }

}


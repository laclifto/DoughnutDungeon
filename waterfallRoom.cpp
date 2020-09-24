/*********************************************************************
 ** Program Filename: waterfallRoom.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: waterfallRoom class implementation
 *********************************************************************/

#include "waterfallRoom.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in room, displays initial explanation. proceeds to room display
 menu */

waterfallRoom::waterfallRoom()
{
    identity = "Waterfall Room";
    
}

/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu
 ** Parameters: none
 *********************************************************************/
void waterfallRoom::displayWelcome(Player& player)
{
    if (!beenHereBefore)
    {
        std::cout << std::endl;
        std::cout << "You enter a rather large room with no visible ceiling. " ;
        std::cout << "A waterfall cascades from high above, leaving a rushing river that ";
        std::cout << " winds diagonally through the room. ";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "You again find yourself in the room with the waterfall.";
        std::cout << std::endl;
    }
    displayMenu(player);
}


/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void waterfallRoom::displayMenu(Player &player)
{
    std::cout << std::endl;
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Investigate waterfall - enter 1" << std::endl;
    std::cout << "Jump into river (perhaps it leads out?)";
    std::cout << " - enter 2" << std::endl;
    std::cout << "Return to rat room - enter 3" << std::endl;
    std::cout << "View items in knapsack - enter 4" << std::endl;
    std::cout << "View current player stats - enter 5" << std::endl;
    std::cout << "Quit - enter 0" << std::endl;
    
    userInt = validateInt();
    play(player);
}

/*********************************************************************
 ** Function: play
 ** Description: accepts user choice from menu and outputs current response
 ** Parameters: none
 *********************************************************************/
void waterfallRoom::play(Player &player)
{
    
    while (userInt < 0 || userInt > 5)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 5." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        case 1: std::cout << "The water replenishes your health. You feel restored. ";
            std::cout << std::endl;
            player.setHealth(20);
            displayMenu(player);
            break;
        case 2: std::cout << "Well, that wasn't very smart. You drown.";
            std::cout << std::endl;
            player.takeDamage(999);
            break;
        case 3: std::cout << "Returning to rat room." << std::endl;
            moveWay = 4;
            break;
        case 4: player.viewKnapsack();
            displayMenu(player);
            break;
        case 5: player.playerStats();
            displayMenu(player);
            break;
        case 0: std::cout << "Quitter." << std::endl;
            moveWay = 0;
            break;
    }
    
}

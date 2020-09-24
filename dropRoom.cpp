/*********************************************************************
 ** Program Filename: dropRoom.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: dropRoom class implementation
 *********************************************************************/
#include "dropRoom.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in room, displays initial explanation. proceeds to room display
 menu */

dropRoom::dropRoom()
{
    identity = "Drop Room";
    
}
/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu
 ** Parameters: none
 *********************************************************************/
void dropRoom::displayWelcome(Player& player)
{
    std::cout << std::endl;
    std::cout << "A new room has appeared around you!" ;
    std::cout << "The room is empty. The floor seems a little unstable but seems";
    std::cout << " to be holding your weight. You feel a strong urge to play the violin. ";
    std::cout << std::endl;
    std::cout << std::endl;
    
    displayMenu(player);

}

/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void dropRoom::displayMenu(Player &player)
{
    std::cout << std::endl;
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Play the violin - enter 1" << std::endl;
    std::cout << "Return to room with minotaur statue";
    std::cout << " - enter 2" << std::endl;
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
void dropRoom::play(Player &player)
{
    
    while (userInt < 0 || userInt > 4)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 4." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        case 1:
            if (player.checkforItem("violin"))
            {
                std::cout << "Employing your well-honed musical skills, you begin to ";
                std::cout << "play. You discover yourself playing an odd tune with which you ";
                std::cout << "are unfamiliar. Suddenly, the room begins to rumble and the ";
                std::cout << "floor collapses below you." << std::endl << std::endl;
                moveWay = 7;
            }
            else
            {
                std::cout << "You do not yet have a violin, so you cannot play.";
                std::cout << "Find a violin in the dungeon and return to this room.";
                std::cout << std::endl;
                displayMenu(player);
            }
            break;
        case 2: std::cout << "Returning to minotaur room. Hope it hasn't come back";
            std::cout << " to life...";
            std::cout << std::endl;
            moveWay = 4;
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

/*********************************************************************
 ** Program Filename: secretGarden.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: secretGarden class implementation
 *********************************************************************/

#include "secretGarden.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in room, displays initial explanation. proceeds to room display
 menu */

secretGarden::secretGarden()
{
    identity = "Secret Garden Room";
    
}

/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu
 ** Parameters: none
 *********************************************************************/
void secretGarden::displayWelcome(Player& player)
{
    if(!beenHereBefore)
    {
        beenHereBefore = true;
        std::cout << std::endl;
        std::cout << "You enter a room covered in flora.";
        std::cout << "Vines dangle from two caged windows.";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "You have returned to the room with the greenery. ";
        std::cout << std::endl;
    }
    displayMenu(player);
}


/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void secretGarden::displayMenu(Player &player)
{
    std::cout << std::endl;
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Inspect blue flower - enter 1" << std::endl;
    std::cout << "Inspect the thing that looks like lettuce";
    std::cout << " - enter 2" << std::endl;
    std::cout << "Inspect left vine - enter 3" << std::endl;
    std::cout << "Climb right vine - enter 4" << std::endl;
    std::cout << "Return to room with iron maidens - enter 5" << std::endl;
    std::cout << "View items in knapsack - enter 6" << std::endl;
    std::cout << "View current player stats - enter 7" << std::endl;
    std::cout << "Quit - enter 0" << std::endl;
    
    userInt = validateInt();
    play(player);
}

/*********************************************************************
 ** Function: play
 ** Description: accepts user choice from menu and outputs current response
 ** Parameters: none
 *********************************************************************/
void secretGarden::play(Player &player)
{
    
    while (userInt < 0 || userInt > 7)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 7." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        case 1: blueFlower(player);
                displayMenu(player);
            break;
        case 2: lettuceThing(player);
                displayMenu(player);
            break;
        case 3: std::cout << "Pulling on the vine, you hear a faint \"Oompfh!\"";
            std::cout << " exclaimed. For some reason, this opens a secret doorway.";
            std::cout << " Just go with it. Best not to ask questions." << std::endl;
            moveWay = 1;
            break;
        case 4: std::cout << "Pulling on the vine, you dislodge a bar from the caged ";
            std::cout << "window. You decide to cimb up to the window. " << std::endl;
            std::cout << "Unfortunately, there's gravity up here.";
            std::cout << "You fall to your death." << std::endl;
            player.takeDamage(999);
            break;
        case 5: std::cout << "Returning to iron maiden room." << std::endl;
            moveWay = 4;
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
 ** Function: blueFlower
 ** Description: modulates interaction with blue flower
 ** Parameters: none
 *********************************************************************/


void secretGarden::blueFlower(Player& player)
{
    std::cout << "That flower has a particularly unappealing odor." << std::endl;
    std::cout << "Would you like to:" << std::endl;
    std::cout << "Eat it - enter 1" << std::endl;
    std::cout << "Put it in your knapsack - enter 2" << std::endl;
    std::cout << "Ignore it - enter 3" << std::endl;
    int selection;
    selection = validateInt();
    while (selection <1 || selection > 3)
    {
        std::cout << "Invalid. Please enter a number between 1 and 3."<< std::endl;
        selection = validateInt();
    }
    switch (selection)
    {
        case 1: std::cout  << "That flower was not edible! Hunger increases by 1.";
            std::cout<< std::endl;
            player.takeHunger(1);
            break;
        case 2: Items blueFlower("blue flower", true, -1);
            player.addToKnapsack(blueFlower);
            std::cout << "Item added to knapsack." << std::endl;
            break;
    }

}

/*********************************************************************
 ** Function: lettuceThing
 ** Description: modulates interaction with lettuceThing
 ** Parameters: none
 *********************************************************************/


void secretGarden::lettuceThing(Player& player)
{
    std::cout << "Well...it might be edible..." << std::endl;
    std::cout << "Would you like to:" << std::endl;
    std::cout << "Eat it - enter 1" << std::endl;
    std::cout << "Put it in your knapsack - enter 2" << std::endl;
    std::cout << "Ignore it - enter 3" << std::endl;
    int selection;
    selection = validateInt();
    while (selection <1 || selection > 3)
    {
        std::cout << "Invalid. Please enter a number between 1 and 3."<< std::endl;
        selection = validateInt();
    }
    switch (selection)
    {
        case 1: std::cout  << "Hunger decreased by 3.";
            std::cout<< std::endl;
            player.takeHunger(-3);
            break;
        case 2: Items lettuceThing("lettuce thing", true, 3);
            player.addToKnapsack(lettuceThing);
            std::cout << "Item added to knapsack." << std::endl;
            break;
    }
    
}

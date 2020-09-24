/*********************************************************************
 ** Program Filename: startRoom.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: startRoom class implementation
 *********************************************************************/

#include "startRoom.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in starting room, displays initial explanation. proceeds to room display
 menu */

startRoom::startRoom()
{
    identity = "Starting Room";
    
}
/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu
 ** Parameters: none
 *********************************************************************/
void startRoom::displayWelcome(Player& player)
{
    
    if(!beenHereBefore)
    {
        beenHereBefore = true;
        std::cout << "You awake, somewhat dazed. You appear to have fallen ";
        std::cout << "into a dark dungeon. You have no memory of how you arrived.";
        std::cout << std::endl << std::endl;
        std::cout << "Look around the room? Enter y or n" << std::endl;
    
        userChar = validateYN();
    
        if (userChar == 'n')
        {
            std::cout << "Well then. Sit here and die. See if I care. " << std::endl;
            std::cout << "I ASK AGAIN - Look around the room? Enter y or n." << std::endl;
            userChar = validateYN();
            if(userChar == 'y')
            {
                std::cout << "Thank you. Now we can proceed. " << std::endl;
            }
            else if (userChar == 'n')
            {
                std::cout << "Sigh. You're going to look around the room.";
                std::cout << " Like it or not." ;
                std::cout << std::endl << std::endl;
            }
        }
    
    std::cout << "The room is dimly lit by a single lantern. ";
    std::cout << "You can make out a strange orb in the center of the room.";
    std::cout << "An eerie sound is emitted from the object. " << std::endl;
    std::cout << "Behind you appears to be a large steel door. ";
    std::cout << "On your right and left are two doorways. " << std::endl << std::endl;
    }
    else
    {
        std::cout << "You have returned to the room in which you began. " << std::endl;
        std::cout << "The orb continues to hum strangely." <<std::endl;
        
    }
    
    displayMenu(player);

}


/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void startRoom::displayMenu(Player &player)
{
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Try to open the door - enter 1" << std::endl;
    std::cout << "Investigate the orb - enter 2" << std::endl;
    std::cout << "Inspect lantern - enter 3" << std::endl;
    std::cout << "Take left path - enter 4" << std::endl;
    std::cout << "Take right path - enter 5" << std::endl;
    std::cout << "Hint - enter 6" << std::endl;
    std::cout << "Quit - enter 0" << std::endl;
    
    userInt = validateInt();
    play(player);
}

/*********************************************************************
 ** Function: play
 ** Description: accepts user choice from menu and outputs current response
 ** Parameters: none
 *********************************************************************/
void startRoom::play(Player &player)
{
    while (userInt < 0 || userInt > 6)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 6." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        case 1:
            if(player.checkforItem("key"))
            {

                std::cout << "The key works!" << std::endl;
                std::cout << "Would you like to exit the dungeon now? Enter y/n";
                std::cout << std::endl;
                char exit;
                exit = validateYN();
                if (exit != 'y')
                {
                    std::cout << "Seriously. You have your doughnut. Get out." << std::endl;
                    exit = 'y';
                    moveWay = 0;
                }
                else
                {
                    moveWay = 0;
                }
            }
            else
            {
            std::cout << "The door appears to be locked." << std::endl << std::endl;
                displayMenu(player);
            }
            break;
        case 2: std::cout << "It's a weird orb. You know very little about weird orbs. ";
                std::cout << "Best to leave it alone. " << std::endl << std::endl;
                displayMenu(player);
            break;
        case 3: std::cout << "Ouch! Let's not touch the hot lantern? Okay? " << std::endl;
                std::cout << std::endl;
                displayMenu(player);
            break;
        case 4: std::cout << "Proceeding along the path to the left." << std::endl;
            moveWay = 4;
            break;
        case 5: std::cout << "Proceeding along the path to the right." << std::endl;
            moveWay = 1;
            break;
        case 6: std::cout << "The fastest way to win is to:" << std::endl;
            std::cout << "1. Go left from this room, kill rat, ";
            std::cout << "select \"investigate hole\" in menu until random function ";
            std::cout << "rolls to pull through portal to treasure room." << std::endl;
            std::cout << "2. Open chest to acquire sword." << std::endl;
            std::cout << "3. Return to start room. " << std::endl;
            std::cout << "4. Go left to return to rat room." << std::endl;
            std::cout << "5. Go right." << std::endl << "6. Pull minotaur's tail, ";
            std::cout << "collect violin. Follow prompt into new space." << std::endl;
            std::cout << "7. Play violin, drop into dragon room, defeat dragon.";
            std::cout << std::endl << "8. Collect dragon's key, use orb to return to ";
            std::cout << "start room. " << std::endl;
            std::cout << "9. Select \"try to open door\" and enter y to exit." << std::endl;
            std::cout << "NOTE: Due to the random nature of damage dealt in this game, ";
            std::cout << "it may be necessary to visit the waterfall room to heal prior";
            std::cout << " to encountering the dragon. The waterfall room can be found ";
            std::cout << "by going left from the rat room." << std::endl;
            std::cout << "Timer: Hunger starts at zero. If it reaches 12, player dies.";
            std::cout << "Hunger increases by one each time player enters a new room.";
            std::cout << std::endl;
            displayMenu(player);
            break;
        case 0: std::cout << "Quitter." << std::endl;
            moveWay = 0;
            break;
    }
    
}






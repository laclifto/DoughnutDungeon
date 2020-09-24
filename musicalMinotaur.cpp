/*********************************************************************
 ** Program Filename: musicalMinotaur.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: musicalMinotaur class implementation
 *********************************************************************/

#include "musicalMinotaur.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in room, displays initial explanation. proceeds to room display
 menu */

musicalMinotaur::musicalMinotaur()
{
    identity = "Musical Minotaur Room";
    hasComeToLife = false;
    
}

/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 menu
 ** Parameters: none
 *********************************************************************/
void musicalMinotaur::displayWelcome(Player& player)
{
    if(!beenHereBefore)
    {
        beenHereBefore = true;
        std::cout << std::endl;
        std::cout << "You enter a fairly empty room. There's an odd statue of a violin-";
        std::cout << "playing minotaur in the center of the room. You hear music...but ";
        std::cout << "it doesn't appear to be coming from the statue.";
        std::cout << "You may be going insane. You do notice a small, arched";
        std::cout << " doorway across the room.";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "You have returned to the room with the stone minotaur. ";
        std::cout << std::endl;
    }
    displayMenu(player);

}


/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void musicalMinotaur::displayMenu(Player &player)
{
    std::cout << std::endl;
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Return to the mutant rat room - enter 1" << std::endl;
    std::cout << "Return to the secret garden room - enter 2" << std::endl;
    std::cout << "Proceed through the small doorway - enter 3" << std::endl;
    std::cout << "Pluck the stone violin strings";
    std::cout << " - enter 4" << std::endl;
    std::cout << "Pull the minotaur statue's tail - enter 5" << std::endl;
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
void musicalMinotaur::play(Player &player)
{
    
    while (userInt < 0 || userInt > 7)
    {
        std::cout << "That is not a valid choice. Please enter a number between ";
        std::cout << "1 and 7." << std::endl;
        userInt = validateInt();
    }
    switch (userInt)
    {
        case 1: std::cout << "Returning to rat room." << std::endl;
            moveWay = 1;
            break;
        case 2: std::cout << "Returning to secret garden room." << std::endl;
            moveWay = 4;
            break;
        case 3: std::cout << "Proceeding through the small doorway." << std::endl;
            moveWay = 1;
            break;
        case 4: std::cout << "A passageway appears! An area has appeared from thin air!";
            std::cout << std::endl;
            moveWay = 6;
            break;

        case 5:
            if(!hasComeToLife)
            {
                std::cout << "Why? What good could have possibly come from this?";
                std::cout << " Well, I hope you're happy now. He's alive.";
                std::cout << " And he's ticked";
                std::cout << std::endl;
                battle(player);
            }
            else
            {
                std::cout << "Why are you still pulling the minotaur's tail?";
                std::cout << "Didn't you learn your lesson the first time?";
                std::cout << "Fortunately for you, he apparently only comes to life ";
                std::cout << "once." << std::endl;
                displayMenu(player);
            }
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
 ** Function: battle
 ** Description: modulates battle between player and zombie
 ** Parameters: none
 *********************************************************************/
void musicalMinotaur::battle(Player &player)
{
    NPC* minotaur;
    minotaur = new Minotaur;
    
    int damage;
    hasComeToLife = true;
    
    std::cout << "Minotaur attacks first! " << std::endl;
    std::cout << "Minotaur health points: " << minotaur->getHealth() << std::endl;
    
    while (!player.isDead() && !minotaur->isDead())
    {
        damage = minotaur->attack();
        player.takeDamage(damage);
        std::cout << "Player health points: " << player.getHealth() << std::endl;
        if(!player.isDead())
        {
            std::cout << "Player attacks! ";
            damage = player.attack();
            std::cout << "Player does " << damage << " damage!" << std::endl;
            minotaur->takeDamage(damage);
            std::cout << "Minotaur health points: " << minotaur->getHealth();
            std::cout << std::endl << std::endl;
        }
    }
    
    if (player.isDead())                    //if player is killed by minotaur
    {
        std::cout << "Game Over. At least you don't have to listen to that violin anymore. ";
        std::cout << std::endl;
        
        delete minotaur;
        minotaur = NULL;
        
        return;
    }
    else
    {
        std::cout << "Congratulations on your victory against the minotaur. ";
        std::cout << std::endl;
        std::cout << "The minotaur dropped his violin.";
        std::cout << " Would you like to add it to your knapsack? Enter y/n" << std::endl;
        Items violin("violin", false, 0);
        userChar = validateYN();
        if(userChar == 'y')
            player.addToKnapsack(violin);
        
        std::cout << "After defeating the minotaur, a room has appeared! Enter it?";
        std::cout << " Enter y/n" << std::endl;
        userChar = validateYN();
        while(userChar != 'y')
        {
            std::cout << "Dude. You have to go that way. Just agree to it. Enter y/n";
            std::cout << std::endl;
            userChar = validateYN();
        }
        moveWay = 6;
        
        delete minotaur;
        minotaur = NULL;
        
    }
}






















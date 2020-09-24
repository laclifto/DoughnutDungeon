/*********************************************************************
 ** Program Filename: dragonRoom.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: dragonRoom class implementation
 *********************************************************************/

#include "dragonRoom.hpp"

/*********************************************************************
 **                      CONSTRUCTOR
 *********************************************************************/
/*begins game in room, displays initial explanation. proceeds to room display
 menu */

dragonRoom::dragonRoom()
{
    identity = "Dragon Room";
    
}

/*********************************************************************
 ** Function: displayWelcome
 ** Description: displays appropriate description of room, directs to
 **                 boss fight
 ** Parameters: none
 *********************************************************************/
void dragonRoom::displayWelcome(Player& player)
{
    std::cout << std::endl;
    std::cout << "You land in front of a large fire-breathing dragon. He stirs and " ;
    std::cout << "stretches his large leathery wings. He notices you. You cannot run. ";
    std::cout << "You look up, and the room above has disappeared!";
    std::cout << "So, BOSS FIGHT TIME (c'mon. you knew it was coming). ";
    std::cout << std::endl;
    std::cout << std::endl;
    
    battle(player);

}

/*********************************************************************
 ** Function: displayMenu
 ** Description: displays user options for this room
 ** Parameters: none
 *********************************************************************/
void dragonRoom::displayMenu(Player &player)
{
    std::cout << std::endl;
    std::cout << "Now that you have defeated the dragon, you look around. " << std::endl;
    std::cout << "You notice a strange orb in the center of the room. " << std::endl;
    std::cout << "It looks similar to the orb in the room you started in.";
    std::cout << " Would you like to:" << std::endl;
    std::cout << "Investigate the orb - enter 1" << std::endl;
    std::cout << "Eat the doughnut - enter 2" << std::endl;
    std::cout << "Stow the doughnut in your knapsack - enter 3" << std::endl;
    std::cout << "View items in knapsack - enter 4" << std::endl;
    std::cout << "View current player stats - enter 5" << std::endl;
    
    userInt = validateInt();
    play(player);
}

/*********************************************************************
 ** Function: play
 ** Description: accepts user choice from menu and outputs current response
 ** Parameters: none
 *********************************************************************/
void dragonRoom::play(Player &player)
{
    
    {
        
        while (userInt < 0 || userInt > 5)
        {
            std::cout << "That is not a valid choice. Please enter a number between ";
            std::cout << "1 and 5." << std::endl;
            userInt = validateInt();
        }
        switch (userInt)
        {
            case 1: std::cout << "The orb draws you in irresistibly. Great. Another ";
                std::cout << "portal. Where are we going now?";
                std::cout << std::endl;
                moveWay = 8;
                break;
            case 2: std::cout << "You attempt to eat the doughnut, but instead begin";
                std::cout << " caressing it and muttering \"My Precious....\"";
                std::cout << std::endl << "Weirdo.";
                std::cout << std::endl;
                displayMenu(player);
                break;
            case 3:
            {
                Items doughnut("doughnut", true, 0);
                player.addToKnapsack(doughnut);
                std::cout << "Doughnut added to knapsack." << std::endl;
                displayMenu(player);
            }
                break;
            case 4: player.viewKnapsack();
                displayMenu(player);
                break;
            case 5: player.playerStats();
                displayMenu(player);
                break;

        }
        
    }

}

/*********************************************************************
 ** Function: battle
 ** Description: moderates battle between dragon and player
 ** Parameters: none
 *********************************************************************/
void dragonRoom::battle(Player& player)
{
    NPC* drogon;
    drogon = new Dragon;
    int damage;
    
    std::cout << "Dragon health: " <<drogon->getHealth() << std::endl;
    
    while (!player.isDead() && !drogon->isDead())
    {
        damage = player.attack();               //get attack from first
        std::cout << "Player does " << damage << " damage!" << std::endl;
        drogon->takeDamage(damage);
        std::cout << "Dragon health: " <<drogon->getHealth() << std::endl;
        if(!drogon->isDead())                       //dragon can only attack if not dead
        {
            damage = drogon->attack();              //get attack from second
        
            player.takeDamage(damage);
            std::cout << "Player health points: " << player.getHealth() << std::endl;

            std::cout << std::endl;
        }
        if(drogon->isDead())
        {
            player.setHealth(20);                 //restore to full health
            std::cout << "You have defeated the dragon. Congratulations! ";
            std::cout << "After defeating the dragon, a chest has appeared! Open it?";
            std::cout << " Enter y/n" << std::endl;
            userChar = validateYN();
            while(userChar != 'y')
            {
                std::cout << "Dude. You open the chest. Its what you do. Enter y/n";
                std::cout << std::endl;
                userChar = validateYN();
            }
            std::cout << "You have retrieved a doughnut. There's some form of writing ";
            std::cout << "on it. It's difficult to make out. As you stand over the dying ";
            std::cout << "dragon's breath with the doughnut, the words begin to glow: ";
            std::cout << std::endl << std::endl;
            std::cout << "One doughnut to feed them all." << std::endl;
            std::cout << "One doughnut to fatten them." << std::endl;
            std::cout << "One doughnut to bring them all" << std::endl;
            std::cout << "Into the oven. To glaze them." << std::endl << std::endl;
            std::cout << std::endl << std::endl;
            std::cout << "Well, that must've been an odd dragon. You also notice that ";
            std::cout << "the dragon dropped a key when he fell. Pick up key? Enter y/n";
            std::cout << std::endl;
            char choice = validateYN();
            if (choice == 'y')
            {
                Items key("key", false, 0);
                player.addToKnapsack(key);
                std::cout << "The key has been added to your knapsack." << std::endl;
            }
            
            displayMenu(player);
 

        }
        else if(player.isDead() && !drogon->isDead())
        {
            std::cout << "You have been defeated by the dragon. Game over. ";
            moveWay = 0;
        }
    }
    
    
    delete drogon;
    
}

















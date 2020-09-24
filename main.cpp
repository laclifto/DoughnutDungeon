/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: client code for Doughnut Dungeon
 ** Input: user interaction
 ** Output: game status
 *********************************************************************/
#include <iostream>
#include "spaceList.hpp"
#include "player.hpp"

int main() {
    
    srand(727);
    
    std::cout << "******* uplifting theme plays *******" << std::endl;
    std::cout << "             WELCOME TO              " << std::endl;
    std::cout << "          DOUGHNUT DUNGEON           " << std::endl;
    std::cout << "******* music shifts to eerie *******" << std::endl << std::endl;
    std::cout << "At least this game is text based." << std::endl;
    std::cout << "Here's the deal, anyway." << std::endl << std::endl;
    
    Player player;
    spaceList newList;
    newList.moveRooms(player);
    
    return 0;
}

/*********************************************************************
 ** Program Filename: secretGarden.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: secretGarden class definition
 *********************************************************************/
#ifndef secretGarden_hpp
#define secretGarden_hpp

#include <iostream>
#include "space.hpp"
#include "player.hpp"
#include "utils.hpp"

class secretGarden : public Space
{
private:
    
public:
    secretGarden();
    void displayMenu(Player&);
    void play(Player&);
    void blueFlower(Player&);
    void lettuceThing(Player&);
    void displayWelcome(Player&);
};


#endif /* secretGarden_hpp */

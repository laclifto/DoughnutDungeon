/*********************************************************************
 ** Program Filename: spaceList.cpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 31, 2016
 ** Description: space linked list class implementation
 *********************************************************************/


#include "spaceList.hpp"

/**********************************************************************
 *                          CONSTRUCTOR
 **********************************************************************/
/* the list constructor will set up the initial design of the dungeon rooms.
 more rooms will be added/deleted during game play */
spaceList::spaceList()
{
    head = NULL;
    tail = NULL;
    playerLocation = NULL;
    
    /* step 1 adds the start room to the circular list */
    Space* temp;
    Space* tempBack;
    Space* tempRight;
    temp = new startRoom;
    tail = temp;
    head = temp;
    head->next = temp;
    tempBack = head;
    temp = NULL;
    
    /* step 2 adds treasure room as next node in list */
    temp = new treasureRoom;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    tail->back = tempBack;
    tempBack = temp;
    temp = NULL;
    
    /* step 3 adds iron maiden room as next node in list */
    temp = new ironMaiden;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    tail->back = tempBack;
    tempBack = temp;
    temp = NULL;
    
    /* step 4 adds secret garden room as next node in list */
    temp = new secretGarden;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    tail->back = tempBack;
    tempBack = temp;
    temp = NULL;
    
    /* step 5 adds minotaur room as next node in list */
    temp = new musicalMinotaur;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    tail->back = tempBack;
    tempBack = temp;
    temp = NULL;
    
    /* step 6 adds rat room as next node in list, leaves as tail - get it? rat tail?*/
    temp = new ratRoom;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    tail->back = tempBack;
    head->back = temp;
    temp->right = head->next;
    tempBack = temp;
    tempRight = NULL;
}

/**********************************************************************
 *                          DECONSTRUCTOR
 **********************************************************************/
spaceList::~spaceList()
{
    
    delete tail->left;
    delete (tail->back)->left;
    delete head->right;
    
    
    Space* ptr = head;
    for (int i = 0; i < 6; i++)                          //loop through base list, delete
    {
        Space* garbage = ptr;

        ptr = ptr->next;
        delete garbage;
        garbage = NULL;

    }

    
    head = NULL;
    tail = NULL;
    playerLocation = NULL;

    
}

/*********************************************************************
 ** Function: moveRooms
 ** Description: moves player to room desired, begins play in that room
 ** Parameters: none
 *********************************************************************/
void spaceList::moveRooms(Player& player)
{
    bool beenToDropRoom = false;
    bool beenToWaterfall = false;
    playerLocation = head;
    playerLocation->displayWelcome(player);

    while (!player.isDead() && playerLocation->getMoveWay() != 0)
    {
        player.takeHunger(1);                     //increase hunger by 1 for each move

        switch(playerLocation->getMoveWay())
        {
            case 1: playerLocation = playerLocation->getNext();         //next
                break;
            case 2: playerLocation = playerLocation->getRight();        //right
                break;
            case 3: playerLocation = playerLocation->getLeft();         //left
                break;
            case 4: playerLocation = playerLocation->getBack();         //back
                break;
            case 5: //new room allocated at runtime if haven't been here before
                if (!beenToWaterfall)
                {
                    Space* temp1 = new waterfallRoom;
                    tail->left = temp1;
                    temp1->back = tail;
                    playerLocation = tail->left;
                    temp1 = NULL;
                }
                else
                {
                    playerLocation = tail->left;
                }
                break;
            case 6: //drop room - allocated at run time if haven't been here before
            if(!beenToDropRoom)
            {
                Space* temp1 = new dropRoom;
                (tail->back)->left = temp1;
                temp1->back = tail->back;
                playerLocation = (tail->back)->left;
                temp1 = NULL;
                beenToDropRoom = true;
            }
            else
            {
                playerLocation = (tail->back)->left;
            }
                break;
            case 7: //dragon room
            {
                Space* temp1 = new dragonRoom;
                playerLocation = temp1;
                playerLocation->next = head;
                head->right = playerLocation;

            }
                break;
            case 8:
                playerLocation = head;
                delete head->right;         //deleted during runtime, cannot return
                head->right = NULL;
                break;
            case 0:                         //if player is defeated by dragon, delete
                delete head->right;
                head->right = NULL;
        }
        playerLocation->displayWelcome(player);                         //start play
    }
}















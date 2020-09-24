/*********************************************************************
 ** Program Filename: utils.hpp
 ** Author: Leigh Ann Pruitt
 ** Date: July 5, 2016
 ** Description: utility functions implementation file
 ** Input:
 ** Output:
 *********************************************************************/
#include "utils.hpp"

using std::cout;
using std::endl;



/*********************************************************************
 ** Function: randomNum(int)
 ** Description: returns a random number between 0 and int n
 ** Parameters: integer
 ** Pre-Conditions: n/a
 ** Post-Conditions: n/a
 *********************************************************************/
int randomNum(int n)
{
    return rand()%n;
}

/**************************************************************************************
 ** Function: validateChar
 ** Description: validates input to char
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: returns valid int
 *************************************************************************************/


char validateChar()
{
    char input;
    std::cin >> input;
    
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "That input is not valid. Please enter a character.";
        std::cin >> input;
    }
    
    return input;
}


/**************************************************************************************
 ** Function: validateYN
 ** Description: validates input to yes or no
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: returns valid yes or no answer
 *************************************************************************************/
char validateYN()
{
    char input;
    std::cin >> input;
    
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "That input is not valid. Please enter y or n." << std::endl;
        std::cin >> input;
    }
    while (input != 'y' && input != 'n')
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "That is not a valid choice. Please enter y or n." << std::endl;
        std::cin >> input;
    }
    
    return input;
}

/**************************************************************************************
 ** Function: validateInt
 ** Description: validates input to int, typecasts double input to int
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: returns valid int
 *************************************************************************************/


int validateInt()
{
    double input;
    std::cin >> input;
    
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "That input is not valid. Please enter a number.";
        std::cin >> input;
    }
    
    return input;
}

/**************************************************************************************
 ** Function: checkForInt
 ** Description: returns true if user input is an integer
 ** Parameters: n/a
 ** Pre-Conditions: n/a
 ** Post-Conditions: returns bool
 *************************************************************************************/
bool checkForInt(int & userInput)
{
    int input;
    std::cin >> input;
    
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        return false;
    }
    else
    {
        userInput = input;
        return true;
    }
}
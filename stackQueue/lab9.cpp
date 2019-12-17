/*********************************************************************
** Program: lab9.cpp
** Author:Kevin Spevacek
** Date:11/27/19
** Description: main function file for lab 9 STL queue and stack
*********************************************************************/
//#include "pch.h"
#include <iostream>
//#include "inputVal.hpp"
#include "Queue.hpp"
#include "stringStack.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;
using std::string;

bool intCheck(string input);//prototype for computer to read
/**************************************************************
Function:getInt

Description: Gets user integer input and checks if it is between the lower and upper limits.
			-Arguments: None
			-Returns:int
****************************************************************/
int getInt(int lowerLimit, int upperLimit)
{
	bool inputValid = false;
	string input;

	while (!inputValid)
	{
		try
		{
			cout << "Please enter your choice number" << endl;
			getline(cin, input);
			inputValid = intCheck(input);
			if (!inputValid)
				throw input;
		}
		catch (string inv)
		{
			cout << inv << " is not valid. Please try again" << endl;
		}

		int inputInt = atoi(input.c_str());
		if (inputInt < lowerLimit || inputInt > upperLimit) {
			cout << "input is out of range. Please try again" << endl;
		}
	}

	return atoi(input.c_str());
}

/**************************************************************
Function:intCHeck

Description:input validation function function. Rules out empty and non-digit input
			-Arguments:string user input
			-Returns: bool
****************************************************************/
bool intCheck(string input)
{

	if (input.size() == 0)
	{
		cout << "Empty input" << endl;
		return 0;
	}

	for (int i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]))
		{
			return 0;
		}
	}

	return 1;

}



/**************************************************************
Function:printMenu

Description: displays main menu for user choice
			-Arguments: None
			-Returns:void
****************************************************************/
void printMenu()
{
	cout << "Please select from the choices below" << endl;
	cout << "    1. Run the integer data buffer" << endl;
	cout << "    2. Create a string palindrome" << endl;
	cout << "    3. Exit " << endl << endl;
}

/**************************************************************
Function:main

Description: main function begins with main menu choices and operates on loop 
		     until user decides to exit
			-Arguments: None
			-Returns:int
****************************************************************/
int main()
{
	srand(time(0));
	int mainMenuChoice = 0;
	cout << "Welcome to Kevin Spevacek's Program On C++ STL Queue and Stacks" << endl;
	bool quitChoice = false;

	while (!quitChoice)
	{
		int numRounds;
		int addChance;
		int removeChance;
		string inputString;
		queue<int> buffer;

		printMenu();

		int mainMenuChoice = getInt(1, 3);
		switch (mainMenuChoice)
		{
		case 1:
			buffer = {};
			cout << "Ok, how many rounds would you like to run?" << endl;
			numRounds = getInt(0, 10000);
			cout << "Ok, there will be " << numRounds << " rounds." << endl;
			cout << "What percent chance will there be to add the value to the back of the buffer?" << endl;
			addChance = getInt(0, 100);
			cout << "Ok, it will be a " << addChance << "% chance" << endl;
			cout << "What percent chance will there be to remove the value from the front of the buffer?" << endl;
			removeChance = getInt(0, 100);

			//run simulation with user inputs
			runGame(buffer, numRounds, addChance, removeChance);
		
			numRounds = 0;
			addChance = 0;
			removeChance = 0;
			break;

		case 2: //create palindrome from user string input
			cout << "Ok, please enter a string to create it's plaindrome." << endl;
			getline(cin, inputString);
			cout << ".... Working ...." << endl;
			cout << "Your plaindrome is shown below." << endl;
			cout << palindrome(inputString) << endl;
			break;

		case 3://Exit
			cout << "Thanks for playing!" << endl;
			quitChoice = true;
			break;

		default:
			cout << "Please enter a valid menu number (1 to 3 only)." << endl;
		}
	}
	return 0;
}

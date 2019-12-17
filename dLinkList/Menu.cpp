/*********************************************************************
** Program: Menu.cpp
** Author:Kevin Spevacek
** Date:10/27/19
** Description:Definition file for Menu class. Displays choices for user and runs program.
		Also contains input validation functions
*********************************************************************/
#include "Menu.hpp"
#include <iostream>
#include "Queue.hpp"
#include <string> //getline
#include <cstdlib>//atoi input validation
using std::cout;
using std::cin;
using std::endl;

/**************************************************************
Function:getInt

Description: Gets user integer input and checks if it is between the lower and upper limits.
			-Arguments: None
			-Returns:int
****************************************************************/
int Menu::getInt(int lowerLimit, int upperLimit)
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
		if (inputInt < lowerLimit || inputInt > upperLimit){
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
bool Menu::intCheck(string input)
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
Function:printMenu()

Description:displays main menu of information system to user
			-Arguments: None
			-Returns:int
****************************************************************/

void Menu::printMenu()
{
	cout << "Please select from the options below:" << endl;
	cout << "1. Enter a value to be added to the back of the queue" << endl;
	cout << "2. Display first node (front) value" << endl;
	cout << "3. Remove the first node (front) value" << endl;
	cout << "4. Display the queue contents" << endl;
	cout << "5. Exit the program" << endl << endl;

	return;
}

/**************************************************************
Function:runMenu

Description:runs the program on while loop for user choices with linkList object 
		Arugmunets:none
		Returns:void
****************************************************************/
void Menu::runMenu()
{
	cout << "Welcome to Kevin Spevacek's Circular Llinked List!!!" << endl << endl;
	int menuChoice = 0;
	int quitChoice = 0;
	Queue myQueue;
	int newHeadVal;
	int newTailVal;

	while (quitChoice != 1)
	{
		cin.clear();
		printMenu();
		menuChoice = getInt(1, 5);
		cin.clear();
		//cin.ignore(100, '\n');


		switch (menuChoice)
		{
		case 1: //add on to list head
			cout << "Ok, please enter a positive integer value to add to the back of the queue." << endl;
			newHeadVal = getInt(1, 100000);
			myQueue.addBack(newHeadVal);
			cout << endl << endl;
			
			cout << endl << "Press 0 to continue or 1 to quit" << endl; 
			quitChoice = getInt(0,1);
			if (quitChoice == 1)
			{
				cout << "See you next time!" << endl;
				cin.clear();
				break;
			}
			else
				break;

		case 2: //display front (head) value
			cout << "Ok, please enter an integer value for the add to the list tail." << endl;
			in frontVal = myQueue.getFront();
			cout << "The front value is " << frontVal;
			cout << endl << endl;
			
			cout << endl << "Press 0 to continue or 1 to quit" << endl; 
			quitChoice = getInt(0, 1);
			if (quitChoice == 1)
			{
				cout << "See you next time!" << endl;
				break;
			}
			else
				break;

		case 3: //delete front (head) value
			myQueue.removeFront();
			cout << endl << endl;
			cout << endl << "Press 0 to continue or 1 to quit" << endl; 
			quitChoice = getInt(0,1);
			if (quitChoice == 1) 
			{
				cout << "See you next time!" << endl;
				break;
			}
			else
				break;
		case 4: //show list/queue contents
			cout << "Your queue is: ";
			myQueue.printQueue();
			cout << endl << endl;
			cout << endl << "Press 0 to continue or 1 to quit" << endl; 
			quitChoice = getInt(0,1);
			if (quitChoice == 1)
			{
				cout << "See you next time" << endl;
				break;
			}
			else
				break;
		case 5: //exit program
			cout << "Thanks for playing!";
			cout << endl << endl;
			cout << endl << "Press 0 to continue or 1 to exit" << endl;
			quitChoice = getInt(0,1);
			if (quitChoice == 1)
			{
				cout << "See you next time!" << endl;
				delete myQueue;
				break;
			}
		
		}
	}
	return;
}

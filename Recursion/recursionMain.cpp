/*********************************************************************
** Program: recursionMain.cpp
** Author:Kevin Spevacek
** Date:10/29/19
** Description:main function for recursion program. Runs 
*********************************************************************/

#include <iostream>
#include <string>
#include "recursiveFunctions.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

/**************************************************************
Function:printMenu()

Description:displays main menu of information system to user
			-Arguments: None
			-Returns:int
****************************************************************/

void printMenu()
{
	cout << "Welcome to Kevin Spevacek's Recuirsion Magic Program!" << endl << endl;
	cout << "Please select from the options below" << endl;
	cout << "1. Print a string in reverse! " << endl;
	cout << "2. Calculate the sum of an array of integers!" << endl;
	cout << "3. Calculate the triange number of an integer N!" << endl;
	cout << "4. Exit the program" << endl;

	return;
}



/**************************************************************
Function:getInt

Description: Gets user integer input and checks if it is between the lower and upper limits.
			-Arguments: None
			-Returns:int
****************************************************************/
int getInt(int lowerLimit, int upperLimit)
{
	int userInt;
	bool inputValid = false;

	while (!inputValid)
	{

		cin >> userInt;

		//input validation acounting for data type
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(); 
			cout << "Invalid input - please try again :" << endl;
			cin >> userInt;
		}
		if (!cin.fail() && userInt >= lowerLimit && userInt <= upperLimit)
			break; //exits while loop



		if (userInt >= lowerLimit && userInt <= upperLimit)
		{
			inputValid = true;
		}

		if (userInt < lowerLimit || userInt > upperLimit)
		{
			cout << "Your input is not in range. Please try again." << endl;
			cin.clear();
			cin.ignore();
		}

	}
	cin.ignore();
	return userInt;
}

/**************************************************************
Function:main()

Description: -Prints menu, gets user choice, and calls apropriate function
			-Arguments: None
			-Returns:int
****************************************************************/
int main()
{
	cin.clear();
	int userChoice = 0;
	string inputString;
	int *arr; 
	int arrSize = 2;
	int numUserInts = 0;
	int triangleNum;
	int arrInput;
	int arrSum;



	while (userChoice != 4)
	{

		printMenu();
		userChoice = getInt(1, 4);

		switch (userChoice)
		{
		case 1: //Reverse String
			cout << "Ok, please enter your string to be reversed: " << endl;
			getline(cin, inputString);
			cout << "Thanks! The reverse is listed below: " << endl;
			reversePrint(inputString);
			cin.clear();
			break;

		case 2://Sum array
			cout << "Ok how many integers do you want to add together?" << endl;
			arrSize = getInt(0, 1000000);
			arr = new int[arrSize];
			
				for (int i = 0; i < arrSize; i++)
				{
					cout << "Ok, please enter integer index " << numUserInts << " to be added in the array." << endl;
					arrInput = getInt(0, 100000000);
					arr[numUserInts] = arrInput;
					numUserInts++;
				}

			arrSum = arraySum(arr, arrSize); //function call to sum the user input array
			cout << "The sum of your array is: " << arrSum << endl << endl;
			cin.clear();

			//reset array
			delete[]arr;
			arrSize = 2;
			numUserInts = 0;
			break;



		case 3:

			int intN;

			cout << "OK, we will calculate the triangle number for an integer N." << endl;
			cout << "Please enter an integer between 0 and 10000" << endl;

			intN = getInt(0, 100000);
			triangleNum = triangle(intN); //function call after input
			cout << "The triangle number is: " << triangleNum << endl << endl;
			cin.clear();
			break;

		case 4:
			break;


		default:
			cout << "Input is invalid. Please enter choice number 1, 2, 3, or 4." << endl;
			break;

		}
	}

	cout << "Thanks for playing!" << endl;
	cin.clear();
	return 0;
}




/************************************************************************
***Program name: simpleSearch
Author: Kevin Spevacek
Date: 11/18/2019
Description: Binary search function
***********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "inputVal.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

/****************************************************************
Function: simpleSearch
Description: linear seach through vector from index 0 looking for target value
Arguments: vector<int>, int
Return type:int (index of the target value)
**************************************************************************/
int simpleSearch(vector<int> numList, int targetVal)
{
	int index = 0;

	while (index < numList.size())
	{
		if (numList[index] == targetVal)
		{
			return index;
		}
		index++;
	}
return -1;
}

/****************************************************************
Function: main()
Description:main function drives simple search method with file I/O
Arguments:none
Return type:int
**************************************************************************/
int main()
{
	ifstream earlyTxt("early.txt");
	ifstream middleTxt("middle.txt");
	ifstream lateTxt("late.txt");

	vector<int> early;
	vector<int> middle;
	vector<int> late;
	int current;
	cout << "Welcome to the simple search function." << endl; 
	cout << "What is your target search value?" << endl;
	int targetVal = getInt(0, 20);
	cout << "Searching files ...." << endl << "....." << endl;

	//Read text file contents into vectors
	while (earlyTxt >> current)
	{
		early.push_back(current);
	}
	while (middleTxt >> current)
	{
		middle.push_back(current);
	}
	while (lateTxt >> current)
	{
		late.push_back(current);
	}


	cout << "Early contents are: ";
	for (int i = 0; i < early.size(); i++)
	{
		cout << early[i] << " ";
	}
	cout << endl << "Target Val is found at index " << simpleSearch(early, targetVal) << endl;
	cout << " in the early.txt file." << endl << endl;


	cout << "Middle contents are: ";
	for (int i = 0; i < early.size(); i++)
	{
		cout << middle[i] << " ";
	}
	cout << endl << "Target Val is found at index " << simpleSearch(middle, targetVal) << endl;
	cout << "in the middle.txt file " << endl << endl;

	cout << "Late contents are: ";
	for (int i = 0; i < early.size(); i++)
	{
		cout << late[i] << " ";
	}
	cout << endl << "Target Val is found at index " << simpleSearch(late, targetVal) << endl;
	cout << "in the late.txt file." << endl << endl;

	earlyTxt.close();
	middleTxt.close();
	lateTxt.close();

	return 0;
}

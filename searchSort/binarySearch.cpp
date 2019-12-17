/************************************************************************
***Program name: binarySearch
Author: Kevin Spevacek
Date: 11/21/2019
Description: Binary search function from Gaddis C++ early objects
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
Function: binarySearch
Description: Binary search method for target value
Arguments: vector<int>, int
Return type:int (-1 if targetVal is not found)
**************************************************************************/
int binarySearch(vector<int> numList, int targetVal)
{
	if (numList.size() == 0)
	{
		return 0;
	}

	int index = 0;
	int first = 0;
	int last = numList.size() - 1;

	//halve numList vector until tagetVal is found
	while ((numList[index] != targetVal) && (first <= last))
	{
		index = (last + first) / 2;

		if (numList[index] == targetVal)
		{
			return index;
		}
		else if (numList[index] > targetVal)
		{
			last = index - 1;
		}
		else
		{
			first = index + 1;
		}
	}
	return -1;
}

/****************************************************************
Function: main
Description: binary search main. Reads txt file into array, displays contents,
			and calls search function to locate target value by binary search
Arguments: none
Return type:int 
**************************************************************************/
int main()
{
	ifstream numListTxt("sorted.txt");

	vector<int> numList;
	int currentVal;
	cout << "Welcome to the binary search" << endl;
	//ifstream data from file into vector
	while (numListTxt >> currentVal)
	{
		numList.push_back(currentVal);
	}

	cout << "Your sorted.txt contents are shown below: " << endl;
	//show the text
	for (int i = 0; i < numList.size(); i++)
	{
		cout << numList[i] << " ";
	}
	cout << endl;

	//call function after getting target value from user
	cout << "What is your target search value?" << endl;
	int targetVal = getInt(0, 99);
	cout << "Your target value was found at index " << binarySearch(numList, targetVal);
	cout  << endl << endl;

}


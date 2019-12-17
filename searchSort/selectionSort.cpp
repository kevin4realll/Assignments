/************************************************************************
***Program name: selectionSort
Author: Kevin Spevacek
Date: 11/18/2019
Description: Selection sort function with input and output filestreams and input validation
*************************************************************************/
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

void selectionSort(vector<int> &numList);

/****************************************************************
Function: main
Description: main function for sorting function. Reads input file and gets 
			string input for output filename. Calls sorting function and closes files
Arguments: none
Return type:int
**************************************************************************/
int main()
{
	ifstream originalTxt("original.txt");
	vector<int> numList;
	int current;
	//read in data from ifstream original text file pushing onto numList vector
	while (originalTxt >> current)
	{
		numList.push_back(current);
	}

	//display original unsorted values
	cout << "Original data list is: ";
	for (int i = 0; i < numList.size(); i++)
	{
		cout << numList[i] << " ";
	}
	cout << endl;

	//get name for output text filename and create file
	string outputName;
	cout << "What is the name of the output file you would like to create for the sorted values?" << endl;
	getline(cin, outputName);
	ofstream outputFile(outputName.c_str());
	
	cout << "sorting data..." << endl;
	cout << "......." << endl;
	selectionSort(numList);//function call sorting text

	cout << "The sorted data list is now written to your file and also shown below: " << endl;
	for (int i = 0; i < numList.size(); i++)
	{
		cout << numList[i] << " "; //display sorted list
		outputFile << numList[i]; //write to file
		outputFile << '\n';
	}
	cout << endl;

	originalTxt.close();
	outputFile.close();
	return 0;
}


/****************************************************************
Function:selectionSort	
Description: Sort algorithm from C++.com
Arguments: vector<int>
Return type: void
**************************************************************************/
void selectionSort(vector<int> &numList)
{
	if (numList.size() <= 1)
	{
		cout << "No values to sort" << endl;
		return;
	}

	int minVal;
	int prevMinVal;
	int minIndex;

	//Outer Loop for sorting from first vector element to prenultimate 
	for (int i = 0; i < numList.size() - 1; i++)
	{
		minIndex = i;
		minVal = numList[minIndex];
		prevMinVal = minVal;

		//Nested loop finds smallest value in remaining vector and sets it at the current index i
		for (int j = i + 1; j < numList.size(); j++)
		{
			if (numList[j] < minVal)
			{
				minIndex = j;
				minVal = numList[j];
			}
		}
		numList[i] = minVal;
		numList[minIndex] = prevMinVal;
	}
}

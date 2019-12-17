/*********************************************************************
** Program: recursiveFunctions.cpp
** Author:Kevin Spevacek
** Date:10/29/19
** Description: Implementation file for 3 recursive functions 
*********************************************************************/
#include <iostream>
#include <string>
#include "recursiveFunctions.hpp"
using std::string;
using std::cout;
using std::endl;


void reversePrint(string inputString)
{
	if (inputString.length() == 0) //base case
	{
		cout << "\n";
		return;
	}
	else
	{
		//recursive step printing last character and recursively calling function with shortened string
		cout << inputString.at(inputString.length() - 1);
		reversePrint(inputString.substr(0, inputString.length() - 1));
	}

}

int arraySum(int arr[], int arrSize)
{
	//base case - arry length = 0
	if (arrSize == 1)
	{
		return arr[0];
	}
	else
	{
		//recursive step - add last int and call function again with shorter array
		return arr[arrSize - 1] + arraySum(arr, arrSize - 1);
	}

}

int triangle(int N)
{
	//base case - triangle num is 0 on 0
	if (N <= 0)
	{
		return 0;
	}
	else
	{
		//recursive step - 
		return N + triangle(N - 1);
	}
}

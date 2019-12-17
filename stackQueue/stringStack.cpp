/*********************************************************************
** Program:stringStack
** Author:Kevin Spevacek
** Date:11/27/19
** Description: Definition file for stringStack in STL lab
*********************************************************************/
#include <iostream>
//#include "pch.h"
#include "stringStack.hpp"
#include <stack>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::stack;
using std::string;

/**************************************************************
Function:palindrome

Description: Creates string palindrome through printing original and reverse
			  off of FIFO stack structure
			-Arguments: string
			-Returns: string concatinated with reverse for palindrome string
****************************************************************/
string palindrome(string inputStr)
{
	stack<char> tempStack;

	for (int i = 0; i < inputStr.length(); i++)
	{
		tempStack.push(inputStr[i]);
	}

	string outputStr = inputStr;

	while (!tempStack.empty())
	{
		outputStr = outputStr + tempStack.top();
		tempStack.pop();
	}

	return outputStr;

}
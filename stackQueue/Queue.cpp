/*********************************************************************
** Program: Queue.cpp
** Author:Kevin Spevacek
** Date:11/27/19
** Description: Definition file for Queue Class in STL lab.
*********************************************************************/
#include <iostream>
//#include "pch.h"
#include "Queue.hpp"
#include <queue>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::queue;

/**************************************************************
Function:appendBuffer

Description: Adds the random number to the back of the queue 
			  if within probability limit
			-Arguments: queue<int> &buffer, int newNum, int percentChance
			-Returns: void
****************************************************************/
void appendBuffer(queue<int> &buffer, int newNum, int percentChance)
{
	int testNum = (rand() % 100 + 1);

	if (testNum <= percentChance)
	{
		buffer.push(newNum);
		cout << newNum << " pushed to buffer" << endl;
	}
	else
	{
		cout << newNum << " not pushed onto buffer" << endl;
	}
}
/**************************************************************
Function:removeFromBuffer				

Description:removes front element of the queue
			if within probability limit
			-Arguments:queue<int> &buffer, int percentChance
			-Returns:void
****************************************************************/
void removeFromBuffer(queue<int> &buffer, int percentChance)
{
	int testNum = (rand() % 100 + 1);

	if (testNum <= percentChance)
	{
		buffer.pop();
		cout << "Removed front element of buffer" << endl;
	}
	else
	{
		cout << "Front element not removed from buffer" << endl;
	}
}
/**************************************************************
Function:runGame

Description: runs the buffer simulation and shows results on console
			-Arguments:queue<int> &buffer, int numRounds, int addChance, int removeChance
			-Returns:void
****************************************************************/
void runGame(queue<int> &buffer, int numRounds, int addChance, int removeChance)
{
	float curAvgL = buffer.size();
	float prevAvgL = buffer.size();
	float curSize = buffer.size();

	for (int i = 1; i <= numRounds; i++)
	{
		cout << "ROUND: " << i << endl;

		//Potential adding onto queue
		int N = (rand() % 1000 + 1); // random num N between 1 - 1000
		appendBuffer(buffer, N, addChance);

		//Potential removing from queue
		if(buffer.size() > 0)
		{
			removeFromBuffer(buffer, removeChance);
		}

		curSize = buffer.size();
		//Average buffer size
		curAvgL = (prevAvgL * (i - 1) + buffer.size()) / (i);
		prevAvgL = curAvgL;	
		cout << "Current size of the buffr is: " << curSize << endl;
		cout << "Average size of the buffer is: " << curAvgL << endl << endl;

	}


}


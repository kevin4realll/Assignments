/*********************************************************************
** Program:Queue.hpp
** Author:Kevin Spevacek
** Date:11/27/19
** Description: Header file for Queue functions
*********************************************************************/
#include <iostream>
#include <queue>
using std::queue;
#ifndef QUEUE_HPP
#define QUEUE_HPP
void appendBuffer(queue<int> &buffer, int newNum, int percentChance);
void removeFromBuffer(queue<int> &buffer, int percentChance);
void runGame(queue<int> &buffer, int numRounds, int addChance, int removeChance);
#endif

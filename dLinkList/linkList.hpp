/*********************************************************************
** Program name: linkList.hpp
** Author:Kevin Spevacek
** Date:11/5/19
** Description: Header file for linkList class in linked list program
*********************************************************************/
#include <iostream>
#include "Node.hpp"
#ifndef linkList_HPP
#define linkList_HPP

class linkList
{
private:
		Node* listHead = NULL;//change to NULL for LINUX
		Node* listTail = NULL;//change to NULL for LINUX
		int numNodes = 0;
public:
	linkList();
	void appendHead(int);
	void appendTail(int num);
	void showList();
	void showListRev();
	void deleteTail();
	void deleteHead();
	int getHead();
	int getTail();
	~linkList();

};

#endif

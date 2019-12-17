/*********************************************************************
** Program name:linklist.cpp
** Author:Kevin Spevacek
** Date:11/5/19
** Description: Implementation file for Node class in linked list program
*********************************************************************/
#include <iostream>
#include "linkList.hpp"

using std::cout;
using std::endl;


linkList::linkList()
{

}
/**************************************
 * *Function:appendHead
 * Description: Set new node as listHead and copy old listHead into previous position
 * *	Arguments: node value variable num
 * *	Returns:void
 * ***************************************/
void linkList::appendHead(int num)
{
	Node *tempHead = new Node(num);

	if (numNodes <= 0)
	{
		listHead = tempHead;
		listTail = tempHead;
		numNodes++;

	}
	else {
		listHead->setPrevNode(tempHead);
		tempHead->setNextNode(listHead);
		listHead = tempHead;
		numNodes++;
	}

}

/**************************************
 * *Function:appendTail
 * Description: Set new node as listTrail and copy old listTrail into previous position
 * *	Arguments: node value variable num
 * *	Returns:void
 * ***************************************/
void linkList::appendTail(int num)
{
	Node *tempTail = new Node(num);

		if (numNodes <= 0)
		{
			listHead = tempTail;
			listTail = tempTail;
			numNodes++;

		}
		else {
			listTail->setNextNode(tempTail);
			tempTail->setPrevNode(listTail);
			listTail = tempTail;
			numNodes++;
		}

}
/**************************************
 * *Function: showList()
 * Description:display list from Head to Tail 
 * *	Arguments:none 
 * *	Returns:void
 * ***************************************/
void linkList::showList()
{
	if (numNodes <= 0)
	{
		cout << "Your list does not have any nodes!" << endl;
	}
	else
	{
		Node *indexNode = listHead;
		cout << "Your list is shown below: " << endl;

		while (indexNode)
		{
			cout << indexNode->getVal() << " ";
			indexNode = indexNode->getNextNode();
		}

	}
}
/**************************************
 * *Function:showListRev
 * Description: display list from Tail to Head 
 * *	Arguments: none 
 * *	Returns:void
 * ***************************************/
void linkList::showListRev()
{

	if (numNodes <= 0)
	{
		cout << "Your list does not have any nodes!";
	}
	else
	{
		Node *indexNode = listTail;
		cout << "Your reverse list is shown below: " << endl;

		while (indexNode)
		{
			cout << indexNode->getVal() << " ";
			indexNode = indexNode->getPrevNode();
		}

	}

}

/**************************************
 * *Function:deleteTail
 * Description:Remove Node object from Tail of list
 * *	Arguments: none
 * *	Returns:void
 * ***************************************/
void linkList::deleteTail()
{
	if (numNodes <= 0)
	{
		cout << "Your list does not have any nodes!";
	}
	else
	{
		Node *currentNode = listTail;
		listTail = listTail->getPrevNode();
		if (listTail == NULL)
		{
			listHead = NULL;
			numNodes--;
		}
		else
		{
			listTail->setNextNode(NULL);
			numNodes--;
			delete currentNode;	
		}

	}



}

/**************************************
 * *Function:deleteHead
 * Description:Remove Node object from Head  of list
 * *	Arguments: none
 * *	Returns:void
 * ***************************************/
void linkList::deleteHead()
{
	if (numNodes <= 0)
	{
		cout << "Your list does not have any nodes!";
	}
	else
	{
		Node *currentHead = listHead;

		listHead = listHead->getNextNode();
		if (listHead == NULL)
		{
			listTail = NULL;
			numNodes--;
		}

		else
		{
			listHead->setPrevNode(NULL);
			delete currentHead;
			numNodes--;
		}
	}
}


/**************************************
 * *Function:getHead
 * Description:gets the value held by listHead Node
 * *	Arguments: none
 * *	Returns:int
 * ***************************************/
int linkList::getHead()
{
	if (numNodes == 0)
	{
		cout << "0 nodes on the list. Head value is NULL" << endl;
		return 0;
	}
	else 
		return listHead->getVal();

}


/**************************************
 * *Function:getTail
 * Description:gets the value held by listTarl Node
 * *	Arguments: none
 * *	Returns:int
 * ***************************************/
int linkList::getTail()
{		
	if (numNodes == 0)
	{
		cout << "0 nodes on the list. Tail value is NULL" << endl;
		return 0; 
	}
	else
		return listTail->getVal();

}

linkList::~linkList()
{
}

/*********************************************************************
** Program name: Node.hpp
** Author:Kevin Spevacek
** Date:11/5/19
** Description: QueueNode header for use in circular linked list program
*********************************************************************/
#include <iostream>


#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

struct QueueNode
{
	QueueNode *nextNode;
	QueueNode *prevNode;
	int nodeVal;
};

#endif

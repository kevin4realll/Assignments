/*********************************************************************
** Program name: Node.cpp
** Author:Kevin Spevacek
** Date:11/5/19
** Description: Implementation file for Node class in linked list program
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "Node.hpp"


Node::Node(int val) //Node constructor
{
	nodeValue = val;
	nextNode = NULL; //change to NULL for LINUX
	prevNode = NULL; //change to NULL for LINUX
}

void Node::setNextNode(Node *n)
{
	nextNode = n;
}
void Node::setPrevNode(Node *o)
{
	prevNode = o;
}
void Node::setVal(int val)
{
	nodeValue = val;
}

int Node::getVal()
{
	return nodeValue;
}
Node* Node::getNextNode()
{
	return nextNode;
}
Node* Node::getPrevNode()
{
	return prevNode;
}


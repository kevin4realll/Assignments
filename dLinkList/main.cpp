/*********************************************************************
** Program: main.cpp
** Author:Kevin Spevacek
** Date:11/5/2019
** Description:main function for linked list program. Creates menu object and runs from there
*********************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "Node.hpp"
#include "linkList.hpp" 

using std::cout;
using std::endl;


int main()
{
	Menu myMenu;
	myMenu.runMenu();
	return 0;
}


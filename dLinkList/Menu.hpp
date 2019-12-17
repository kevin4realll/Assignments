/*********************************************************************
** Program name: Menu.hpp
** Author:Kevin Spevacek
** Date:11/5/19
** Description: Header file with function prototypes for Menu functions.
*********************************************************************/
#include <iostream>
#include <string>
#ifndef MENU_HPP
#define MENU_HPP
using std::string;

class Menu{

public:

	int getInt(int lowLimit, int highLimit);
	bool intCheck(string input);
	void runMenu();
	void printMenu();
};

#endif

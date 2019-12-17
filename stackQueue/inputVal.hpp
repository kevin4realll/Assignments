/*********************************************************************
** Program: InputVal.hpp
** Author:Kevin Spevacek
** Date:11/27/19
** Description: Header file for inputValidation 
*********************************************************************/
#include <iostream>
#include <limits>
#include <string>
using std::string;

#ifndef INPUTVAL_HPP
#define INPUTVAL_HPP
int getInt(int lowerLimit, int upperLimit);
bool intCheck(string input);
#endif

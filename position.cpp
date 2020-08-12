/*
 * position.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: error-404
 */

#include "position.h"

int position::getX() const {
	return x;
}

void position::setX(int x) {
	this->x = x;
}

int position::getY() const {
	return y;
}

position::position(int int1, int int2)
{
	x = int1 ;
	y = int2 ;
}

void position::setY(int y) {
	this->y = y;
}

position::position()
{
	x = 0 ;
	y = 0 ;
}


/*
 * Mushroom.cpp
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#include "Mushroom.h"

Mushroom::Mushroom() : GameObject()
{
	health = 2 ;
}

Mushroom::Mushroom(int x, int y) : GameObject(x,y)
{
	health = 2 ;
}

void Mushroom::Draw()
{
	if (health == 2)
		DrawSquare( getPos().getX() , getPos().getY() ,10,colors[RED]) ;

	else if (health == 1)
		DrawSquare( getPos().getX() , getPos().getY() ,10,colors[PINK]) ;
	else
		setPos(800,800) ;
}

int Mushroom::getHealth() const {
	return health;
}

void Mushroom::setHealth(int health) {
	this->health = health;
}

Mushroom::~Mushroom() {}


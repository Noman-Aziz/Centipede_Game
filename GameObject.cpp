/*
 * GameObject.cpp
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#include "GameObject.h"

GameObject::GameObject() : pos(0,0) {}

GameObject::GameObject(int x, int y) : pos(x,y) {}

void GameObject::setPos(int int1, int int2)
{
	pos.setX(int1) ;
	pos.setY(int2) ;
}

position GameObject::getPos() const
{
	return pos ;
}

GameObject::~GameObject() {}


/*
 * GameObject.h
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "position.h"
using namespace std ;

class GameObject
{
	position pos ;

	public:

	GameObject();
	GameObject(int,int) ;

	void setPos(int,int) ;
	position getPos() const ;

	virtual void Draw() = 0 ;

	virtual ~GameObject();
};

#endif /* GAMEOBJECT_H_ */

/*
 * MoveableObject.h
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_

#include "GameObject.h"
using namespace std ;

class MoveableObject: public GameObject
{

	public:

		MoveableObject();
		MoveableObject(int,int) ;

		virtual void Move() = 0 ;

		virtual ~MoveableObject();
};

#endif /* MOVEABLEOBJECT_H_ */

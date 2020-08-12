/*
 * Mushroom.h
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#ifndef MUSHROOM_H_
#define MUSHROOM_H_

#include "GameObject.h"
#include "util.h"
using namespace std ;

class Mushroom: public GameObject
{
	int health ;

	public:

		Mushroom();
		Mushroom(int x, int y) ;
		
		void Draw() override ;

		virtual ~Mushroom();

		int getHealth() const;
		void setHealth(int health);
};

#endif /* MUSHROOM_H_ */

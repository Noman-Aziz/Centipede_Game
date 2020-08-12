/*
 * Player.h
 *
 *  Created on: May 3, 2019
 *      Author: error-404
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "MoveableObject.h"
#include "Mushrooms.h"
#include "util.h"
using namespace std ;

class Player: public MoveableObject
{
	public:

		virtual ~Player();

		Player() ;
		Player(int x, int y);

		void Move() override ;
		void Draw() override ;

		void incX(const Mushrooms &) ;
		void decX(const Mushrooms &) ;

		void incY(const Mushrooms &) ;
		void decY(const Mushrooms &) ;
};

#endif /* PLAYER_H_ */

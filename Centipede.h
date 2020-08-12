/*
 * Centipede.h
 *
 *  Created on: May 3, 2019
 *      Author: error-404
 */

#ifndef CENTIPEDE_H_
#define CENTIPEDE_H_

#include "MoveableObject.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "Mushrooms.h"
#include "Segment.h"
using namespace std ;

class Centipede: public MoveableObject
{
	Segment * segments ;
	int quantity ;

	public:

		void Move() ;
		void Draw() ;
		
		virtual ~Centipede();
		Centipede() = default ;
		Centipede(int q);

		void HitMushrooms(const Mushrooms &) ;
		void HitPlayer(Player &, ScoreBoard &, Mushrooms &) ;

		const Segment * getSegments() const;
		void Attacked(int, Mushrooms &) ;

		int getQuantity() const;
		void setQuantity(int quantity);
};

#endif /* CENTIPEDE_H_ */

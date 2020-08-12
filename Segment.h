/*
 * Segment.h
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "MoveableObject.h"
#include "Mushrooms.h"
#include "Player.h"
#include "ScoreBoard.h"
#include <fstream>
#include <cstdlib>
#include "util.h"
using namespace std ;

class Segment: public MoveableObject
{
	bool magic ;
	bool alive ;

	bool check, check3 ; //Check and Check3 tells the Segment that it has hit the end and will turn itself.
	bool bottom, rebounce ;

	public:

		Segment()  ;
		Segment(int,int);

		void Draw() ;
		void Move() ;

		bool AttackPlayer(Player &, ScoreBoard &, Mushrooms &) ;

		void HitMushroom(const Mushrooms &) ;

		void MovementUpdate() ;

		virtual ~Segment();

		bool isMagic() const;
		void setMagic(bool magic);

		void setAlive(bool, Mushrooms &) ;
		bool isAlive() const;
};

#endif /* SEGMENT_H_ */

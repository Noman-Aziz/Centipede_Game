/*
 * Fleas.h
 *
 *  Created on: May 8, 2019
 *      Author: error-404
 */

#ifndef FLEAS_H_
#define FLEAS_H_

#include "MoveableObject.h"
#include "util.h"
#include "Mushrooms.h"
#include "Player.h"
#include "Centipede.h"

class Fleas: public MoveableObject
{
	int timer ;
	bool check ;
	int mushroom_timer ;

	public:

		virtual ~Fleas();
		Fleas();

		int getTimer() const;
		void setTimer(int timer);

		void RandomPos() ;

		void Draw() override ;
		void Move() override ;
		void GenMushroom(Mushrooms &) ;

		bool isCheck() const;
		void setCheck(bool check);

		int getMushroomTimer() const;
		void setMushroomTimer(int mushroomTimer);

		void HitPlayer(Player &, ScoreBoard &, Centipede &, Mushrooms &) ;
};

#endif /* FLEAS_H_ */

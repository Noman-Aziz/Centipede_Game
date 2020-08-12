/*
 * Laser.h
 *
 *  Created on: May 6, 2019
 *      Author: error-404
 */

#ifndef LASER_H_
#define LASER_H_

#include "MoveableObject.h"
#include "util.h"
#include "Player.h"
#include "Mushrooms.h"
#include "ScoreBoard.h"
#include "Centipede.h"
#include "Fleas.h"

class Laser: public MoveableObject
{
	bool fire ;

	public:

		void Move() override ;
		void Draw() override ;

		Laser() ;
		virtual ~Laser();

		void UpdatePos() ;
		void HitMushrooms(Mushrooms &, ScoreBoard &) ;
		void HitCentipede(Mushrooms &, Centipede &, ScoreBoard & ) ;
		void HitFleas(Fleas &, Mushrooms &, ScoreBoard & ) ;

		void setFire(const Player &);
};

#endif /* LASER_H_ */

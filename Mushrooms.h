/*
 * Mushrooms.h
 *
 *  Created on: May 4, 2019
 *      Author: error-404
 */

#ifndef MUSHROOMS_H_
#define MUSHROOMS_H_

#include "Mushroom.h"
#include "util.h"
#include "GameObject.h"
using namespace std ;

class Mushrooms : public GameObject
{
	int quantity ;
	Mushroom * mushrooms ;
	Mushroom * respawn ;
	int respawn_quantity ;

	public:

		Mushrooms(int q=20);

		void setPositions() ;

		void Draw() override ;

		virtual ~Mushrooms();

		const Mushroom * getMushrooms() const;
		void Attacked(int,int) ;

		void addRespawn(int,int) ;

		void setQuantity(int) ;
		int getQuantity() const;

		const Mushroom* getRespawn() const;

		int getRespawnQuantity() const;
		void setRespawnQuantity(int respawnQuantity);
};

#endif /* MUSHROOMS_H_ */

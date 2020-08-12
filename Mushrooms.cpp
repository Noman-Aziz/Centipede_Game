/*
 * Mushrooms.cpp
 *
 *  Created on: May 4, 2019
 *      Author: error-404
 */

#include "Mushrooms.h"

Mushrooms::Mushrooms(int q) : GameObject()
{
	setQuantity(q) ;
}

void Mushrooms::setQuantity(int q)
{
	quantity = q ;
	respawn_quantity = 0 ;
	mushrooms = new Mushroom[q] ;
	setPositions() ;
}
Mushrooms::~Mushrooms() {}

void Mushrooms::addRespawn(int x, int y)
{
	Mushroom temp[respawn_quantity] ;

	for ( int i=0 ; i<respawn_quantity ; i++ )
	{
		temp[i].setPos( respawn[i].getPos().getX(), respawn[i].getPos().getY() ) ;
	}

	respawn_quantity++ ;

	respawn = new Mushroom[respawn_quantity] ;

	for ( int i=0 ; i<respawn_quantity ; i++ )
	{
		if (i!=respawn_quantity-1)
			respawn[i].setPos( temp[i].getPos().getX(), temp[i].getPos().getY() ) ;

		else
			respawn[i].setPos(x,y) ;
	}
}

void Mushrooms::setPositions()
{
	int x = GetRandInRange( 10,590 ) ;
	int y = GetRandInRange( 80 , 580 ) ;
	int temp_one, temp_two ;

	temp_one = (x/10) * 10 ;
	temp_two = x + 10 ;

	if (x - temp_one > temp_two - x)
		x = temp_two ;
	else
		x = temp_one ;

	temp_one = (y/10) * 10 ;
	temp_two = y + 10 ;

	if (y - temp_one > temp_two - y)
		y = temp_two ;
	else
		y = temp_one ;

	bool check = true ;

	for ( int i=0 ; i<quantity ; i++ )
	{
		if (i==0)
		{
			while ( x<10 || x>590 || y<80 || y>580 )
			{
				x = GetRandInRange( 10 , 590 ) ;
				y = GetRandInRange( 80 , 580 ) ;

				temp_one = (x/10) * 10 ;
				temp_two = x + 10 ;

				if (x - temp_one > temp_two - x)
					x = temp_two ;
				else
					x = temp_one ;

				temp_one = (y/10) * 10 ;
				temp_two = y + 10 ;

				if (y - temp_one > temp_two - y)
					y = temp_two ;
				else
					y = temp_one ;
			}

			mushrooms[i].setPos(x,y) ;
		}

		else
		{
			do
			{
				check = true ;

				x = GetRandInRange( 10,590 ) ;
				y = GetRandInRange( 80 , 580 ) ;

				temp_one = (x/10) * 10 ;
				temp_two = x + 10 ;

				if (x - temp_one > temp_two - x)
					x = temp_two ;
				else
					x = temp_one ;

				temp_one = (y/10) * 10 ;
				temp_two = y + 10 ;

				if (y - temp_one > temp_two - y)
					y = temp_two ;
				else
					y = temp_one ;


				if ( x<10 || x>590 || y<80 || y>580 )
					check = false ;

				for ( int j=0 ; j < i ; j++ )
				{
					if ( mushrooms[j].getPos().getX() == x and mushrooms[j].getPos().getY() == y )
						check = false ;
				}

			} while ( check == false ) ;

			mushrooms[i].setPos(x,y) ;
		}
	}
}

void Mushrooms::Draw()
{
	for ( int i=0 ; i<quantity ; i++ )
		mushrooms[i].Draw() ;

	for ( int i=0 ; i<respawn_quantity ; i++ )
		respawn[i].Draw() ;
}

void Mushrooms::Attacked(int a, int b)
{
	if (a != -1)
		mushrooms[a].setHealth( mushrooms[a].getHealth() - 1 ) ;

	if (b != -1)
		respawn[b].setHealth( respawn[b].getHealth() - 1 ) ;
}

const Mushroom * Mushrooms::getMushrooms() const {
	return mushrooms;
}

int Mushrooms::getQuantity() const {
	return quantity;
}

const Mushroom* Mushrooms::getRespawn() const {
	return respawn;
}

int Mushrooms::getRespawnQuantity() const {
	return respawn_quantity;
}

void Mushrooms::setRespawnQuantity(int respawnQuantity) {
	respawn_quantity = respawnQuantity;
}

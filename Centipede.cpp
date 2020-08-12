/*
 * Centipede.cpp
 *
 *  Created on: May 3, 2019
 *      Author: error-404
 */

#include "Centipede.h"

Centipede::~Centipede() {}

const Segment * Centipede::getSegments() const {
	return segments;
}

void Centipede::Attacked(int i, Mushrooms & mushi)
{
	segments[i].setAlive(false,mushi) ;
}

Centipede::Centipede(int q)
{
	setQuantity(q) ;
}

void Centipede::HitPlayer(Player & pl, ScoreBoard  & score, Mushrooms & mush )
{
	bool check = false ;

	for ( int i=0 ; i<quantity ; i++ )
	{
		check = segments[i].AttackPlayer( pl, score, mush ) ;

		if (check == true)
		{
			setQuantity(quantity) ;
			break ;
		}
	}
}

void Centipede::HitMushrooms(const Mushrooms & temp)
{
	for ( int i=0 ; i<quantity ; i++ )
	{
		segments[i].HitMushroom(temp) ;
	}
}

void Centipede::Draw()
{
	for ( int i=0 ; i<quantity ; i++ )
		segments[i].Move() ;
}

void Centipede::Move()
{
	Draw() ;
}

int Centipede::getQuantity() const {
	return quantity;
}

void Centipede::setQuantity(int q)
{
	segments = nullptr ;

	int x=30,y=590 ;

	Mushrooms temp ;
	temp.setQuantity(0) ;

	quantity = q ;
	segments = new Segment[quantity] ;

	for ( int i=0 ; i<quantity ; i++ )
	{
		if (i==quantity-1)
			segments[i].setMagic(true) ;

		segments[i].setPos( x+(i*10), y ) ;
		segments[i].setAlive(true,temp) ;
	}
}

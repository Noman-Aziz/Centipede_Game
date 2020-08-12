/*
 * Player.cpp
 *
 *  Created on: May 3, 2019
 *      Author: error-404
 */

#include "Player.h"

Player::~Player() {}

Player::Player() : MoveableObject(300,50) {}

Player::Player(int x, int y) :
		MoveableObject(x, y) {
}

void Player::Move()
{
	Draw() ;
}

void Player::Draw()
{
	DrawSquare( getPos().getX() , getPos().getY() ,10,colors[BLUE]);
}

void Player::incX(const Mushrooms & temp)
{
	int temp_x = getPos().getX() + 10 ;
	int temp_y = getPos().getY() ;
	bool check = true ;

	for ( int i=0 ; i<temp.getQuantity() ; i++ )
	{
		if ( temp_x == temp.getMushrooms()[i].getPos().getX() and temp_y == temp.getMushrooms()[i].getPos().getY() )
			check = false ;
	}

	for ( int i=0 ; i<temp.getRespawnQuantity() ; i++)
	{
		if ( temp_x == temp.getRespawn()[i].getPos().getX() and temp_y == temp.getRespawn()[i].getPos().getY() )
			check = false ;
	}


	if( temp_x <= 590 and check == true )
		setPos( temp_x, temp_y ) ;
}

void Player::decX(const Mushrooms & temp)
{
	int temp_x = getPos().getX() - 10 ;
	int temp_y = getPos().getY() ;
	bool check = true ;

	for ( int i=0 ; i<temp.getQuantity() ; i++ )
	{
		if ( temp_x == temp.getMushrooms()[i].getPos().getX() and temp_y == temp.getMushrooms()[i].getPos().getY() )
			check = false ;
	}

	for ( int i=0 ; i<temp.getRespawnQuantity() ; i++)
	{
		if ( temp_x == temp.getRespawn()[i].getPos().getX() and temp_y == temp.getRespawn()[i].getPos().getY() )
			check = false ;
	}

	if( temp_x >= 0 and check == true )
		setPos( temp_x, temp_y ) ;
}

void Player::incY(const Mushrooms & temp)
{
	int temp_x = getPos().getX() ;
	int temp_y = getPos().getY() + 10 ;
	bool check = true ;

	for ( int i=0 ; i<temp.getQuantity() ; i++ )
	{
		if ( temp_x == temp.getMushrooms()[i].getPos().getX() and temp_y == temp.getMushrooms()[i].getPos().getY() )
			check = false ;
	}

	for ( int i=0 ; i<temp.getRespawnQuantity() ; i++)
	{
		if ( temp_x == temp.getRespawn()[i].getPos().getX() and temp_y == temp.getRespawn()[i].getPos().getY() )
			check = false ;
	}

	if( temp_y <= 100 and check == true )
		setPos( temp_x, temp_y ) ;
}

void Player::decY(const Mushrooms & temp)
{
	int temp_x = getPos().getX() ;
	int temp_y = getPos().getY() - 10 ;
	bool check = true ;

	for ( int i=0 ; i<temp.getQuantity() ; i++ )
	{
		if ( temp_x == temp.getMushrooms()[i].getPos().getX() and temp_y == temp.getMushrooms()[i].getPos().getY() )
			check = false ;
	}

	for ( int i=0 ; i<temp.getRespawnQuantity() ; i++)
	{
		if ( temp_x == temp.getRespawn()[i].getPos().getX() and temp_y == temp.getRespawn()[i].getPos().getY() )
			check = false ;
	}

	if( temp_y >= 50 and check == true )
		setPos( temp_x, temp_y ) ;
}

/*
 * Segment.cpp
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#include "Segment.h"

Segment::Segment()
{
	magic = false ;
	alive = true ;
	check = true ;
	bottom = false ;
	check3 = true ;
	rebounce = false ;
}

Segment::Segment(int x, int y) : MoveableObject(x,y)
{
	magic = false ;
	alive = true ;
	check = true ;
	bottom = false ;
	check3 = true ;
	rebounce = false ;
}

Segment::~Segment() {}

void Segment::setAlive(bool b, Mushrooms & mush)
{
	if (mush.getQuantity() != 0)
			mush.addRespawn(getPos().getX(),getPos().getY()) ;

	alive = b ;

	if (b==false)
		setPos(800,800) ;
}

bool Segment::AttackPlayer( Player & pl, ScoreBoard & score, Mushrooms & mush )
{
	int x = getPos().getX() ;
	int y = getPos().getY() ;

	int player_x = pl.getPos().getX() ;
	int player_y = pl.getPos().getY() ;

	if ( x == player_x and y == player_y )
	{
		score.setLives( score.getLives() - 1 ) ;

		if ( score.getLives() == 0 )
		{
			cout<<"Player is Dead :("<<endl;
			cout<<"Your Score : "<<score.getScore()<<endl;
			exit(EXIT_FAILURE) ;
		}

		else
		{
			pl.setPos(300,50);
			mush.setQuantity(30) ;
			mush.setRespawnQuantity(0) ;
			return true ;
		}
	}

	return false ;
}

void Segment::HitMushroom( const Mushrooms & temp )
{
	int x = getPos().getX() ;
	int y = getPos().getY() ;

	int mushroom_x ;
	int mushroom_y ;

	for ( int i=0 ; i < temp.getQuantity() ; i++ )
	{
		mushroom_x = temp.getMushrooms()[i].getPos().getX() ;
		mushroom_y = temp.getMushrooms()[i].getPos().getY() ;

		if ( (x + 10 == mushroom_x || x - 10 == mushroom_x ) and y == mushroom_y )
		{
			if ( check == false )
				check = true ;
			else
				check = false ;

			if ( check3 == false )
				check3 = true ;
			else
				check3 = false ;
			
			setPos( x, y-10 ) ;
		}

		for ( int i=0 ; i < temp.getRespawnQuantity() ; i++ )
		{
			mushroom_x = temp.getRespawn()[i].getPos().getX() ;
			mushroom_y = temp.getRespawn()[i].getPos().getY() ;

			if ( (x + 10 == mushroom_x || x - 10 == mushroom_x ) and y == mushroom_y )
			{
				if ( check == false )
					check = true ;
				else
					check = false ;

				if ( check3 == false )
					check3 = true ;
				else
					check3 = false ;

				setPos( x, y-10 ) ;
			}
		}
	}
}

void Segment::MovementUpdate()
{
	int x = getPos().getX() ;
	int y = getPos().getY() ;

	if (bottom == false)
	{
		if ( y - 10 < 50 and  x >= 590)
		{
			bottom = true ;
			setPos( x , y + 10 ) ;
		}

		else if( x + 10 <= 590 and check == true)
			setPos( x + 10, y ) ;

		else if ( x + 10 > 590 and check == true)
		{
			check = false ;

			if( y - 10 >= 50 )
				setPos( x , y - 10 ) ;
		}

		else if ( check == false and x - 10 >= 0)
		{
			setPos( x - 10, y );
		}

		else if ( check == false and x - 10 < 0)
		{
			check = true ;

			if( y - 10 >= 50 )
				setPos( x , y - 10 ) ;
		}
	}

	else
	{
		if ( x + 10 > 590 and y + 10 > 70 )
		{
			setPos( x, y - 10 ) ;
			rebounce = true ;
			check3 = false ;
		}

		else if ( rebounce == true and x - 10 < 0 and y == 60 )
		{
			setPos( x, y - 10 ) ;
			rebounce = false ;
			check3 = true ;
		}

		else if( x + 10 > 590 and check3 == true )
		{
			check3 = false ;

			if( y + 10 <= 70 )
				setPos( x , y + 10 ) ;
		}

		else if( x + 10 <= 590 and check3 == true )
			setPos( x + 10, y ) ;

		else if ( check3 == false and x - 10 >= 0 )
		{
			setPos( x - 10, y );
		}

		else if ( check3 == false and x - 10 < 0 )
		{
			check3 = true ;

			if( y + 10 <= 70 )
				setPos( x , y + 10 ) ;
		}
	}
}

void Segment::Move()
{
	if (alive == true)
	{
		Draw() ;
		MovementUpdate() ;
	}

	else
		setPos(800,800) ;
}

void Segment::Draw()
{
	if (magic == false)
		DrawSquare( getPos().getX() , getPos().getY() ,10,colors[YELLOW]);
	else
		DrawSquare( getPos().getX() , getPos().getY() ,10,colors[ORANGE]);
}

bool Segment::isMagic() const {
	return magic;
}

void Segment::setMagic(bool magic) {
	this->magic = magic;
}

bool Segment::isAlive() const {
	return alive;
}

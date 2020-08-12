/*
 * Laser.cpp
 *
 *  Created on: May 6, 2019
 *      Author: error-404
 */

#include "Laser.h"

void Laser::HitFleas(Fleas & fl, Mushrooms& mush, ScoreBoard& score)
{
	int y = fl.getPos().getY() ;

	if ( (y-5) % 10 == 0 )
		y -= 5 ;

	else if ( (y+5) % 10 == 0 )
		y += 5 ;

	if ( getPos().getX() == fl.getPos().getX() and getPos().getY() == y )
	{
		fire = false ;
		fl.setTimer(0) ;
		fl.setCheck(false) ;
		mush.addRespawn(fl.getPos().getX(), y) ;
		fl.RandomPos() ;
		setPos( 300, 20 ) ;
		score.setScore( score.getScore() + 200 ) ;
	}
}

void Laser::setFire(const Player & pl)
{
	if (fire == false)
	{
		fire = true ;
		setPos( pl.getPos().getX(), pl.getPos().getY()+10 ) ;
	}
}

Laser::Laser()
{
	fire = false ;
}

Laser::~Laser() {}

void Laser::Move()
{
	if ( fire == true )
	{
		UpdatePos() ;
		Draw() ;
	}
}

void Laser::UpdatePos()
{
	int x = getPos().getX() ;
	int y = getPos().getY() ;

	if ( y <= 600 and fire == true )
		setPos( x, y + 10 ) ;
	else
		fire = false ;
}

void Laser::HitMushrooms(Mushrooms & mush, ScoreBoard & score )
{
	for ( int i=0 ; i < mush.getQuantity() ; i++ )
	{
		if ( getPos().getX() == mush.getMushrooms()[i].getPos().getX() and getPos().getY() == mush.getMushrooms()[i].getPos().getY() )
		{
			fire = false ;
			mush.Attacked(i,-1) ;
			setPos( 300, 20 ) ;

			if (mush.getMushrooms()[i].getHealth() == 0)
				score.setScore( score.getScore()+5 ) ;

			break ;
		}
	}

	for ( int i=0 ; i < mush.getRespawnQuantity() ; i++ )
	{
		if ( getPos().getX() == mush.getRespawn()[i].getPos().getX() and getPos().getY() == mush.getRespawn()[i].getPos().getY() )
		{
			fire = false ;
			mush.Attacked(-1,i) ;
			setPos( 300,20 ) ;

			if(mush.getRespawn()[i].getHealth() == 0)
				score.setScore( score.getScore()+5 ) ;

			break ;
		}

	}
}

void Laser::HitCentipede(Mushrooms & mushi, Centipede & c, ScoreBoard & score )
{
	for ( int i=0 ; i < c.getQuantity() ; i++ )
	{
		if ( getPos().getX() == c.getSegments()[i].getPos().getX() and getPos().getY() == c.getSegments()[i].getPos().getY() )
		{
			fire = false ;
			c.Attacked(i,mushi) ;
			setPos( 300,20 ) ;

			if (c.getSegments()[i].isMagic() == true )
				score.setScore( score.getScore() + 100 ) ;

			else
				score.setScore( score.getScore() + 10 ) ;

			break ;
		}
	}

}

void Laser::Draw()
{
	DrawRectangle( getPos().getX() , getPos().getY() , 5, 5, colors[WHITE] ) ;
}

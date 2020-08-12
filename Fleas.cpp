/*
 * Fleas.cpp
 *
 *  Created on: May 8, 2019
 *      Author: error-404
 */

#include "Fleas.h"

Fleas::~Fleas() {}

int Fleas::getTimer() const {
	return timer;
}

void Fleas::setTimer(int timer) {
	this->timer = timer;
}

Fleas::Fleas()
{
	timer = 0 ;
	check = false ;
	mushroom_timer = 0 ;
	RandomPos() ;
}

void Fleas::RandomPos()
{
	int x = GetRandInRange(10,590) ;
	int y = 590 ;
	int temp_one, temp_two ;

	temp_one = (x/10) * 10 ;
	temp_two = x + 10 ;

	if (x - temp_one > temp_two - x)
		x = temp_two ;
	else
		x = temp_one ;

	setPos( x,y ) ;
}

void Fleas::Draw()
{
	DrawSquare( getPos().getX() , getPos().getY() ,10,colors[SKY_BLUE] ) ;
}

bool Fleas::isCheck() const {
	return check;
}

void Fleas::setCheck(bool check) {
	this->check = check;
}

void Fleas::Move()
{
	if (timer == 100)
	{
		check = true ;
	}

	if (check == true)
	{
		Draw() ;

		setPos( getPos().getX(), getPos().getY() - 5  ) ;

		mushroom_timer++ ;
	}

	if ( getPos().getY() < 60 )
	{
		check = false ;
		timer = 0 ;
		RandomPos() ;
	}
}

void Fleas::GenMushroom(Mushrooms & mush)
{
	if ( check == true and mushroom_timer % 25 == 0 )
	{
		int y = getPos().getY() ;

		if ( (y-5) % 10 == 0 )
			y -= 5 ;

		else if ( (y+5) % 10 == 0 )
			y += 5 ;

		mush.addRespawn( getPos().getX(), y ) ;
	}
}

int Fleas::getMushroomTimer() const {
	return mushroom_timer;
}

void Fleas::setMushroomTimer(int mushroomTimer) {
	mushroom_timer = mushroomTimer;
}

void Fleas::HitPlayer(Player& pl, ScoreBoard& score, Centipede& cent, Mushrooms& mush)
{
	int x = getPos().getX() ;
	int y = getPos().getY() ;

	if ( (y-5) % 10 == 0 )
		y -= 5 ;

	else if ( (y+5) % 10 == 0 )
		y += 5 ;

	if ( x == pl.getPos().getX() and y == pl.getPos().getY() )
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
			cent.setQuantity( cent.getQuantity() ) ;
		}
	}
}

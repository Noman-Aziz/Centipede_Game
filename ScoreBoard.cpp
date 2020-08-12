/*
 * ScoreBoard.cpp
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#include "ScoreBoard.h"

int ScoreBoard::getLives() const {
	return lives;
}

void ScoreBoard::setLives(int lives) {
	this->lives = lives;
}

const int ScoreBoard::getScore() const {
	return score;
}

void ScoreBoard::setScore(const int score) {
	this->score = score;
}

ScoreBoard::~ScoreBoard() {}

ScoreBoard::ScoreBoard()
{
	lives = 3 ;
	score = 0 ;
	bonus = 1000 ;
}

void ScoreBoard::Draw()
{
	if ( score >= bonus and lives <= 6 )
	{
		bonus += 1000  ;
		lives++ ;
	}

	string temp = "Score = " ;
	temp += to_string(score) ;

	DrawLine( 0 , 45 ,  600 , 45 , 10 , colors[AQUA_MARINE] );

	DrawString(50, 15, temp, colors[AQUA_MARINE] ) ;

	DrawString(200, 15, "Lives : ", colors[AQUA_MARINE] ) ;

	for ( int i=0 ; i<lives ; i++ )
	{
		DrawSquare( 300 + (i*20) , 15 ,10,colors[ORANGE] ) ;
	}
}

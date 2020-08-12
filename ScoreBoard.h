/*
 * ScoreBoard.h
 *
 *  Created on: May 1, 2019
 *      Author: error-404
 */

#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "string"
#include "GameObject.h"
#include "util.h"
using namespace std ;

class ScoreBoard: public GameObject
{
	private:

		int lives ;
		int score ;
		int bonus ;

	public:

	ScoreBoard();

	virtual ~ScoreBoard();

	void Draw() override ;

	int getLives() const;
	void setLives(int lives);

	const int getScore() const;
	void setScore(int score);
};

#endif /* SCOREBOARD_H_ */

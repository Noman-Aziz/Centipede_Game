/*
 * position.h
 *
 *  Created on: Apr 30, 2019
 *      Author: error-404
 */

#ifndef POSITION_H_
#define POSITION_H_

using namespace std ;

class position
{
	int x ;
	int y ;

	public:

		position();
		position(int , int) ;

		int getX() const;
		void setX(int x);

		int getY() const;
		void setY(int y);
};

#endif /* POSITION_H_ */

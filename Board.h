
#ifndef _BOARD_H_
#define _BOARD_H_

#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "util.h"
#include "ScoreBoard.h"
#include "Mushrooms.h"
#include "Player.h"
#include "Laser.h"
#include "Centipede.h"
#include "Fleas.h"
#include "GameObject.h"
#include "MoveableObject.h"

using namespace std;

class Board
{
	private:

		int xcellsize, ycellsize;
		int width, height;
		ColorNames pcolor, bcolor, gcolor;

	public:

		static const int BOARD_X = 17;
		static const int BOARD_Y = 14;

		//GameObjects

		GameObject * base ;
		MoveableObject * move_ptr ;

		ifstream input;
		ofstream output;
		int temp_score ;

		ScoreBoard score ;
		Mushrooms mushrooms ;

		Player player ;

		Laser bomb[5] ;
		int ammo ;

		Centipede centipede ;

		Fleas flee ;


		int board_array[BOARD_X][BOARD_Y];
		Board(int xsize = 8, int ysize = 8);
		~Board(void);
		void InitalizeBoard(int, int);
		void Draw();

		static int GetBoardX() {
			return BOARD_X;
		}

		static int GetBoardY() {
			return BOARD_Y;
		}

		int GetMidX() {
			return BOARD_X * xcellsize / 2.0;
		}
		int GetMidY() {
			return BOARD_Y * ycellsize / 2.0;
		}

		int GetCellSize() {
			return xcellsize;
		}

		void GetInitRandomPosition(int &x, int &y) {
		// leave 10 units from all sides
		x = GetRandInRange(50, width - 50);
		y = GetRandInRange(50, height - 50);
		}

		int GetWidth() {
			return width;
		}
		int GetHeight() {
			return height;
		}

		void GetInitTextPosition(int &x, int &y);
};

#endif

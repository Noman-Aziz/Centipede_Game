#include "Board.h"
#include <cstdio>

enum BoardParts
{
	NILL
};

Board::~Board(void)
{

}

void Board::InitalizeBoard(int w, int h)
{
	cout << "Initialize board" << endl;
	width = w;
	height = h;

	for (int i = 0; i < BOARD_Y - 1; ++i)
	{
		for (int j = 0; j < BOARD_X; ++j)
		{
			board_array[i][j] = NILL;
		}
	}
}

Board::Board(int xsize, int ysize)
{
	cout << "Constructor board" << endl;
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;

	for (int i = 0; i < BOARD_Y; ++i)
		for (int j = 0; j < BOARD_X; ++j)
			board_array[i][j] = 0;

	ammo = 0 ;
	mushrooms.setQuantity(25) ;
	centipede.setQuantity(10) ;

	input.open("highscore.txt") ;
	input >> temp_score ;
	input.close() ;

	output.open("highscore.txt") ;

}

void Board::Draw()
{
	glColor3f(0, 0, 1);
	glPushMatrix();

	bool check = true ;

	base = &score ;

	base->Draw() ;

	DrawString(420, 15, "HighScore : ", colors[AQUA_MARINE] ) ;
	DrawString(550, 15, to_string(temp_score) , colors[AQUA_MARINE] ) ;

	base = &mushrooms ;

	base->Draw() ;

	move_ptr = &player ;

	move_ptr->Move() ;
	for ( int i=0 ; i<5  ; i++)
	{
		move_ptr = &bomb[i] ;

		bomb[i].HitMushrooms(mushrooms,score) ;
		bomb[i].HitCentipede(mushrooms,centipede,score) ;
		bomb[i].HitFleas(flee,mushrooms,score) ;
		move_ptr->Move() ;
	}

	move_ptr = &centipede ;

	centipede.HitMushrooms(mushrooms) ;
	centipede.HitPlayer(player,score,mushrooms) ;
	move_ptr->Move() ;

	move_ptr = &flee ;

	move_ptr->Move() ;
	flee.GenMushroom(mushrooms) ;
	flee.HitPlayer(player,score,centipede,mushrooms) ;

	for ( int i=0 ; i < centipede.getQuantity() ; i++ )
	{
		if ( centipede.getSegments()[i].isAlive() == true )
			check = false ;
	}

	if ( check == true )
	{
		if( score.getScore() > temp_score )
			output << score.getScore() ;

		output.close() ;

		cout<<"You have Won the Game :) "<<endl;
		cout<<"Your Score : "<<score.getScore()<<endl;
		exit(EXIT_SUCCESS) ;
	}

	glPopMatrix();
}

void Board::GetInitTextPosition(int &x, int &y)
{
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}

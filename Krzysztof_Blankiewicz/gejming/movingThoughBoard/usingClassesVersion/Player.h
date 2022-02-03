#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	const char UP = 'w';
	const char DOWN = 's';
	const char RIGHT = 'd';
	const char LEFT = 'a';
	
	public:
	int x;	// x & y range from 0 to boardSize
	int y;
	
	bool move(char direction, int boardSize);
	void setPosition(int newX, int newY);
	
};

#endif

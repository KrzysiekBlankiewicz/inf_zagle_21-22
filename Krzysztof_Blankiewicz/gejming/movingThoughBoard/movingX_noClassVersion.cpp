#include <iostream>

const char UP = 'W';
const char DOWN = 'S';
const char RIGHT = 'D';
const char LEFT = 'A';

void displaySingleRaw(int size)
{
	std::cout << "|";
	for(int i = 0; i < size; ++i)
	{
		std::cout << "_|";
	}
	std::cout << std::endl;
}

void displayTopRaw(int size)
{
	for(int i = 0; i < size; ++i)
	{
		std::cout << " _";
	}
	std::cout << std::endl;
}

void displayBoardWithX(int size, int XCoord, int YCoord)
{
	displayTopRaw(size);
	
	for(int i = 0; i < size; ++i)
	{
		if(i != YCoord)
			displaySingleRaw(size);
		else
		{
			std::cout << "|";
			for(int j = 0; j < size; ++j)
			{
				if(j != XCoord)
					std::cout << "_|";
				else
					std::cout << "x|";
			}
			std::cout << std::endl;
		}
	}
	
}

int changeXCoordinate(int currentX, char direction, int boardSize)
{
	if(direction == UP || direction == DOWN)
		return currentX;
				
	if(direction == RIGHT)
		if(currentX == boardSize - 1)
			return currentX;
		else
			return ++currentX;
	if(direction == LEFT)
		if(currentX == 0)
			return currentX;
		else
			return --currentX;
}

int changeYCoordinate(int currentY, char direction, int boardSize)
{
	if(direction == RIGHT || direction == LEFT)
		return currentY;
				
	if(direction == DOWN)
		if(currentY == boardSize - 1)
			return currentY;
		else
			return ++currentY;
	if(direction == UP)
		if(currentY == 0)
			return currentY;
		else
			return --currentY;
}

void displayBoard(int size)
{
	displayTopRaw(size);
		
	for(int i = 0; i < size; ++i)
	{
		displaySingleRaw(size);
	}
	
}

int main()
{
	// initial board:
		int x, y;
		int boardSize;
		
		std::cout << "Type in size of the board" << std::endl;
		std::cin >> boardSize;
				
		std::cout << "Type in coordinates separated with space" << std::endl;
		
		std::cin >> x >> y;
		if(x > boardSize || x < 1 || y > boardSize || y < 1)
		{	
			std::cout << "Invalid coordinates";
			return 1;
		}
		
		// real coordinates start with 0, given start with 1, so:
		--x;
		--y;
		
		displayBoardWithX(boardSize, x, y);
	
	// moving loop:
	char nextMove;
	while(true)
	{
		std::cout << "Type direction [WASD] or x to exit" << std::endl;
		std::cin >> nextMove;

		if(nextMove == 'x')
			break;
					
		x = changeXCoordinate(x, std::toupper(nextMove), boardSize);
		y = changeYCoordinate(y, std::toupper(nextMove), boardSize);

		displayBoardWithX(boardSize, x, y);
	}
	
	return 0;		
}

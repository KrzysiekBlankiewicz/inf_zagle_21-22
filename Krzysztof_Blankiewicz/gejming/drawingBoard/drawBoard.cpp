#include <iostream>

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
	int boardSize;
	
	std::cout << "Type in size of the board" << std::endl;
	std::cin >> boardSize;
	
	displayBoard(boardSize);
	
	std::cout << "Type in coordinates separated with space" << std::endl;
	
	int x, y;	
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

	return 0;		
}

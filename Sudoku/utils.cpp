#include<iostream>
#include"utils.h"

void logo()
{
	std::cout << "\n\n\n";
	for (int i = 0; i < 15; i++)
	{
		std::cout << "\t\t\t\t";
		for (int j = 0; j < 70; j++)
		{
			//S
			if ((i == 0 || i == 14) && (j >= 2 && j <= 7))
			{
				std::cout << " *";
			}
			else if ((i == 1 || i == 13) && (j >= 1 && j <= 8))
			{
				std::cout << " *";
			}
			else if ((i == 3 || i == 11) && ((j >= 0 && j <= 2) || (j >= 7 && j <= 9)))
			{
				std::cout << " *";
			}
			else if ((i == 2 || i == 12) && (j <= 3 || (j >= 6 && j <= 9)))
			{
				std::cout << " *";
			}
			else if ((i >= 4 && i <= 10) && (j <= i - 1 && j >= i - 4))
			{
				std::cout << " *";
			}

			//U1
			else if (i <= 11 && ((j >= 12 && j <= 14) || (j >= 19 && j <= 21)))
			{
				std::cout << " *";
			}
			else if (i == 12 && ((j >= 12 && j <= 15) || (j >= 18 && j <= 21)))
			{
				std::cout << " *";
			}
			else if (i == 13 && (j >= 13 && j <= 20))
			{
				std::cout << " *";
			}
			else if (i == 14 && (j >= 14 && j <= 19))
			{
				std::cout << " *";
			}

			//D
			else if ((i == 0 || i == 14) && (j >= 24 && j <= 31))
			{
				std::cout << " *";
			}
			else if ((i == 1 || i == 13) && (j >= 24 && j <= 32))
			{
				std::cout << " *";
			}
			else if ((i == 2 || i == 12) && ((j >= 24 && j <= 26) || (j >= 30 && j <= 33)))
			{
				std::cout << " *";
			}
			else if ((i >= 3 && i <= 11) && ((j >= 24 && j <= 26) || (j >= 31 && j <= 33)))
			{
				std::cout << " *";
			}

			//O
			else if ((i == 0 || i == 14) && (j >= 38 && j <= 43))
			{
				std::cout << " *";
			}
			else if ((i == 1 || i == 13) && (j >= 37 && j <= 44))
			{
				std::cout << " *";
			}
			else if ((i == 2 || i == 12) && ((j >= 36 && j <= 39) || (j >= 42 && j <= 45)))
			{
				std::cout << " *";
			}
			else if ((i >= 3 && i <= 11) && ((j >= 36 && j <= 38) || (j >= 43 && j <= 45)))
			{
				std::cout << " *";
			}

			//K
			else if (i <= 7 && ((j >= 48 && j <= 50) || (i >= 55 - j && i <= 57 - j)))
			{
				std::cout << " *";
			}
			else if (i >= 8 && ((j >= 48 && j <= 50) || (j >= i + 41 && j <= i + 43)))
			{
				std::cout << " *";
			}

			//U2
			else if (i <= 11 && ((j >= 60 && j <= 62) || j >= 67))
			{
				std::cout << " *";
			}
			else if (i == 12 && ((j >= 60 && j <= 63) || j >= 66))
			{
				std::cout << " *";
			}
			else if (i == 13 && (j >= 61 && j <= 68))
			{
				std::cout << " *";
			}
			else if (i == 14 && (j >= 62 && j <= 67))
			{
				std::cout << " *";
			}

			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void printBoard(int game[9][9])
{
	std::cout << "\n\n";
	std::cout << "\t\t\t\t\t\t\t\t\t\t  ";
	std::cout << "    ";
	for (int i = 1; i < 10; i++)
	{
		std::cout << i << "   ";
	}
	std::cout << std::endl;
	std::cout << "\t\t\t\t\t\t\t\t\t\t  ";
	std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
	for (int i = 0; i < 9; i++)
	{
		std::cout << "\t\t\t\t\t\t\t\t\t\t  ";
		std::cout << i + 1 << " |";
		for (int j = 0; j < 9; j++)
		{
			if (game[i][j] == 0)
			{
				std::cout << "   ";
			}
			else
			{
				std::cout << " " << game[i][j] << " ";
			}
			if ((j + 1) % 3 == 0)
			{
				std::cout << "|";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n\t\t\t\t\t\t\t\t\t\t  ";
		if ((i + 1) % 3 == 0)
		{
			std::cout << "  +---+---+---+---+---+---+---+---+---+" << std::endl;
		}
		else
		{
			std::cout << "  +   +   +   +   +   +   +   +   +   +" << std::endl;
		}
	}
}

bool isFull(int game[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (game[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}
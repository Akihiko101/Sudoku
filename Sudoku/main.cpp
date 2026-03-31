#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<fstream>
#include"utils.h"

std::ifstream fin;
std::ofstream fout;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	std::string difficult = "Лёгкая";
	int gameCount[3] = { 0, 0, 0 };
	int bestMinutes[3] = { 0, 0, 0 };
	int bestSeconds[3] = { 0, 0, 0 };
	int difficultFile = 0;
	int difficulty = 50;
	fin.open("stats.txt");
	if (fin.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			fin >> gameCount[i] >> bestMinutes[i] >> bestSeconds[i];
		}
	}
	fin.close();

	while (true)
	{
		system("cls");
		logo();
		std::cout << "\n\n\n\n\n\n";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t            Меню\n\n";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t      1 - Новая игра\n\n";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t      2 - Сложность игры\n\n";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t      3 - Правила игры\n\n";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t      4 - Статистика\n\n";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t      5 - Выход\n\n";
		std::cout << "\t\t\t\t\t\t\t\t\t\t\t      ";

		char choice = '0';
		choice = _getch();
		if (choice < '1' || choice > '5')
		{
			std::cerr << "Некоректный ввод!";
			Sleep(2000);
			continue;
		}
		if (choice == '5')
		{
			std::cout << "Спасибо за игру!\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			break;
		}
		if (choice == '2')
		{
			while (true)
			{
				system("cls");
				logo();
				std::cout << "\n\n\n\n\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t      Выберите сложность\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\tЧем выше сложность, тем меньше изначальных чисел\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t   Выбрана " << difficult << " сложность\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t 1 - Лёгкая(50)\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t 2 - Средняя(45)\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t 3 - Сложная(40)\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t 4 - Выход\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t   ";

				char diffChoice = '0';
				diffChoice = _getch();
				if (diffChoice < '1' || diffChoice > '4')
				{
					std::cerr << "\tНекоректный ввод!";
					Sleep(2000);
					continue;
				}
				if (diffChoice == '4')
				{
					break;
				}
				if (diffChoice == '1')
				{
					difficulty = 50;
					difficultFile = 0;
					difficult = "Лёгкая";
					std::cout << "Вы выбрали лёгкую сложность!";
					Sleep(2000);
				}
				if (diffChoice == '2')
				{
					difficulty = 45;
					difficultFile = 1;
					difficult = "Средняя";
					std::cout << "Вы выбрали среднюю сложность!";
					Sleep(2000);
				}
				if (diffChoice == '3')
				{
					difficulty = 40;
					difficultFile = 2;
					difficult = "Сложная";
					std::cout << "Вы выбрали сложную сложность!";
					Sleep(2000);
				}
			}
		}
		if (choice == '3')
		{
			while (true)
			{
				system("cls");
				logo();
				std::cout << "\n\n\n\n\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\tПравила классического Судоку\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t (для выхода нажмите любую клавишу, кроме 0)\n\n";
				std::cout << "\t\t\t\t\t\t\t1. Судоку - это логическая головоломка, которая состоит из сетки 9x9, разделенной на девять 3x3 блока.\n\n";
				std::cout << "\t\t\t\t\t\t\t2. Цель игры - заполнить 9x9 сетку цифрами от 1 до 9\n";
				std::cout << "\t\t\t\t\t\t\t   так, чтобы каждая цифра встречалась только один раз в каждой строке,\n";
				std::cout << "\t\t\t\t\t\t\t   каждом столбце и каждом из девяти 3x3 блоков.\n\n";
				std::cout << "\t\t\t\t\t\t\t3. Игра начинается с частично заполненной сетки, и игрок должен заполнить оставшиеся\n";
				std::cout << "\t\t\t\t\t\t\t   клетки, следуя правилам. Некоторые клетки уже заполнены числами, и эти числа\n";
				std::cout << "\t\t\t\t\t\t\t   нельзя изменять.\n\n";
				std::cout << "\t\t\t\t\t\t\t4. Игрок может использовать логическое мышление и дедукцию, чтобы определить правильные\n";
				std::cout << "\t\t\t\t\t\t\t   числа для каждой клетки. Важно внимательно анализировать строки, столбцы и блоки,\n";
				std::cout << "\t\t\t\t\t\t\t   чтобы исключить неправильные варианты и найти правильные числа.\n\n";
				std::cout << "\t\t\t\t\t\t\t5. Игра заканчивается, когда все клетки заполнены правильно, и игрок может гордиться\n";
				std::cout << "\t\t\t\t\t\t\t   своим достижением в решении судоку!\n\n";
				std::cout << "\t\t\t\t\t\t\t";

				char ruleChoice = '0';
				ruleChoice = _getch();
				if (ruleChoice != '0')
				{
					break;
				}
				else
				{
					std::cerr << "Некоректный ввод!";
					Sleep(2000);
					continue;
				}
			}
		}
		if (choice == '4')
		{
			while (true)
			{
				system("cls");
				logo();
				std::cout << "\n\n\n\n\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t Статистика\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t (для выхода нажмите любую клавишу, кроме 0)\n\n";

				std::cout << "\t\t\t\t\t\t\t\t\t\t\tСложность: Лёгкая\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\tКоличество сыгранных игр: " << gameCount[0] << std::endl;
				std::cout << "\t\t\t\t\t\t\t\t\t\t\tЛучшее время: " << bestMinutes[0] << " минут " << bestSeconds[0] << " секунд\n\n";

				std::cout << "\t\t\t\t\t\t\t\t\t\t\tСложность: Средняя\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\tКоличество сыгранных игр: " << gameCount[1] << std::endl;
				std::cout << "\t\t\t\t\t\t\t\t\t\t\tЛучшее время: " << bestMinutes[1] << " минут " << bestSeconds[1] << " секунд\n\n";

				std::cout << "\t\t\t\t\t\t\t\t\t\t\tСложность: Сложная\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\tКоличество сыгранных игр: " << gameCount[2] << std::endl;
				std::cout << "\t\t\t\t\t\t\t\t\t\t\tЛучшее время: " << bestMinutes[2] << " минут " << bestSeconds[2] << " секунд\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t\t";

				char statsChoice = '0';
				statsChoice = _getch();
				if (statsChoice != '0')
				{
					break;
				}
				else
				{
					std::cerr << "Некоректный ввод!";
					Sleep(2000);
					continue;
				}
			}
		}
		if (choice == '1')
		{
			system("cls");
			logo();
			int board[9][9] = {
			{1,2,3, 4,5,6, 7,8,9},
			{4,5,6, 7,8,9, 1,2,3},
			{7,8,9, 1,2,3, 4,5,6},
			{2,3,4, 5,6,7, 8,9,1},
			{5,6,7, 8,9,1, 2,3,4},
			{8,9,1, 2,3,4, 5,6,7},
			{3,4,5, 6,7,8, 9,1,2},
			{6,7,8, 9,1,2, 3,4,5},
			{9,1,2, 3,4,5, 6,7,8}
			};

			int map[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			for (int i = 9; i > 1; i--)
			{
				int j = rand() % i + 1;
				std::swap(map[i], map[j]);
			}
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					board[i][j] = map[board[i][j]];
				}
			}
			int game[9][9] = {};
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					game[i][j] = board[i][j];
				}
			}
			bool staticNum[9][9] = { true };
			int cellsToRemove = 81 - difficulty;
			while (cellsToRemove > 0)
			{
				int i = rand() % 9;
				int j = rand() % 9;
				if (game[i][j] != 0)
				{
					game[i][j] = 0;
					staticNum[i][j] = false;
					cellsToRemove--;
				}
			}
			int startStopwatch = clock();
			while (true)
			{
				system("cls");
				logo();
				std::cout << "\n\n\n";
				std::cout << "\t\t\t\t\t\t\t\t\t\t       Для выхода из игры введите 0 0 0\n";
				printBoard(game);
				int row = 0, col = 0, num = 0;
				std::cout << "\n\t\t\t\t\t\t\t\t\t\t  Ваш ход (строка, столбец, число): ";
				std::cin >> row >> col >> num;
				std::cout << "\n\t\t\t\t\t\t\t\t\t\t  ";
				if (row == 0 && col == 0 && num == 0)
				{
					std::cout << "Игра завершена.";
					Sleep(2000);
					break;
				}
				row--;
				col--;
				if (row < 0 || row > 8 || col < 0 || col > 8 || num < 1 || num > 9)
				{
					std::cout << "Некорректный ввод! Используйте числа от 1 до 9." << std::endl;
					Sleep(2000);
					continue;
				}
				if (staticNum[row][col])
				{
					std::cout << "Нельзя менять изначальное или правильное число!" << std::endl;
					Sleep(2000);
					continue;
				}
				if (board[row][col] == num)
				{
					game[row][col] = num;
					staticNum[row][col] = true;
					std::cout << "Правильный ход!" << std::endl;
					Sleep(1000);

					if (isFull(game))
					{
						int endStopwatch = clock();
						int allTime = (endStopwatch - startStopwatch) / 1000;
						int minutes = allTime / 60;
						int seconds = allTime % 60;

						while (true)
						{
							system("cls");
							logo();
							printBoard(game);
							std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tПоздравляем! Вы решил судоку!\n";
							std::cout << "\t\t\t\t\t\t\t\t\t\t(для выхода нажмите любую клавишу, кроме 0)\n\n";
							gameCount[difficultFile]++;
							if ((bestMinutes[difficultFile] == 0 && bestSeconds[difficultFile] == 0) || minutes < bestMinutes[difficultFile] ||
								(minutes == bestMinutes[difficultFile] && seconds < bestSeconds[difficultFile]))
							{
								std::cout << "\t\t\t\t\t\t\t\t\t\t\t\tНовый рекорд!\n";
								bestMinutes[difficultFile] = minutes;
								bestSeconds[difficultFile] = seconds;
							}
							std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t Ваше время\n\n";
							std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t Минуты: " << minutes << std::endl;
							std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t Секунды: " << seconds << std::endl;
							std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t ";

							char endChoice = '0';
							endChoice = _getch();
							if (endChoice != '0')
							{
								break;
							}
							else
							{
								std::cerr << "Некоректный ввод!";
								Sleep(2000);
								continue;
							}
						}
						break;
					}
				}
				else
				{
					std::cout << "Неверный ход! Попробуйте снова." << std::endl;
					Sleep(1000);
				}
			}
		}
	}

	fout.open("stats.txt");
	if (!fout.is_open())
	{
		std::cerr << "\t\t\t\t\t\t\t\t\t\t\tОшибка открытия файла статистики!\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		return 1;
	}
	for (int i = 0; i < 3; i++)
	{
		fout << gameCount[i] << " " << bestMinutes[i] << " " << bestSeconds[i] << std::endl;
	}
	fout.close();
	return 0;
}
#include "MoveCoords.cpp"
#include <iostream>
enum Players { Empty = 0, Ai, Human };
class TicTacToe
{

	int board[3][3] = { {} };
	//int board[3][3] = 
	//{ 
	//	{ 2, 0, 0 }, 
	//	{ 0, 0, 0 }, 
	//	{ 0, 0, 0 } 
	//};//used for depth testing
				  
					
public:
	bool MakeMove(int x, int y, Players play)
	{
		if (x < 0 || x > 2 || y < 0 || y > 2)//check to see if it can be placed on the board
			return false;
		if (board[x][y] != Empty)//prevent the player from picking a spot thats already used
			return false;
		board[x][y] = (int)play;
		return true;
	}
	void printBoard()
	{
		int side = 1;
		std::cout << "\n" << std::endl;
		std::cout << "    1   2   3" << std::endl;
		std::cout << "    ---------" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << side++ << "|  ";
			for (int j = 0; j < 3; j++)
			{
				std::cout << board[i][j] << "   ";
			}
			std::cout << std::endl;
		}
	}
	bool checkWin(Players player)
	{
		int countRow, countCol, countDiagonally = 0, countDiagonally1 = 0, diagonallyMove = 2;
		//checks for 3 in a row both horizontally and vertically 
		for (int i = 0; i < 3; i++)
		{
			countRow = 0;
			countCol = 0;
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == player)
					countRow++;
				if (board[j][i] == player)
					countCol++;
			}
			if (countRow == 3 || countCol == 3)//check to see for 3 in a row
				return true;

			if (board[i][i] == player)//checks diagonally this way "\"
				countDiagonally++;
			if (board[i][diagonallyMove] == player)//checks diagonally this way "/"
				countDiagonally1++;
			diagonallyMove--;
		}
		if (countDiagonally == 3 || countDiagonally1 == 3)
			return true;
		return false;
	}

	//check to see if the game is tied. Must check to see if someone won first before calling checkTie.
	bool checkTie()
	{
		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == Empty)
					return false;
			}
		}
		return true;//all spaces full means the game is tied
	}
	
	public:
		MoveCoords MiniMax()
		{
			MoveCoords bestMove;
			int bestScore = -100;
			int tempScore;
			int depth = 0, alpha = -100, beta = 100;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (board[i][j] == Empty)
					{
						board[i][j] = Ai;//set the spot to Ai
						tempScore = MinScore(depth-1,alpha,beta);
						if (tempScore >= bestScore)
						{
							alpha = tempScore;
							bestScore = tempScore;
							bestMove.SetX(i);
							bestMove.SetY(j);
						}
						board[i][j] = Empty;
						if (alpha > beta) break;
					}
				}


			}

			return bestMove;

		}
	private:
		int MinScore(int depth, int alpha, int beta)
		{
			if (checkWin(Ai)) return 10;
			else if (checkWin(Human)) return -10;
			else if (checkTie()) return 0;
			MoveCoords bestMove;
			int bestScore = 100;
			int tempScore;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (board[i][j] == Empty)
					{
						board[i][j] = Human;//set the spot to Ai
						tempScore = MaxScore(depth - 1, alpha, beta) - depth;
						if (tempScore <= bestScore)
						{
							beta = tempScore;
							bestScore = tempScore;
						}
						board[i][j] = Empty;
						if (alpha > beta) break;
					}
				}
			}
			return bestScore;
		}
		int MaxScore(int depth,int alpha, int beta)
		{
			if (checkWin(Ai)) return 10;
			else if (checkWin(Human)) return -10;
			else if (checkTie()) return 0;
			MoveCoords bestMove;
			int bestScore = -100;
			int tempScore;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (board[i][j] == Empty)
					{
						board[i][j] = Ai;//set the spot to Ai
						tempScore = MinScore(depth - 1,alpha,beta) + depth;
						if (tempScore >= bestScore)
						{
							alpha = tempScore;
							bestScore = tempScore;
						}
						board[i][j] = Empty;
						if (alpha > beta) break;
					}
				}
			}
			return bestScore;
		}



};
#include "TicTacToe.cpp"
#include <string>
#include <sstream>
#include <chrono>
using namespace std;

int main()
{
	TicTacToe game;
	string input, clear;
	int turn;
	std::stringstream ss;
	MoveCoords move;
	cout << "Would you like to go first or second\n";
	cin >> turn;
	getline(cin, clear);//clean the cin so that the getline below waits for new input
	int x, y;
	if (turn == 2)
	{
		auto start = std::chrono::high_resolution_clock::now();
		move = game.MiniMax();
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::cout << "Elapsed time: " << elapsed.count() << " s\n";
		game.MakeMove(move.GetX(), move.GetY(), Ai);
	}
	game.printBoard();
		while (getline(cin,input))
		{
			ss << input.substr(0,1);
			ss >> x;
			ss.str("");
			ss.clear();
			ss << input.substr(1);
			ss >> y;
			ss.str("");
			ss.clear();
			input = "";
			while (!game.MakeMove(x-1, y-1, Human))
			{
				cout << "that is not a correct move" << endl;
				getline(cin, input);
				ss << input.substr(0,1);
				ss >> x;
				ss.str("");
				ss.clear();
				ss << input.substr(1);
				ss >> y;
				ss.str("");
				ss.clear();
				input = "";
			}
			if (game.checkWin(Human))
			{
				cout << "You Win" << endl;
				game.printBoard();
				break;
			}
			move = game.MiniMax();

			game.MakeMove(move.GetX(), move.GetY(),Ai);

			if (game.checkWin(Ai))
			{
				cout << "You Lose" << endl;
				game.printBoard();
				break;
			}
			if (game.checkTie())
			{
				cout << "You Tie" << endl;
				game.printBoard();
				break;
			}
			game.printBoard();
		}
		while (true)//keep the cmd open till the user closes it
		{

		}
	
}



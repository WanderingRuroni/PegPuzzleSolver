#include "StdAfx.h"
#include "PuzzleSolver.h"


PuzzleSolver::PuzzleSolver(void)
{
	// seeding of the random number generator
	srand(time(NULL));

	// vector of position 0 with values of its jump destination and what it jumps over
	pos0.push_back(3);
	pos0.push_back(1);
	pos0.push_back(5);
	pos0.push_back(2);

	// vector of position 1 with values of its jump destination and what it jumps over
	pos1.push_back(6);
	pos1.push_back(3);
	pos1.push_back(8);
	pos1.push_back(4);

	// vector of position 2 with values of its jump destination and what it jumps over
	pos2.push_back(7);
	pos2.push_back(4);
	pos2.push_back(9);
	pos2.push_back(5);

	// vector of position 3 with values of its jump destination and what it jumps over
	pos3.push_back(0);
	pos3.push_back(1);
	pos3.push_back(5);
	pos3.push_back(4);
	pos3.push_back(12);
	pos3.push_back(7);
	pos3.push_back(10);
	pos3.push_back(6);

	// vector of position 4 with values of its jump destination and what it jumps over
	pos4.push_back(11);
	pos4.push_back(7);
	pos4.push_back(13);
	pos4.push_back(8);

	// vector of position 5 with values of its jump destination and what it jumps over
	pos5.push_back(0);
	pos5.push_back(2);
	pos5.push_back(3);
	pos5.push_back(4);
	pos5.push_back(12);
	pos5.push_back(8);
	pos5.push_back(14);
	pos5.push_back(9);

	// vector of position 6 with values of its jump destination and what it jumps over
	pos6.push_back(1);
	pos6.push_back(3);
	pos6.push_back(8);
	pos6.push_back(7);

	// vector of position 7 with values of its jump destination and what it jumps over
	pos7.push_back(2);
	pos7.push_back(4);
	pos7.push_back(9);
	pos7.push_back(8);

	// vector of position 8 with values of its jump destination and what it jumps over
	pos8.push_back(1);
	pos8.push_back(4);
	pos8.push_back(6);
	pos8.push_back(7);

	// vector of position 9 with values of its jump destination and what it jumps over
	pos9.push_back(2);
	pos9.push_back(5);
	pos9.push_back(7);
	pos9.push_back(8);

	// vector of position 10 with values of its jump destination and what it jumps over
	pos10.push_back(3);
	pos10.push_back(6);
	pos10.push_back(12);
	pos10.push_back(11);

	// vector of position 11 with values of its jump destination and what it jumps over
	pos11.push_back(4);
	pos11.push_back(7);
	pos11.push_back(13);
	pos11.push_back(12);

	// vector of position 12 with values of its jump destination and what it jumps over
	pos12.push_back(3);
	pos12.push_back(7);
	pos12.push_back(5);
	pos12.push_back(8);
	pos12.push_back(10);
	pos12.push_back(11);
	pos12.push_back(14);
	pos12.push_back(13);

	// vector of position 13 with values of its jump destination and what it jumps over
	pos13.push_back(4);
	pos13.push_back(8);
	pos13.push_back(11);
	pos13.push_back(12);

	// vector of position 14 with values of its jump destination and what it jumps over
	pos14.push_back(5);
	pos14.push_back(9);
	pos14.push_back(12);
	pos14.push_back(13);

	// map of the possible moves using the key as the position on the board and vector of jump information
	// as the map's value
	possibleMoves.insert(map<int, vector<int> >::value_type(0, pos0));
	possibleMoves.insert(map<int, vector<int> >::value_type(1, pos1));
	possibleMoves.insert(map<int, vector<int> >::value_type(2, pos2));
	possibleMoves.insert(map<int, vector<int> >::value_type(3, pos3));
	possibleMoves.insert(map<int, vector<int> >::value_type(4, pos4));
	possibleMoves.insert(map<int, vector<int> >::value_type(5, pos5));
	possibleMoves.insert(map<int, vector<int> >::value_type(6, pos6));
	possibleMoves.insert(map<int, vector<int> >::value_type(7, pos7));
	possibleMoves.insert(map<int, vector<int> >::value_type(8, pos8));
	possibleMoves.insert(map<int, vector<int> >::value_type(9, pos9));
	possibleMoves.insert(map<int, vector<int> >::value_type(10, pos10));
	possibleMoves.insert(map<int, vector<int> >::value_type(11, pos11));
	possibleMoves.insert(map<int, vector<int> >::value_type(12, pos12));
	possibleMoves.insert(map<int, vector<int> >::value_type(13, pos13));
	possibleMoves.insert(map<int, vector<int> >::value_type(14, pos14));
}

// function that returns a string to be put into the windows form's text box after all the puzzles have been solved.
String^ PuzzleSolver::getBoard(int start)
{
	String^ boardText = "\r\n=========================================";

	// for loop iterates 10000 times and on each iteration, the board is cleared and reset based on the parameter passed into the function
	// which indicates which spot on the board is empty at the beginning of the game
	for(int k = 0; k < 10000; k++)
	{
		// clear board to reinitialize it each new puzzle
		boardSpaces.clear();

		// initializes the total number of pegs the board will start with at each puzzle
		numPegs = 14;

		for(int i = 0; i < 15; i++)
		{
			if(i == start)
			{
				boardSpaces.insert(map<int,bool>::value_type(i, false));
			}
			boardSpaces.insert(map<int,bool>::value_type(i, true));
		}
		
		// solve function called to try and solve the game with the current board
		solve();

		// if the puzzle is solved after the solve function, it prints out the necessary information into a handled String function
		if(numPegs == 1)
		{	
			boardText += "\r\nPosition Done: " + start + "\r\nPegs Left: " + numPegs + "\r\nMoves: ";
			
			// runs through the madeMoves vector and adds information about each move made to solve the puzzle
			for(unsigned int j = 0; j < madeMoves.size(); j += 2)
			{
				boardText += "\r\nFrom: " + madeMoves[j] + " To: " + madeMoves[j+1];
			}

			boardText += "\r\n";

			// clear the vector once the information is printed
			madeMoves.clear();

			// break out of the for loop
			break;
		}

		// clear the vector even if the puzzle isn't solved because a new board is required with no made moves
		madeMoves.clear();
	}

	return boardText;
}

// solve function that iterates 100 hundreds times at maximum which in each iteration, a random position on the board is selected and based on that,
// the possibleMoves map is checked for moves from that position and if the criteria are met (open destination, peg to jump over, and start peg position contains a peg),
// the jump will be called with the values. The iteration number is increased after all events occur
void PuzzleSolver::solve()
{
	iterations = 0;

	while(iterations != 100)
	{
		if(numPegs == 1)
		{
			break;
		}

		do
		{
			startPos = (rand() % 15);
		}while(!boardSpaces[startPos]);

		for(unsigned int j = 0; j < possibleMoves[startPos].size(); j += 2)
		{
			int toPos = possibleMoves[startPos][j];
			int overPos = possibleMoves[startPos][j+1];

			if(boardSpaces[toPos] == false && boardSpaces[overPos] == true && boardSpaces[startPos] == true)
			{
				jump(startPos, overPos, toPos);
			}
		}	

		iterations++;
	}
}

// jump function that accepts parameters of the jump and changes the boolean of each position in the boardSpaces map
// while also adding the made move into a vector of ints
// it also decreases the number of pegs on the board as well
void PuzzleSolver::jump(int from, int over, int to)
{
	boardSpaces[from] = false;
	boardSpaces[over] = false;
	boardSpaces[to] = true;
	madeMoves.push_back(from);
	madeMoves.push_back(to);
	numPegs--;
}

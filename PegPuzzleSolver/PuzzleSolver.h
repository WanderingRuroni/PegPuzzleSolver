#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;
using namespace System;

class PuzzleSolver
{
private:
	// sets up board with positions and whether they are occupied
	map<int, bool> boardSpaces;

	// map with int key and value of a vector to hold all the possible moves on the board
	map<int, vector<int> > possibleMoves;

	// vectors that hold what the position jumps to and what it jumps over to get there
	vector<int> pos0;
	vector<int> pos1;
	vector<int> pos2;
	vector<int> pos3;
	vector<int> pos4;
	vector<int> pos5;
	vector<int> pos6;
	vector<int> pos7;
	vector<int> pos8;
	vector<int> pos9;
	vector<int> pos10;
	vector<int> pos11;
	vector<int> pos12;
	vector<int> pos13;
	vector<int> pos14;

	// vector to keep track of the moves made to win
	vector<int> madeMoves;

	// int to keep track of pegs in the game
	int numPegs;
	int iterations;
	int startPos;

public:
	PuzzleSolver(void);
	String^ getBoard(int start);
	void solve();
	void jump(int from, int over, int to);
};



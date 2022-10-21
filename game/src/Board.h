#pragma once
#include "raylib.h"

class Board
{

private:
	int mScreenWidth;
	int mScreenHeight;
	int mSquareSize;
	Vector2 mStartingArea;
	Vector2 mGrid;

public:
	Board();
	Board(int screenWidth, int screenHeight, int squareSize, Vector2 startingArea);
	~Board();

	int GetAreaWidth();
	int GetAreaHeight();
	int GetNbColumn();
	int GetNbLine();
	Vector2 GetStartingArea();

	void Draw();
};


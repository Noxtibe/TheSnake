#include "Board.h"
#include <iostream>

Board::Board()
{
	mScreenWidth = 0;
	mScreenHeight = 0;
	mSquareSize = 0;
	mGrid.x = 0;
	mGrid.y = 0;
	mStartingArea = { 0, 0 };
}

Board::Board(int screenWidth, int screenHeight, int squareSize, Vector2 startingArea)
{
	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;
	mSquareSize = squareSize;
	mGrid.x = screenWidth % squareSize;
	mGrid.y = screenHeight % squareSize;
	mStartingArea = startingArea;
}

Board::~Board()
{
}

int Board::GetAreaWidth()
{
	return mScreenWidth;
}

int Board::GetAreaHeight()
{
	return mScreenHeight;
}

int Board::GetNbColumn()
{
	return mGrid.x;
}

int Board::GetNbLine()
{
	return mGrid.y;
}

Vector2 Board::GetStartingArea()
{
	return mStartingArea;
}

void Board::Draw()
{
	Vector2 vect1;
	Vector2 vect2;
	for (int i = 0; i < ((mScreenWidth / mSquareSize) + 1); i++)
	{
		vect1 = { (mSquareSize * i + mGrid.x / 2) + mStartingArea.x, (mGrid.y / 2) + mStartingArea.y };
		vect2 = { (mSquareSize * i + mGrid.x / 2) + mStartingArea.x, (mScreenHeight - mGrid.y / 2) + mStartingArea.y };
		DrawLineV(vect1, vect2, DARKGRAY);
	}
	for (int i = 0; i < ((mScreenHeight / mSquareSize) + 1); i++)
	{
		vect1 = { (mGrid.x / 2 ) + mStartingArea.x, (mSquareSize * i + mGrid.y / 2) + mStartingArea.y-1 };
		vect2 = { (mScreenWidth - mGrid.x / 2) + mStartingArea.x, (mSquareSize * i + mGrid.y / 2) + mStartingArea.y-1 };
		DrawLineV(vect1, vect2, DARKGRAY);
	}
}

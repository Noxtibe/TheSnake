#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	mScreenWidth = 0;
	mScreenHeight = 0;
	mPixelSize = 0;
	mGrid.x = 0;
	mGrid.y = 0;
	mStartPosition = { 0, 0 };
}

Grid::Grid(unsigned int screenWidth, unsigned int screenHeight, unsigned int squareSize, Vector2 startPosition)
{
	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;
	mPixelSize = squareSize;
	mGrid.x = screenWidth % squareSize;
	mGrid.y = screenHeight % squareSize;
	mStartPosition = startPosition;
}

Grid::~Grid()
{
}

unsigned int Grid::GetAreaWidth()
{
	return mScreenWidth;
}

unsigned int Grid::GetAreaHeight()
{
	return mScreenHeight;
}

unsigned int Grid::GetNbColumn()
{
	return mGrid.x;
}

unsigned int Grid::GetNbLine()
{
	return mGrid.y;
}

Vector2 Grid::GetStartPosition()
{
	return mStartPosition;
}

void Grid::Draw()
{
	Vector2 vect1;
	Vector2 vect2;
	for (int i = 0; i < ((mScreenWidth / mPixelSize) + 1); i++)
	{
		vect1 = { (mPixelSize * i + mGrid.x / 2) + mStartPosition.x, (mGrid.y / 2) + mStartPosition.y };
		vect2 = { (mPixelSize * i + mGrid.x / 2) + mStartPosition.x, (mScreenHeight - mGrid.y / 2) + mStartPosition.y };
		DrawLineV(vect1, vect2, DARKGRAY);
	}
	for (int i = 0; i < ((mScreenHeight / mPixelSize) + 1); i++)
	{
		vect1 = { (mGrid.x / 2 ) + mStartPosition.x, (mPixelSize * i + mGrid.y / 2) + mStartPosition.y-1 };
		vect2 = { (mScreenWidth - mGrid.x / 2) + mStartPosition.x, (mPixelSize * i + mGrid.y / 2) + mStartPosition.y-1 };
		DrawLineV(vect1, vect2, DARKGRAY);
	}
}

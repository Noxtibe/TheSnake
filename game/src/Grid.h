#pragma once
#include "raylib.h"

class Grid
{
private:

	unsigned int mScreenWidth;
	unsigned int mScreenHeight;
	unsigned int mPixelSize;
	Vector2 mStartPosition;
	Vector2 mGrid;

public:

	Grid();
	Grid(unsigned int screenWidth, unsigned int screenHeight, unsigned int pixelSize, Vector2 startPosition);
	~Grid();

	unsigned int GetAreaWidth();
	unsigned int GetAreaHeight();
	unsigned int GetNbColumn();
	unsigned int GetNbLine();

	void Draw();

	Vector2 GetStartPosition();
};


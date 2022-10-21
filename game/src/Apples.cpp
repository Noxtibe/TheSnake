#include "Apples.h"

Apples::Apples()
{
	mApplesPositions = { 0, 0 };
	mApplesSize = 0;
	mApplesColor = WHITE;
}

Apples::Apples(Vector2 applesPosition, float applesSize, Color applesColor)
{
	mApplesPositions = applesPosition;
	mApplesSize = applesSize;
	mApplesColor = applesColor;
}

Apples::~Apples()
{
}

Vector2 Apples::GetApplesPosition()
{
	return mApplesPositions;
}

unsigned short int Apples::GetApplesScore()
{
	return mApplesScore;
}

bool Apples::GetActivated()
{
	return mActivated;
}

Color Apples::GetApplesColor()
{
	return mApplesColor;
}

void Apples::SetApplesPosition(Vector2 applesPositions)
{
	mApplesPositions = applesPositions;
}

void Apples::SetApplesScore(unsigned short int applesScore)
{
	mApplesScore = applesScore;
}

void Apples::SetActivated(bool activated)
{
	mActivated = activated;
}

void Apples::Draw()
{
	DrawCircle((mApplesPositions.x + mApplesSize / 2)+1, mApplesPositions.y + mApplesSize / 2, mApplesSize / 2, SKYBLUE);
	//DrawText(FormatText("SCORE: %i",  mScore), mApplesSize, mApplesSize, 25, GRAY);
}

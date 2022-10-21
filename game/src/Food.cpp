#include "Food.h"

Food::Food()
{
	mPosition = { 0, 0 };
	mSize = 0;
	mColor = WHITE;
}

Food::Food(Vector2 position, float size, Color color)
{
	mPosition = position;
	mSize = size;
	mColor = color;
}

Food::~Food()
{
}

Vector2 Food::GetPosition()
{
	return mPosition;
}

int Food::GetScore()
{
	return mScore;
}

bool Food::GetActivated()
{
	return mActivated;
}

Color Food::GetColor()
{
	return mColor;
}

void Food::SetPosition(Vector2 position)
{
	mPosition = position;
}

void Food::SetScore(int score)
{
	mScore = score;
}

void Food::SetActivated(bool activated)
{
	mActivated = activated;
}

void Food::Draw()
{
	DrawCircle((mPosition.x + mSize / 2)+1, mPosition.y + mSize / 2, mSize / 2, RED);
	//DrawText(FormatText("SCORE: %i",  mScore), mSize, mSize, 25, GRAY);
}

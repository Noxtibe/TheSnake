#include "SnakeTail.h"

SnakeTail::SnakeTail()
{
	mSNPosition = {0,0};
	mSNSpeed = {32, 0};
	mSNColor = WHITE;
}

SnakeTail::SnakeTail(Vector2 snPosition, float snSize, Color snColor)
{
	mSNPosition = snPosition;
	mSNSpeed = { snSize, 0 };
	mSNColor = snColor;
}

SnakeTail::~SnakeTail()
{
}

Vector2 SnakeTail::GetSnakeTailPosition()
{
    return mSNPosition;
}

Vector2 SnakeTail::GetSnakeTailSpeed()
{
	return mSNSpeed;
}

Color SnakeTail::GetSnakeTailColor()
{
	return mSNColor;
}

void SnakeTail::SetSnakeTailPostion(Vector2 snPosition)
{
	mSNPosition.x = snPosition.x;
	mSNPosition.y = snPosition.y;
}

void SnakeTail::SetSnakeTailSpeed(Vector2 snSpeed)
{
	mSNSpeed.x = snSpeed.x;
	mSNSpeed.y = snSpeed.y;
}

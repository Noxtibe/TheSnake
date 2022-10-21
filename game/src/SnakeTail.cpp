#include "SnakeTail.h"

SnakeTail::SnakeTail()
{
	mSNPosition = {0,0};
	mSNSpeed = {32, 0};
	mSNColor = WHITE;
}

SnakeTail::SnakeTail(Vector2 position, float size, Color color)
{
	mSNPosition = position;
	mSNSpeed = { size, 0 };
	mSNColor = color;
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

void SnakeTail::SetSnakeTailPostion(Vector2 position)
{
	mSNPosition.x = position.x;
	mSNPosition.y = position.y;
}

void SnakeTail::SetSnakeTailSpeed(Vector2 speed)
{
	mSNSpeed.x = speed.x;
	mSNSpeed.y = speed.y;
}

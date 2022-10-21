#include "Tail.h"

Tail::Tail()
{
	mPosition = {0,0};
	mSpeed = {32, 0};
	mColor = WHITE;
}

Tail::Tail(Vector2 position, float size, Color color)
{
	mPosition = position;
	mSpeed = { size, 0 };
	mColor = color;
}

Tail::~Tail()
{
}

Vector2 Tail::GetPosition()
{
    return mPosition;
}

Vector2 Tail::GetSpeed()
{
	return mSpeed;
}

Color Tail::GetColor()
{
	return mColor;
}

void Tail::SetPostion(Vector2 position)
{
	mPosition.x = position.x;
	mPosition.y = position.y;
}

void Tail::SetSpeed(Vector2 speed)
{
	mSpeed.x = speed.x;
	mSpeed.y = speed.y;
}

#pragma once
#include "raylib.h"

class SnakeTail
{
private:

	Vector2 mSNPosition;
	Vector2 mSNSpeed;
	Color mSNColor;

public:

	SnakeTail();
	SnakeTail(Vector2 snPosition, float snSize, Color snColor);
	~SnakeTail();

	Vector2 GetSnakeTailPosition();
	Vector2 GetSnakeTailSpeed();
	Color GetSnakeTailColor();

	void SetSnakeTailPostion(Vector2 snPosition);
	void SetSnakeTailSpeed(Vector2 snSpeed);
};


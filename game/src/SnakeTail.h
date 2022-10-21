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

	Vector2 GetPosition();
	Vector2 GetSpeed();
	Color GetColor();

	void SetPostion(Vector2 position);
	void SetSpeed(Vector2 speed);
};


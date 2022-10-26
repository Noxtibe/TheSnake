#pragma once
#include "raylib.h"

class Apples
{
private:

	Vector2 mApplesPositions;
	unsigned short int mApplesScore = 0;
	float mApplesSize;
	bool mActivated = false;
	Color mApplesColor;

public:

	Apples();
	Apples(Vector2 applesPositions, float applesSize, Color applesColor);
	~Apples();

	Vector2 GetApplesPosition();
	unsigned short int GetApplesScore();
	bool GetActivated();
	Color GetApplesColor();

	void Draw();

	void SetApplesPosition(Vector2 applesPositions);
	void SetApplesScore(unsigned short int applesScore);
	void SetActivated(bool activated);
};


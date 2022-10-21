#pragma once
#include "raylib.h"

class Food
{
private:
	Vector2 mPosition;
	int mScore = 0;
	float mSize;
	bool mActivated = false;
	Color mColor;

public:
	Food();
	Food(Vector2 position, float size, Color color);
	~Food();

	Vector2 GetPosition();
	int GetScore();
	bool GetActivated();
	Color GetColor();

	void SetPosition(Vector2 position);
	void SetScore(int score);
	void SetActivated(bool activated);
	void Draw();
};


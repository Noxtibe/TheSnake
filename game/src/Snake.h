#pragma once
#include <string>
#include <vector>
#include "SnakeTail.h"
#include "Grid.h"
#include "Food.h"

class Snake
{
private:
	std::vector<SnakeTail> mSnakeTail;
	std::vector<Vector2> mPosition;
	float mSize;
	Vector2 mSpeed;
	Grid* mpBoard;
	bool mMoving = false;
	bool mLoose = false;

public:
	Snake();
	Snake(Vector2 position, float size, Grid* grid);
	~Snake();

	bool GetLoose();

	void Update(int frames, Food* pFood);
	void SetLoose(bool loose);
	void Draw();
	void Controls();
};


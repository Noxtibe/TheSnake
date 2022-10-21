#pragma once
#include <string>
#include <vector>
#include "SnakeTail.h"
#include "Grid.h"
#include "Apples.h"

using namespace std;

class TheSnake
{
private:

	vector<SnakeTail> mSnakeTail;
	vector<Vector2> mSnakePosition;
	float mSnakeSize;
	Vector2 mSnakeSpeed;
	Grid* mGrid;
	bool mMoving = false;
	bool mFailed = false;

public:

	TheSnake();
	TheSnake(Vector2 snakePosition, float snakeSize, Grid* grid);
	~TheSnake();

	bool GetFailed();

	void Update(int frames, Apples* papples);
	void SetFailed(bool failed);
	void Draw();
	void Controls();
};


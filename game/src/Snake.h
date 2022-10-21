#pragma once
#include <string>
#include <vector>
#include "Tail.h"
#include "Board.h"
#include "Food.h"

class Snake
{
private:
	std::vector<Tail> mTail;
	std::vector<Vector2> mPosition;
	float mSize;
	Vector2 mSpeed;
	Board* mpBoard;
	bool mMoving = false;
	bool mLoose = false;

public:
	Snake();
	Snake(Vector2 position, float size, Board* board);
	~Snake();

	bool GetLoose();

	void Update(int frames, Food* pFood);
	void SetLoose(bool loose);
	void Draw();
	void Controls();
};


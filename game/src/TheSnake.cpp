#include "raylib.h"
#include "TheSnake.h"
#include <iostream>

TheSnake::TheSnake()
{
	mSnakeTail.push_back(SnakeTail());
	mSnakePosition.push_back({ 0, 0 });
	mSnakeSize = 32;
	mSnakeSpeed = { 32, 0 };
	mGrid = nullptr;
}

TheSnake::TheSnake(Vector2 snakePosition, float snakeSize, Grid* grid)
{
	mSnakeTail.push_back(SnakeTail(snakePosition, snakeSize, ORANGE));
	mSnakePosition.push_back(snakePosition);
	mSnakeSize = snakeSize;
	mSnakeSpeed = { snakeSize, 0};
	mGrid = grid;
}

TheSnake::~TheSnake()
{
}

bool TheSnake::GetFailed()
{
	return mFailed;
}

void TheSnake::Update(int frames, Apples* papples)
{
	int randomX = 0;
	int randomY = 0;

	Controls();

	// Movement of the tail
	if (mSnakeTail.size() > mSnakePosition.size())
	{
		mSnakePosition.push_back(mSnakeTail[mSnakeTail.size() - 1].GetSnakeTailPosition());
	}

	for (int i = 0; i < mSnakeTail.size(); i++)
	{
		mSnakePosition[i] = mSnakeTail[i].GetSnakeTailPosition();
	}

	// Frames intervall
	if ((frames % 24) == 0)
	{
		for (int i = 0; i < mSnakeTail.size(); i++)
		{
			if (i == 0)
			{
				mSnakeTail[i].SetSnakeTailPostion({ mSnakeTail[i].GetSnakeTailPosition().x + mSnakeTail[i].GetSnakeTailSpeed().x, mSnakeTail[i].GetSnakeTailPosition().y + mSnakeTail[i].GetSnakeTailSpeed().y });
				mMoving = true;
			}
			else
				mSnakeTail[i].SetSnakeTailPostion(mSnakePosition[i - 1]);
		}
	}

	// Grid limits
	if ((mSnakeTail[0].GetSnakeTailPosition().x < mGrid->GetStartPosition().x) || (mSnakeTail[0].GetSnakeTailPosition().y < mGrid->GetStartPosition().y) || (mSnakeTail[0].GetSnakeTailPosition().x > (mGrid->GetAreaWidth() + mGrid->GetStartPosition().x - mGrid->GetNbColumn())) || (mSnakeTail[0].GetSnakeTailPosition().y >(mGrid->GetAreaHeight() + mGrid->GetStartPosition().y - mGrid->GetNbLine())))
		mFailed = true;

	// Bump with tail
	for (int i = 1; i < mSnakeTail.size(); i++)
	{
		if ((mSnakeTail[0].GetSnakeTailPosition().x == mSnakeTail[i].GetSnakeTailPosition().x) && (mSnakeTail[0].GetSnakeTailPosition().y == mSnakeTail[i].GetSnakeTailPosition().y))
			mFailed = true;
	}


	// Apples spawn
	if (!papples->GetActivated())
	{
		papples->SetActivated(true);

		randomX = GetRandomValue(0, (mGrid->GetAreaWidth() / mSnakeSize) - 1) * mSnakeSize + (mGrid->GetNbColumn() / 2) + mGrid->GetStartPosition().x;
		randomY = GetRandomValue(0, (mGrid->GetAreaHeight() / mSnakeSize) - 1) * mSnakeSize + (mGrid->GetNbLine() / 2) + mGrid->GetStartPosition().y;
		papples->SetApplesPosition({ (float)randomX, (float)randomY });

		for (int i = 0; i < mSnakeTail.size(); i++)
		{
			while ((papples->GetApplesPosition().x == mSnakeTail[i].GetSnakeTailPosition().x) && (papples->GetApplesPosition().y == mSnakeTail[i].GetSnakeTailPosition().y))
			{
				randomX = GetRandomValue(0, (mGrid->GetAreaWidth() / mSnakeSize) - 1) * mSnakeSize + (mGrid->GetNbColumn() / 2) + mGrid->GetStartPosition().x;
				randomY = GetRandomValue(0, (mGrid->GetAreaHeight() / mSnakeSize) - 1) * mSnakeSize + (mGrid->GetNbLine() / 2) + mGrid->GetStartPosition().y;
				papples->SetApplesPosition({ (float)randomX, (float)randomY });
				i = 0;
			}
		}
	}

	// Apples gnom !
	if ((mSnakeTail[0].GetSnakeTailPosition().x < (papples->GetApplesPosition().x + mSnakeSize) && (mSnakeTail[0].GetSnakeTailPosition().x + mSnakeSize) > papples->GetApplesPosition().x) && (mSnakeTail[0].GetSnakeTailPosition().y < (papples->GetApplesPosition().y + mSnakeSize) && (mSnakeTail[0].GetSnakeTailPosition().y + mSnakeSize) > papples->GetApplesPosition().y))
	{
		mSnakeTail.push_back(SnakeTail(mSnakePosition[mSnakePosition.size()-1], mSnakeSize, ORANGE));
		papples->SetActivated(false);
		papples->SetApplesScore(papples->GetApplesScore() + 1);
	}
}

void TheSnake::SetFailed(bool failed)
{
	mFailed = failed;
}

void TheSnake::Draw()
{
	for (int i = 0; i < mSnakeTail.size(); i++)
	{
		DrawRectangleV(mSnakeTail[i].GetSnakeTailPosition(), {mSnakeSize, mSnakeSize}, mSnakeTail[i].GetSnakeTailColor());
	}
}

void TheSnake::Controls()
{
	if (IsKeyPressed(KEY_LEFT) && mSnakeTail[0].GetSnakeTailSpeed().x == 0 && mMoving)
	{
		mSnakeTail[0].SetSnakeTailSpeed({ -mSnakeSize, 0 });
		mMoving = false;
	}
	if (IsKeyPressed(KEY_RIGHT) && mSnakeTail[0].GetSnakeTailSpeed().x == 0 && mMoving)
	{
		mSnakeTail[0].SetSnakeTailSpeed({ mSnakeSize, 0 });
		mMoving = false;
	}
	if (IsKeyPressed(KEY_UP) && mSnakeTail[0].GetSnakeTailSpeed().y == 0 && mMoving)
	{
		mSnakeTail[0].SetSnakeTailSpeed({ 0, -mSnakeSize });
		mMoving = false;
	}
	if (IsKeyPressed(KEY_DOWN) && mSnakeTail[0].GetSnakeTailSpeed().y == 0 && mMoving)
	{
		mSnakeTail[0].SetSnakeTailSpeed({ 0, mSnakeSize });
		mMoving = false;
	}
}

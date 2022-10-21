#include "raylib.h"
#include "Snake.h"
#include <iostream>

Snake::Snake()
{
	mTail.push_back(Tail());
	mPosition.push_back({ 0, 0 });
	mSize = 32;
	mSpeed = { 32, 0 };
	mpBoard = nullptr;
}

Snake::Snake(Vector2 position, float size, Board* board)
{
	mTail.push_back(Tail(position, size, GREEN));
	mPosition.push_back(position);
	mSize = size;
	mSpeed = { size, 0};
	mpBoard = board;
}

Snake::~Snake()
{
}

bool Snake::GetLoose()
{
	return mLoose;
}

void Snake::Update(int frames, Food* pFood)
{
	int randomX = 0;
	int randomY = 0;

	Controls();

	// Movement
	if (mTail.size() > mPosition.size())
	{
		mPosition.push_back(mTail[mTail.size() - 1].GetPosition());
	}

	for (int i = 0; i < mTail.size(); i++)
	{
		mPosition[i] = mTail[i].GetPosition();
	}

	if ((frames % 24) == 0)
	{
		for (int i = 0; i < mTail.size(); i++)
		{
			if (i == 0)
			{
				mTail[i].SetPostion({ mTail[i].GetPosition().x + mTail[i].GetSpeed().x, mTail[i].GetPosition().y + mTail[i].GetSpeed().y });
				mMoving = true;
			}
			else
				mTail[i].SetPostion(mPosition[i - 1]);
		}
	}

	// Board limitation
	if ((mTail[0].GetPosition().x < mpBoard->GetStartingArea().x) || (mTail[0].GetPosition().y < mpBoard->GetStartingArea().y) || (mTail[0].GetPosition().x > (mpBoard->GetAreaWidth() + mpBoard->GetStartingArea().x - mpBoard->GetNbColumn())) || (mTail[0].GetPosition().y >(mpBoard->GetAreaHeight() + mpBoard->GetStartingArea().y - mpBoard->GetNbLine())))
		mLoose = true;

	// Bites its tail
	for (int i = 1; i < mTail.size(); i++)
	{
		if ((mTail[0].GetPosition().x == mTail[i].GetPosition().x) && (mTail[0].GetPosition().y == mTail[i].GetPosition().y))
			mLoose = true;
	}


	// Food apearance
	if (!pFood->GetActivated())
	{
		pFood->SetActivated(true);

		randomX = GetRandomValue(0, (mpBoard->GetAreaWidth() / mSize) - 1) * mSize + (mpBoard->GetNbColumn() / 2) + mpBoard->GetStartingArea().x;
		randomY = GetRandomValue(0, (mpBoard->GetAreaHeight() / mSize) - 1) * mSize + (mpBoard->GetNbLine() / 2) + mpBoard->GetStartingArea().y;
		pFood->SetPosition({ (float)randomX, (float)randomY });

		for (int i = 0; i < mTail.size(); i++)
		{
			while ((pFood->GetPosition().x == mTail[i].GetPosition().x) && (pFood->GetPosition().y == mTail[i].GetPosition().y))
			{
				randomX = GetRandomValue(0, (mpBoard->GetAreaWidth() / mSize) - 1) * mSize + (mpBoard->GetNbColumn() / 2) + mpBoard->GetStartingArea().x;
				randomY = GetRandomValue(0, (mpBoard->GetAreaHeight() / mSize) - 1) * mSize + (mpBoard->GetNbLine() / 2) + mpBoard->GetStartingArea().y;
				pFood->SetPosition({ (float)randomX, (float)randomY });
				i = 0;
			}
		}
	}

	// Food eat
	if ((mTail[0].GetPosition().x < (pFood->GetPosition().x + mSize) && (mTail[0].GetPosition().x + mSize) > pFood->GetPosition().x) && (mTail[0].GetPosition().y < (pFood->GetPosition().y + mSize) && (mTail[0].GetPosition().y + mSize) > pFood->GetPosition().y))
	{
		mTail.push_back(Tail(mPosition[mPosition.size()-1], mSize, DARKGREEN));
		pFood->SetActivated(false);
		pFood->SetScore(pFood->GetScore() + 1);
	}
}

void Snake::SetLoose(bool loose)
{
	mLoose = loose;
}

void Snake::Draw()
{
	for (int i = 0; i < mTail.size(); i++)
	{
		DrawRectangleV(mTail[i].GetPosition(), {mSize, mSize}, mTail[i].GetColor());
	}
}

void Snake::Controls()
{
	if (IsKeyPressed(KEY_LEFT) && mTail[0].GetSpeed().x == 0 && mMoving)
	{
		mTail[0].SetSpeed({ -mSize, 0 });
		mMoving = false;
	}
	if (IsKeyPressed(KEY_RIGHT) && mTail[0].GetSpeed().x == 0 && mMoving)
	{
		mTail[0].SetSpeed({ mSize, 0 });
		mMoving = false;
	}
	if (IsKeyPressed(KEY_UP) && mTail[0].GetSpeed().y == 0 && mMoving)
	{
		mTail[0].SetSpeed({ 0, -mSize });
		mMoving = false;
	}
	if (IsKeyPressed(KEY_DOWN) && mTail[0].GetSpeed().y == 0 && mMoving)
	{
		mTail[0].SetSpeed({ 0, mSize });
		mMoving = false;
	}
}

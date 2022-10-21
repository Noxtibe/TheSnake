#include "raylib.h"
#include <string>
#include <iostream>
#include <vector>
#include "TheSnake.h"
#include "Grid.h"


using namespace std;

void Update();
void Draw();
void InitializeGame();

const int screenWidth = 800;
const int screenHeight = 480;
const int pixelSize = 31;
const Vector2 startPosition = { 250, 250 };
unsigned int frames = 0;
unsigned int scoreToBeat = 0;

TheSnake cobra;
Apples apples;
Grid grid;


int main(int argc, char* argv[])
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "cobra Game");
    SetTargetFPS(60);  

    cobra.SetFailed(true);

    // Main game loop
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();

    return 0;
}

void Update()
{
    if (!cobra.GetFailed())
    {
        cobra.Update(frames, &apples);
        frames++;
    }
    else
    {
        if (apples.GetApplesScore() > scoreToBeat)
            scoreToBeat = apples.GetApplesScore();
        if (IsKeyPressed(KEY_ENTER))
        {
            frames = 0;
            InitializeGame();
        }
    }
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);
    
    if (!cobra.GetFailed())
    {
        cobra.Draw();
        apples.Draw();
        grid.Draw();
        //DrawText(FormatText("BEST: %i", scoreToBeat), pixelSize, pixelSize*3, 25, YELLOW);
    }
    else
    {
        DrawText("Press ENTER for new game", GetScreenWidth() / 2 - MeasureText("Press ENTER for new game", 25) / 2, GetScreenHeight() / 2 - 50, 25, GRAY);
        if (scoreToBeat != 0) 
        {
            //DrawText(FormatText("BEST SCORE: %i", scoreToBeat), GetScreenWidth() / 2 - MeasureText(FormatText("BEST SCORE : %i", scoreToBeat), 25) / 2, GetScreenHeight() * 0.6f, 25, YELLOW);
            //DrawText(FormatText("Score: %i", apple.GetScore()), GetScreenWidth() / 2 - MeasureText(FormatText("Score : %i", apple.GetScore()), 20) / 2, GetScreenHeight() * 0.5f, 20, GRAY);
        }
    }

    EndDrawing();
}

void InitializeGame()
{
    grid = Grid(screenWidth / 2, screenHeight - 100, pixelSize, startPosition);
    cobra = cobra({ (float)(grid.GetAreaWidth() / 2) + startPosition.x, (float)(grid.GetAreaHeight() / 2) + startPosition.y}, pixelSize, &grid);
    apples = apples({ (float)(grid.GetNbColumn() / 2) + startPosition.x, (float)(grid.GetNbLine() / 2) + startPosition.y }, pixelSize, RED);
}
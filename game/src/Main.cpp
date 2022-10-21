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

const int screenWidth = 1280;
const int screenHeight = 720;
const int pixelSize = 31;
const Vector2 startPosition = { 250, 50 };
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

    ClearBackground(WHITE);
    
    if (!cobra.GetFailed())
    {
        cobra.Draw();
        apples.Draw();
        grid.Draw();
        DrawText(TextFormat("Beat: %i", scoreToBeat), pixelSize, pixelSize*3, 25, RED);
    }
    else
    {
        DrawText("Press ENTER to discover... TheSnake", GetScreenWidth() / 2 - MeasureText("Press ENTER to discover... The Snake", 25) / 2, GetScreenHeight() / 2 - 50, 25, RED);
        if (scoreToBeat != 0) 
        {
            // TEXT FORMAT NOT FORMAT TEXT....
            DrawText(TextFormat("Score to Beat: %i", scoreToBeat), GetScreenWidth() / 2 - MeasureText(TextFormat("Score to Beat : %i", scoreToBeat), 25) / 2, GetScreenHeight() * 0.6f, 25, RED);
            DrawText(TextFormat("Score: %i", apples.GetApplesScore()), GetScreenWidth() / 2 - MeasureText(TextFormat("Score : %i", apples.GetApplesScore()), 20) / 2, GetScreenHeight() * 0.5f, 20, RED);
        }
    }

    EndDrawing();
}

void InitializeGame()
{
    grid = Grid(screenWidth / 2, screenHeight - 100, pixelSize, startPosition);
    cobra = TheSnake({ (float)(grid.GetAreaWidth() / 2) + startPosition.x, (float)(grid.GetAreaHeight() / 2) + startPosition.y}, pixelSize, &grid);
    apples = Apples({ (float)(grid.GetNbColumn() / 2) + startPosition.x, (float)(grid.GetNbLine() / 2) + startPosition.y }, pixelSize, RED);
}
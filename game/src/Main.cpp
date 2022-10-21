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
const int squareSize = 31;
const Vector2 startingArea = { 250, 250 };
unsigned int frames = 0;
unsigned int scoreToBeat = 0;

TheSnake cobra;
Apples apple;
Board board;


int main(int argc, char* argv[])
{
    // Initialization
    InitWindow(screenWidth, screenHeight, "cobra Game");
    SetTargetFPS(60);  

    cobra.SetLoose(true);

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
    if (!cobra.GetLoose())
    {
        cobra.Update(frames, &apple);
        frames++;
    }
    else
    {
        if (apple.GetScore() > scoreToBeat)
            scoreToBeat = apple.GetScore();
        if (IsKeyPressed(KEY_ENTER))
        {
            frames = 0;
            InitGame();
        }
    }
}

void Draw()
{
    BeginDrawing();

    ClearBackground(BLACK);
    
    if (!cobra.GetLoose())
    {
        cobra.Draw();
        apple.Draw();
        board.Draw();
        //DrawText(FormatText("BEST: %i", scoreToBeat), squareSize, squareSize*3, 25, YELLOW);
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

void InitGame()
{
    board = Board(screenWidth / 2, screenHeight - 100, squareSize, startingArea);
    cobra = cobra({ (float)(board.GetAreaWidth() / 2) + startingArea.x, (float)(board.GetAreaHeight() / 2) + startingArea.y}, squareSize, &board);
    apple = apple({ (float)(board.GetNbColumn() / 2) + startingArea.x, (float)(board.GetNbLine() / 2) + startingArea.y }, squareSize, RED);
}
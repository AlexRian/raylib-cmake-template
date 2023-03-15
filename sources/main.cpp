#include <stdio.h>
#include "raylib.h"
#include "./engine/debug.hpp"
#include "./engine/physics.hpp"
#include "./entities.hpp"

int main(void)
{
    InitWindow(Settings::screenWidth, Settings::screenHeight, "Game");
    SetTargetFPS(60);

    Debug debug{ 0, 0, false };
    Physics physics{ b2Vec2{0.f, 9.8f} };

    Box box{ 
        Settings::screenWidth / 2, 200, 30, 
        physics.getBody(Settings::screenWidth / 2, 200.0f, 120, 60, true, {.5f, 0.3f, 0.5f}) 
    };

    Ground ground{ 
        Settings::screenWidth / 2, Settings::screenHeight, 180,
        physics.getBody(Settings::screenWidth / 2, Settings::screenHeight, Settings::screenWidth, 60, false, {0.1f, 0.1f, 0.1f})
    };

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_UP)) box.applyForce(b2Vec2{ 0.0f, -500.0f });
        if (IsKeyDown(KEY_LEFT)) box.applyForce(b2Vec2{ -100.0f, 0.0f });
        if (IsKeyDown(KEY_RIGHT)) box.applyForce(b2Vec2{ 100.0f, 0.0f });

        physics.makeWorldStep();

        box.applyPhysicsPosition();
        ground.applyPhysicsPosition();

        BeginDrawing();
            ClearBackground(RAYWHITE);
            box.draw();
            ground.draw();
            debug.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
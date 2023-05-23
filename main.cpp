#include <pendulum.cpp>

int main()
{
    int S_HEIGHT = 720;
    int S_WIDTH = 800;
    InitWindow(S_HEIGHT, S_WIDTH, "Pendulum bitch");

    SetTargetFPS(50);
    Pendulum p{100.0f , 40};
    Pendulum p1(500.0f , 500);
    Pendulum p2(300.0f , 200);

    while (!WindowShouldClose())
    {
        ClearBackground(BLACK);
        BeginDrawing();
        p.DrawPendulum();
        p1.DrawPendulum();
        p2.DrawPendulum();
        EndDrawing();
    }
    return 0;
}

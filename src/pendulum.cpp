#include <cmath>
#include <iostream>
#include <raylib.h>
class Pendulum
{
private:
    float angle = PI / 4;
    float force;
    float g = 9.8;
    float angleV = 0;     // angular velocity
    float angleA = 0.001; // angular acceleration

public:
    int len = 600;
    Vector2 bob = {0, 0};
    Vector2 origin = {300, 0};

    Pendulum(float origin_X, int Length)
    {
        origin = {origin_X, 0};
        len = Length;
    }

public:
    void updateMetrics()
    {
        force = (sin(angle) * g) / len;
        angleA = -1 * force;
        angleV += angleA;
        angle += angleV;
        bob.x = len * sin(angle) + origin.x;
        bob.y = len * cos(angle) + origin.y;
        // std::cout << "angle:" << angle << std::endl
        //           << "angleV: " << angleV << std::endl;
    }
    void DrawPendulum()
    {
        updateMetrics();
        DrawLine(origin.x, origin.y, bob.x, bob.y, WHITE);
        DrawCircle(bob.x, bob.y, 10, WHITE);
    }
};

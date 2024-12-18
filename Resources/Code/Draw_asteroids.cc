#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "esat\window.h"
#include "esat\draw.h"
#include "esat\input.h"
#include "esat\time.h"
#include "esat\math.h"



void InitPointsAsteroids(){
    asteroid1_points = (esat::Vec2*)malloc(knPoints_asteroid1 * sizeof(esat::Vec2));
    asteroid2_points = (esat::Vec2*)malloc(knPoints_asteroid2 * sizeof(esat::Vec2));
    asteroid3_points = (esat::Vec2*)malloc(knPoints_asteroid3 * sizeof(esat::Vec2));
    asteroid4_points = (esat::Vec2*)malloc(knPoints_asteroid4 * sizeof(esat::Vec2));


    //Puntos asteroide 1
    *(asteroid1_points + 0) = {0.0f, 2.0f/9.0f};
    *(asteroid1_points + 1) = {1.0f/9.0f, 4.0f/9.0f};
    *(asteroid1_points + 2) = {0.0f, 6.0f/9.0f};
    *(asteroid1_points + 3) = {2.0f/9.0f, 8.0f/9.0f};
    *(asteroid1_points + 4) = {3.0f/9.0f, 7.0f/9.0f};
    *(asteroid1_points + 5) = {6.0f/9.0f, 8.0f/9.0f};
    *(asteroid1_points + 6) = {9.0f/9.0f, 4.0f/9.0f};
    *(asteroid1_points + 7) = {7.0f/9.0f, 2.0f/9.0f};
    *(asteroid1_points + 8) = {9.0f/9.0f, 1.0f/9.0f};
    *(asteroid1_points + 9) = {7.0f/9.0f, 0.0f};
    *(asteroid1_points + 10) = {5.0f/9.0f, 1.0f/9.0f};
    *(asteroid1_points + 11) = {3.0f/9.0f, 0.0f};
    *(asteroid1_points + 12) = {0.0f, 2.0f/9.0f};
    //puntos asteroide 2
    *(asteroid2_points + 0) = {3.0f/11.0f, 0.0f};
    *(asteroid2_points + 1) = {6.0f/11.0f, 0.0f};
    *(asteroid2_points + 2) = {9.0f/11.0f, 3.0f/11.0f};
    *(asteroid2_points + 3) = {9.0f/11.0f, 5.0f/11.0f};
    *(asteroid2_points + 4) = {5.0f/11.0f, 11.0f/11.0f};
    *(asteroid2_points + 5) = {3.0f/11.0f, 11.0f/11.0f};
    *(asteroid2_points + 6) = {4.0f/11.0f, 5.0f/11.0f};
    *(asteroid2_points + 7) = {1.0f/11.0f, 11.0f/11.0f};
    *(asteroid2_points + 8) = {0.0f, 7.0f/11.0f};
    *(asteroid2_points + 9) = {2.0f/11.0f, 5.0f/11.0f};
    *(asteroid2_points + 10) = {0.0f, 4.0f/11.0f};
    *(asteroid2_points + 11) = {3.0f/11.0f, 0.0f};
    //puntos asteroide 3
    *(asteroid3_points + 0) = {4.0f/12.0f, 0.0f};
    *(asteroid3_points + 1) = {6.0f/12.0f, 3.0f/12.0f};
    *(asteroid3_points + 2) = {8.0f/12.0f, 1.0f/12.0f};
    *(asteroid3_points + 3) = {10.0f/12.0f, 3.0f/12.0f};
    *(asteroid3_points + 4) = {9.0f/12.0f, 6.0f/12.0f};
    *(asteroid3_points + 5) = {11.0f/12.0f, 9.0f/12.0f};
    *(asteroid3_points + 6) = {7.0f/12.0f, 12.0f/12.0f};
    *(asteroid3_points + 7) = {2.0f/12.0f, 12.0f/12.0f};
    *(asteroid3_points + 8) = {0.0f, 10.0f/12.0f};
    *(asteroid3_points + 9) = {0.0f, 3.0f/12.0f};
    *(asteroid3_points + 10) = {4.0f/12.0f, 0.0f};
    //puntos asteroide 4
    *(asteroid4_points + 0) = {2.0f/10.0f, 0.0f};
    *(asteroid4_points + 1) = {5.0f/10.0f, 0.0f};
    *(asteroid4_points + 2) = {8.0f/10.0f, 2.0f/10.0f};
    *(asteroid4_points + 3) = {8.0f/10.0f, 3.0f/10.0f};
    *(asteroid4_points + 4) = {5.0f/10.0f, 5.0f/10.0f};
    *(asteroid4_points + 5) = {8.0f/10.0f, 8.0f/10.0f};
    *(asteroid4_points + 6) = {5.0f/10.0f, 10.0f/10.0f};
    *(asteroid4_points + 7) = {4.0f/10.0f, 8.0f/10.0f};
    *(asteroid4_points + 8) = {1.0f/10.0f, 9.0f/10.0f};
    *(asteroid4_points + 9) = {0.0f, 6.0f/10.0f};
    *(asteroid4_points + 10) = {0.0f, 2.0f/10.0f};
    *(asteroid4_points + 11) = {3.0f/10.0f, 2.0f/10.0f};
    *(asteroid4_points + 12) = {2.0f/10.0f, 0.0f};



}

void CleanAsteroids(){
    free(asteroid1_points);
    asteroid1_points = nullptr;
    free(asteroid2_points);
    asteroid2_points = nullptr;
    free(asteroid3_points);
    asteroid3_points = nullptr;
    free(asteroid4_points);
    asteroid4_points = nullptr;
}

void DrawAsteroid1(esat::Mat3 m, int n_points)
{
    esat::Vec2 *tr_points;
    tr_points = (esat::Vec2*)calloc(n_points, sizeof(esat::Vec2));
    for (int i = 0; i < n_points; ++i)
    {
        esat::Vec2 tmp = esat::Mat3TransformVec2(m, asteroid1_points[i]);
        tr_points[i] = {tmp.x, tmp.y};
    }
    esat::DrawSetStrokeColor(255, 255, 255, 255);
    esat::DrawSetFillColor(0, 0, 0, 0);
    esat::DrawSolidPath(&tr_points[0].x, n_points);
    free(tr_points);
    tr_points = nullptr;
}

void DrawAsteroid2(esat::Mat3 m, int n_points)
{
    esat::Vec2 *tr_points;
    tr_points = (esat::Vec2*)calloc(n_points, sizeof(esat::Vec2));
    for (int i = 0; i < n_points; ++i)
    {
        esat::Vec2 tmp = esat::Mat3TransformVec2(m, asteroid2_points[i]);
        tr_points[i] = {tmp.x, tmp.y};
    }
    esat::DrawSetStrokeColor(255, 255, 255, 255);
    esat::DrawSetFillColor(0, 0, 0, 0);
    esat::DrawSolidPath(&tr_points[0].x, n_points);
    free(tr_points);
    tr_points = nullptr;
}

void DrawAsteroid3(esat::Mat3 m, int n_points)
{
    esat::Vec2 *tr_points;
    tr_points = (esat::Vec2*)calloc(n_points, sizeof(esat::Vec2));
    for (int i = 0; i < n_points; ++i)
    {
        esat::Vec2 tmp = esat::Mat3TransformVec2(m, asteroid3_points[i]);
        tr_points[i] = {tmp.x, tmp.y};
    }
    esat::DrawSetStrokeColor(255, 255, 255, 255);
    esat::DrawSetFillColor(0, 0, 0, 0);
    esat::DrawSolidPath(&tr_points[0].x, n_points);
    free(tr_points);
    tr_points = nullptr;
}

void DrawAsteroid4(esat::Mat3 m, int n_points)
{
    esat::Vec2 *tr_points;
    tr_points = (esat::Vec2*)calloc(n_points, sizeof(esat::Vec2));
    for (int i = 0; i < n_points; ++i)
    {
        esat::Vec2 tmp = esat::Mat3TransformVec2(m, asteroid4_points[i]);
        tr_points[i] = {tmp.x, tmp.y};
    }
    esat::DrawSetStrokeColor(255, 255, 255, 255);
    esat::DrawSetFillColor(0, 0, 0, 0);
    esat::DrawSolidPath(&tr_points[0].x, n_points);
    free(tr_points);
    tr_points = nullptr;
}



/* esat::Mat3 UpdateBase(float x, float y)
{
    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(50.0f, 50.0f), m);
    m = esat::Mat3Multiply(esat::Mat3Translate(x, y), m);
    return m;
} */

esat::Mat3 UpdateBase2(float x, float y)
{
    esat::Mat3 m = esat::Mat3Identity();
    m = esat::Mat3Multiply(esat::Mat3Scale(20.0f, 20.0f), m);
    m = esat::Mat3Multiply(esat::Mat3Translate(x, y), m);
    return m;
}

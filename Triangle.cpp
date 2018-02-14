#include "Triangle.h"

Triangle::Triangle(){};

Triangle::Triangle(sf::Vector2f A,sf::Vector2f B, sf::Vector2f C)
{
    a=A;
    b=B;
    c=C;
};

Triangle::~Triangle(){};

bool Triangle::inTriangle(sf::Vector2f d)
{
    float m;
    float lambda;
    float Bx, By, Cx, Cy, Dx, Dy;
    Bx = b.x - a.x; By = b.y - a.y;
    Cx = c.x - a.x; Cy = c.y - a.y;
    Dx = d.x - a.x; Dy = d.y - a.y;
    m = (Dx*By - Bx*Dy) / (Cx*By - Bx*Cy);
    if( (m >= 0) && (m <= 1) )
    {
        lambda = (Dx - m*Cx) / Bx;
        if( (lambda >= 0) and ((m + lambda) <= 1) )
            return true;
    }
    return false;
};
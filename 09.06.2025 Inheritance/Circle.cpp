//
// Created by Student on 09.06.2025.
//

#include "Circle.h"
#include <math.h>

Circle::Circle(string name, float r) : Figure(name)
{
    m_r = r;
}

float Circle::Area() const
{
    return M_PI * m_r * m_r;
}

float Circle::Perimeter() const
{
    return 2 * M_PI * m_r;
}

void Circle::Info() const
{
    cout << "Circle: " << Name() << endl;
    cout << "Radius: " << m_r << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimeter: " << Perimeter() << endl;
}
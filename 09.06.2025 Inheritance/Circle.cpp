//
// Created by Student on 09.06.2025.
//

#include "Circle.h"
#include <math.h>

Circle::Circle(string name, float r) : Figure(name)
{
    m_r = r;

    m_area = 0;
    m_perimeter = 0;
    Calculations();
}

void Circle::Calculations() {
    m_area = M_PI * m_r * m_r;
    m_perimeter = 2 * M_PI * m_r;
}

float Circle::Area() const
{
    return m_area;
}

float Circle::Perimeter() const
{
    return m_perimeter;
}

void Circle::Info() const
{
    cout << "Circle: " << Name() << endl;
    cout << "Radius: " << m_r << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimeter: " << Perimeter() << endl;
}
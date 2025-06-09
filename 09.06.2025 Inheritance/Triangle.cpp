//
// Created by Student on 09.06.2025.
//

#include "Triangle.h"
#include <math.h>

Triangle::Triangle(string name, float a, float b, float c) : Figure(name)
{
    m_a = a;
    m_b = b;
    m_c = c;
}

float Triangle::Area() const
{
    double p, area;
    p = 0.5 * (m_a + m_b + m_c);
    area = sqrt(p*(p-m_a)*(p-m_b)*(p-m_c));
    return area;
}

float Triangle::Perimeter() const
{
    return m_a + m_b + m_c;
}

void Triangle::Info() const
{
    cout << "Triangle: " << Name() << endl;
    cout << "Sides: a = " << m_a << ", b = " << m_b << ", c = " << m_c << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimeter: " << Perimeter() << endl;
}
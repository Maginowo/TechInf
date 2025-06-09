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

    m_area = 0;
    m_perimeter = 0;
    Calculations();
}

void Triangle::Calculations(){
    double p;
    p = 0.5 * (m_a + m_b + m_c);
    m_area = sqrt(p*(p-m_a)*(p-m_b)*(p-m_c));

    m_perimeter = m_a + m_b + m_c;
}

float Triangle::Area() const
{

    return m_area;
}

float Triangle::Perimeter() const
{
    return m_perimeter;
}

void Triangle::Info() const
{
    cout << "Triangle: " << Name() << endl;
    cout << "Sides: a = " << m_a << ", b = " << m_b << ", c = " << m_c << endl;
    cout << "Area: " << Area() << endl;
    cout << "Perimeter: " << Perimeter() << endl;
}
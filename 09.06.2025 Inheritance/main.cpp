#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"


int main()
{
    Rectangle R1("R1", 2.0, 3.0);
    Rectangle R2("R2", 3.0, 4.0);
    Square S1("S1", 5.0);
    Circle C1("C1", 10);
    Triangle T1("T1", 5, 10, 12);
    Triangle T2("T2", 3, 4, 5);

    R1.Info();
    std::cout << std::endl;
    R2.Info();
    std::cout << std::endl;
    C1.Info();
    std::cout << std::endl;
    S1.Info();
    std::cout << std::endl;
    T1.Info();
    std::cout << std::endl;
    T2.Info();

    std::cout << std::endl << "======" << std::endl << "Wykorzystanie wskaznika" << std::endl;
    Figure* pointer_s = &S1;
    Figure* pointer_r = &R1;
    std::cout << std::endl;
    pointer_s->Info();
    std::cout << std::endl;
    pointer_r->Info();

    std::cout << std::endl << "======" << std::endl << "Wykorzystanie referencji" << std::endl;
    Figure& ref_s = S1;
    Figure& ref_r = R1;
    std::cout << std::endl;
    ref_s.Info();
    std::cout << std::endl;
    ref_r.Info();

}
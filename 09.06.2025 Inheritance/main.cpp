#include <iostream>
#include "Figure.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"


int main()
{
    Figure* figureArray[6];

    Rectangle R1("R1", 2.0, 3.0);
    Rectangle R2("R2", 3.0, 4.0);
    Square S1("S1", 5.0);
    Circle C1("C1", 10);
    Triangle T1("T1", 5, 10, 12);
    Triangle T2("T2", 3, 4, 5);

    figureArray[0] = &R1;
    figureArray[1] = &R2;
    figureArray[2] = &S1;
    figureArray[3] = &C1;
    figureArray[4] = &T1;
    figureArray[5] = &T2;

    Figure& figureRef = *figureArray[0];
    for(int i=0; i<6; i++){
        //figureArray[i]->Info(); // Using the array directly

        // Using the reference, from the array anyway tho
        figureRef = *figureArray[i];
        figureRef.Info();

        std::cout << std::endl;
    }

}
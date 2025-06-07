#include <iostream>
#include "Point.h"
#include <random>
using namespace std;

int main()
{
    // defining random generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);


    Point points[10] = {};

    for (int i = 0; i < 10; i++) {
        double randomNumber = dis(gen);
        points[i] = Point("P" + to_string(i+1), randomNumber, randomNumber);
    }

    cout << "There are " << Point::numberOfPoints() << " points."<< endl;

    // Showing all the points
    for (int i = 0; i < 10; i++){
        points[i].show();
    }

    // Looking for the furthest point from the (0, 0)
    const Point* furthestPoint = &points[0];
    for (int i = 0; i < 10; i++) {
        furthestPoint = &furthestPoint->distant(points[i]);
    }
    cout << endl << "Furthest point from (0, 0) is: " << endl;
    furthestPoint->show();

    // Creating new points in the block, which means that the object lifetime will be restricted to only inside the block
    {
        Point p1, p2, p3;
        cout << endl;
        cout << "Now there are " << Point::numberOfPoints() << " points." << endl;
    }
    cout << "Now there are " << Point::numberOfPoints() << " points." << endl;
}
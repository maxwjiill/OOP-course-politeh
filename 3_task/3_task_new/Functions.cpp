#include <iostream>
#include "Functions.h"
using namespace std;



bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22) {
    if (size < 4) {
        return false;
    }

    double k1, k2;

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (i != j)
            {
                p11 = points[i];
                p12 = points[i + 1];
                p21 = points[j];
                p22 = points[(j + 1) % size];

                k1 = (p12.getY() - p11.getY()) / (p12.getX() - p11.getX());
                k2 = (p22.getY() - p21.getY()) / (p22.getX() - p21.getX());

                if (k1 == k2)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

Point getMinCirclePoint(Point* points, int size, int R) {
    Point minCircleCenter;
    int minPointsInside = size + 1;

    for (int i = 0; i < size; ++i) {
        int pointsInside = 0;

        for (int j = 0; j < size; ++j) {
            double distance = sqrt((points[i].getX() - points[j].getX()) * (points[i].getX() - points[j].getX())) +
                (points[i].getY() - points[j].getY()) * (points[i].getY() - points[j].getY());

            if (distance <= R) {
                ++pointsInside;
            }
        }

        if (pointsInside < minPointsInside) {
            minPointsInside = pointsInside;
            minCircleCenter = points[i];
        }
    }

    return minCircleCenter;
}

int getIsoscelesTriangles(Triangle t[], int size, Triangle** selected)
{
    int countIsosceles = 0;

    for (int i = 0; i < size; ++i) {
        if (t[i].isIsosceles())
        {
            ++countIsosceles;
        }
    }

    return countIsosceles;
}

int getIsoscelesTriangles(Triangle* t, int size, Triangle* selected) {
    int countIsosceles = 0;

    for (int i = 0; i < size; ++i) {
        if (t[i].isIsosceles())
        {
            ++countIsosceles;
        }
    }

    return countIsosceles;
}

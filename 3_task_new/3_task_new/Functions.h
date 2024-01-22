#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Point.h"
#include "Triangle.h"

bool getParallelLines(Point* points, int size, Point& p11, Point& p12, Point& p21, Point& p22);

Point getMinCirclePoint(Point* points, int size, int R);

int getIsoscelesTriangles(Triangle t[], int size, Triangle** selected);

#endif

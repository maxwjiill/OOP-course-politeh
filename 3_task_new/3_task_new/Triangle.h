#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

class Triangle {
public:
    Triangle();
    Triangle(const Point& a, const Point& b, const Point& c);

    double calculateArea() const;
    double calculatePerimeter() const;
    bool isIsosceles() const;

    const Point& getVertexA() const;
    const Point& getVertexB() const;
    const Point& getVertexC() const;

private:
    Point vertexA;
    Point vertexB;
    Point vertexC;
};

#endif

#include "Triangle.h"
#include <cmath>

double distance(const Point& p1, const Point& p2) {
    return hypot(p1.getX() - p2.getX(), p1.getY() - p2.getY());
}

Triangle::Triangle() {}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : vertexA(a), vertexB(b), vertexC(c) {}

double Triangle::calculateArea() const {
    double sideAB = distance(vertexA, vertexB);
    double sideBC = distance(vertexB, vertexC);
    double sideCA = distance(vertexC, vertexA);

    double s = (sideAB + sideBC + sideCA) / 2.0;

    return sqrt(s * (s - sideAB) * (s - sideBC) * (s - sideCA));
}

bool Triangle::isIsosceles() const {
    double sideAB = distance(vertexA, vertexB);
    double sideBC = distance(vertexB, vertexC);
    double sideCA = distance(vertexC, vertexA);

    return sideAB == sideBC || sideAB == sideCA || sideBC == sideCA;
}

double Triangle::calculatePerimeter() const {
    double sideAB = distance(vertexA, vertexB);
    double sideBC = distance(vertexB, vertexC);
    double sideCA = distance(vertexC, vertexA);

    return sideAB + sideBC + sideCA;
}

const Point& Triangle::getVertexA() const {
    return vertexA;
}

const Point& Triangle::getVertexB() const {
    return vertexB;
}

const Point& Triangle::getVertexC() const {
    return vertexC;
}

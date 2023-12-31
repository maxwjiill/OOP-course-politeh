//g++ main.cpp -o 3_task
//Metelkin Maksim -> intV = (int('M') +int('M')) % 12 -> 10 variant "Point, Triangle (L4, P4, T2)"

#include "Functions.h"
#include <iostream>
using namespace std;

int main()
{
    int choice;
    
    do {
        std::cout << "\n\n1. getParallelLines\n";
        std::cout << "2. getMinCirclePoint\n";
        std::cout << "3. getIsoscelesTriangles\n";
        std::cout << "4. exit\n";
        std::cout << "ur choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int size;
                std::cout << "enter massive size: ";
                std::cin >> size;

                Point* points = new Point[size];
                Point p11, p12, p21, p22;

                for (int i = 0; i < size; ++i) {
                    double x, y;
                    std::cout << "coordinates of " << i+1 << " points separated by a space (x y): ";
                    std::cin >> x >> y;
               
                    points[i].setX(x);
                    points[i].setY(y);
                }

                if (getParallelLines(points, size, p11, p12, p21, p22)) {
                    cout << ">>> straight lines are parallel!\n" 
                    << "p11.x=" << p11.getX() << " p11.y=" << p11.getY() << "\n"
                    << "p12.x=" << p12.getX() << " p12.y=" << p12.getY() << "\n"
                    << "p21.x=" << p21.getX() << " p21.y=" << p21.getY() << "\n"
                    << "p22.x=" << p22.getX() << " p22.y=" << p22.getY() << endl;
                } else {
                    cout << ">>> straight lines are not parallel!" << endl;
                }

                delete[] points;

                break;
            }
            case 2: {
                int size, R;
                std::cout << "enter massive size: ";
                std::cin >> size;
                std::cout << "enter R: ";
                std::cin >> R;

                Point* points = new Point[size];
                Point p;
                for (int i = 0; i < size; ++i) {
                    double x, y;
                    std::cout << "coordinates of " << i+1 << " points separated by a space (x y): ";
                    std::cin >> x >> y;
               
                    points[i].setX(x);
                    points[i].setY(y);
                }

                p = getMinCirclePoint(points, size, R);
                std::cout << ">>> a point with x = " << p.getX() << " and y = " <<p.getY() << " is a point that contains the minimum number of points of a given set" << endl;
                
                delete[] points;
                break;
            }
            case 3: {
                int size, R;
                std::cout << "enter massive size: ";
                std::cin >> size;

                Triangle* triangle = new Triangle[size];

                for (int i = 0; i < size; ++i) {
                    double x1, y1, x2, y2, x3, y3;
                    std::cout << "enter coordinates of vertices for triangle " << i + 1 << " separated by spaces (x1 y1 x2 y2 x3 y3): ";
                    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

                    Point vertexA(x1, y1);
                    Point vertexB(x2, y2);
                    Point vertexC(x3, y3);

                    triangle[i] = Triangle(vertexA, vertexB, vertexC);
                }

                Triangle* selectedTriangles;
                int countIsosceles = getIsoscelesTriangles(triangle, size, &selectedTriangles);

                std::cout << "number of isosceles triangles: " << countIsosceles << std::endl;

                delete[] triangle;
                delete[] selectedTriangles;
                break;
            }
            case 4: {
                std::cout << "exiting the program.\n";
                break;
            }
            default: {
                cout << "\ninvalid character: " << choice << endl;
                break;
            }
        }
    } while (choice != 4);
    
    return 0;
}

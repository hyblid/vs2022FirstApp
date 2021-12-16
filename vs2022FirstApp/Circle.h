#ifndef HOWARD_CIRCLE_H
#define HOWARD_CIRCLE_H
#include <iostream>

using namespace std;
class Circle {
private:
    const double PI = 3.14;
    double radius;

public:
    Circle(double radius =0) {
        this->radius = radius;
    }
    double get_radius() const {
        return this->radius;
    }
    void set_radius(double r) {
        this->radius = r;
    }

    double getDiameter() {
        return 2 * radius;
    }

    double getCircumference() {
        return getDiameter() * PI;
    }

    double getArea() {
        double area = PI * pow(radius, 2.0);
        return round(area * 10) / 10;
    }
};


#endif // MURACH_DIE_H
#include "circle.hpp"
#include <iostream>
#include <numbers>
#include <cmath>
using namespace std;
Circle::Circle(Point center, std::string name, int radius) : Shape(center, name), radius(radius) {}
double Circle::area() const {
    return radius * radius *  M_PI;
}
void Circle::draw(std::ostream& out) const {
    for (int y = -radius; y <= radius; y+=2) {
        for (int x =  -radius; x<= radius; ++x) {
            out << (x*x+y*y <= radius * radius ? '*': ' ');
        }
        out << '\n';
    }
}
Circle* Circle::clone() const {
    return new Circle(*this);
}

#include "PointShape.h"
#include <iostream>

PointShape::PointShape(double x_, double y_) : x(x_), y(y_) {}

void PointShape::draw() {
    std::cout << "Drawing Point(" << x << ", " << y << ")\n";
}

std::string PointShape::info() {
    return "ShapeType: POINT";
}

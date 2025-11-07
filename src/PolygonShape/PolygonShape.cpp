#include "PolygonShape.h"
#include <iostream>
#include <sstream>

PolygonShape::PolygonShape(const std::vector<std::pair<double, double>>& pts)
    : points(pts) {}

void PolygonShape::draw() {
    std::cout << "Drawing Polygon with " << points.size() << " points:\n";
    for (const auto& p : points) {
        std::cout << "  (" << p.first << ", " << p.second << ")\n";
    }
}

std::string PolygonShape::info() {
    return "ShapeType: POLYGON";
}

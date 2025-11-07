#include "PolygonShape.h"
#include <iostream>
#include <sstream>

PolygonShape::PolygonShape(double min_x, double min_y, double max_x, double maxY,
                           uint32_t n_parts, uint32_t n_points,
                           std::vector<std::pair<double, double>>& pts,
                           std::vector<uint32_t>& prts)
    : minX(min_x),
      minY(min_y),
      maxX(max_x),
      maxY(maxY),
      numParts(n_parts),
      numPoints(n_points),
      points(pts),
      parts(prts)
{
    // Optional: body can be empty
}

void PolygonShape::draw() {
    std::cout << "Drawing Polygon with " << points.size() << " points:\n";
    for (const auto& p : points) {
        std::cout << "  (" << p.first << ", " << p.second << ")\n";
    }
}

std::string PolygonShape::info() {
    return "ShapeType: POLYGON";
}

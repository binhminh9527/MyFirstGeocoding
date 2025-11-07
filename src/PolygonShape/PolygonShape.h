#ifndef POLYGON_SHAPE_H
#define POLYGON_SHAPE_H

#include "IShape.h"
#include <vector>
#include <utility>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <cstdint>

class PolygonShape : public IShape {
private:
    const ShapeType shapeType = ShapeType::POLYGON;
    
    double minX, minY, maxX, maxY;
    uint32_t numParts;
    uint32_t numPoints;
    std::vector<std::pair<double, double>> points;
    std::vector<uint32_t> parts;


public:

    PolygonShape(double min_x, double min_y, double max_x, double max_y,
                 uint32_t n_parts, uint32_t n_points,
                 std::vector<std::pair<double, double>>& pts,
                 std::vector<uint32_t>& prts);

    void draw() override;
    std::string info() override;
};

#endif // POLYGON_SHAPE_H

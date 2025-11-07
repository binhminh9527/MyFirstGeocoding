#ifndef POLYGON_SHAPE_H
#define POLYGON_SHAPE_H

#include "IShape.h"
#include <vector>
#include <utility> // for std::pair

class PolygonShape : public IShape {
private:
    std::vector<std::pair<double, double>> points;
    const ShapeType shapeType = ShapeType::POLYGON;

public:
    PolygonShape(const std::vector<std::pair<double, double>>& pts);
    void draw() override;
    std::string info() override;
};

#endif // POLYGON_SHAPE_H

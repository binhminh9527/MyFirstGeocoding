#ifndef POINT_SHAPE_H
#define POINT_SHAPE_H

#include "IShape.h"

class PointShape : public IShape {
private:
    double x, y;
    const ShapeType shapeType = ShapeType::POINT;
public:
    PointShape(double x, double y);
    void draw() override;
    std::string info() override;
};

#endif // POINT_SHAPE_H

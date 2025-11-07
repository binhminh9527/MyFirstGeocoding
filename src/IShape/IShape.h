// IShape.h
#ifndef ISHAPE_H
#define ISHAPE_H
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <string>

#ifndef SHAPE_TYPE_H
#define SHAPE_TYPE_H

// Common enumeration for all shape types
enum class ShapeType {
    NULL_SHAPE   = 0,
    POINT        = 1,
    POLYLINE     = 3,
    POLYGON      = 5
    //MULTIPOINT   = 8,
    //POINT_Z      = 11,
    //POLYLINE_Z   = 13,
    //POLYGON_Z    = 15,
    //MULTIPOINT_Z = 18,
    //POINT_M      = 21,
    //POLYLINE_M   = 23,
    //POLYGON_M    = 25,
    //MULTIPOINT_M = 28,
    //MULTIPATCH   = 31
};

#endif // SHAPE_TYPE_H


class IShape {
public:
    IShape();
    virtual ~IShape();
    virtual void draw() = 0;
    virtual std::string info() = 0;
};

#endif // ISHAPE_H
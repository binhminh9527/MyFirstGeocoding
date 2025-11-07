// IShape.h
#ifndef ISHAPE_H
#define ISHAPE_H
#include <cstdio>
#include <cmath>
#include <stdio.h>

class IShape {
public:
    int shapeType;
    virtual ~IShape() = default;
    virtual void draw();
    virtual std::string info()  = 0;
};

#endif // ISHAPE_H
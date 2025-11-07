// Shapefile.h
#ifndef SHAPEFILE_H
#define SHAPEFILE_H

#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <filesystem>
#include "IShape.h"
#include "PointShape.h"
#include "PolygonShape.h"

class Shapefile {
public:
    Shapefile(const std::string& filename);
    ~Shapefile();

    std::vector<IShape*> getShapes() ;


private:
    int shapeType = 0;
    void loadShapefile(const std::string& filename);
    std::vector<IShape*> shapes;
};

#endif // SHAPEFILE_H
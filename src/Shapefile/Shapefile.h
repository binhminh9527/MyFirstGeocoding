// Shapefile.h
#ifndef SHAPEFILE_H
#define SHAPEFILE_H

#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <bit>
#include "IShape.h"
#include "PointShape.h"
#include "PolygonShape.h"

class Shapefile {
public:
    Shapefile(const std::string& filename);
    ~Shapefile();

    std::vector<IShape*> GetAllShapes() ;


private:
    ShapeType m_shapeType = ShapeType::NULL_SHAPE;
    void LoadShapefiles(const std::string& filename);
    ShapeType GetShapeTypefromFile();
    uint32_t GetFileLength();
    void CreateAllShapes();
    std::ifstream m_shp; 
    std::vector<IShape*> shapes;
};

#endif // SHAPEFILE_H
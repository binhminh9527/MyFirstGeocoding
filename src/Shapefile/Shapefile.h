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
    std::vector<IShape*> m_shapes;
    std::ifstream m_shp;
    std::ifstream m_shx;
    std::ifstream m_dbf; 
};

#endif // SHAPEFILE_H
#include "Shapefile.h"
#include <iostream>
#include <vector>
Shapefile::~Shapefile() {
    for (IShape* shape : shapes) {
        delete shape;
    }
}
Shapefile::Shapefile(const std::string& filename)
{
    loadShapefile(filename);
    ShapeType  t_shapeType =  getShapeType();
}

ShapeType Shapefile::getShapeType()
{
    // Placeholder implementation
    if (!m_shp.is_open()) {
        std::cerr << "Shapefile is not open: " << filename << std::endl;
        return;
    }

    m_shp.seekg(32, std::ios::beg);
    ShapeType shapeTypeLE = 0;
    m_shp.read(reinterpret_cast<char*>(&shapeTypeLE), sizeof(shapeTypeLE));

    return shapeTypeLE;
}

void Shapefile::loadShapefile(const std::string& filename) {
    if (!std::filesystem::exists(filename)) {
        std::cerr << "Shapefile not found at: " << filename << "\n";
        std::cerr << "Make sure the file is present in the repository root or update the path in main.cpp" << std::endl;
        return;
    }else {
        std::cout << "Loading shapefile: " << filename << std::endl;
    }
    m_shp.open(filename, std::ios::binary);
    if (!m_shp.is_open()) {
        std::cerr << "Failed to open shapefile: " << filename << std::endl;
        return;
    }
}

std::vector<IShape*> Shapefile::getShapes() {
    std::cout << "Getting shapes from loaded shapefile." << std::endl;
    return std::vector<IShape*>();
}
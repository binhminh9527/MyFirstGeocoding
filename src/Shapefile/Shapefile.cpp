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
};

void Shapefile::loadShapefile(const std::string& filename) {
    if (!std::filesystem::exists(filename)) {
        std::cerr << "Shapefile not found at: " << filename << "\n";
        std::cerr << "Make sure the file is present in the repository root or update the path in main.cpp" << std::endl;
        return;
    }else {
        std::cout << "Loading shapefile: " << filename << std::endl;
    }
}

std::vector<IShape*> Shapefile::getShapes() {
    std::cout << "Getting shapes from loaded shapefile." << std::endl;
    return std::vector<IShape*>();
}
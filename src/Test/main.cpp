#include <iostream>
#include <string>

#include "Shapefile.h"

const std::string shapefile_path = "./Input/test_polygons.shp";

int main() {
    
    Shapefile shapefile(shapefile_path);

    return 0;
}
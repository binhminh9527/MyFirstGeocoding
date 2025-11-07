#include <iostream>
#include <string>

#include "Shapefile.h"

const std::string test_polygon = "./Input/test_polygons";
const std::string test_points = "./Input/test_points";

int main() {
    
    Shapefile shapefile(test_points);

    return 0;
}
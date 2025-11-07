#include <iostream>
#include <string>

#include "Shapefile.h"

const std::string test_polygon = "./Input/test_polygons";
const std::string test_points = "./Input/test_points";

int main() {
    {  
        Shapefile shapefile(test_points);

        std::vector<IShape*> allshapes = shapefile.GetAllShapes() ;
        for (IShape* shape : allshapes) {
            shape->draw();
            std::cout << shape->info() << std::endl;
        }
    }
    std::cout << "________________________________________________________" << std::endl << std::endl;
    
    {  
        Shapefile shapefile(test_polygon);

        std::vector<IShape*> allshapes = shapefile.GetAllShapes() ;
        for (IShape* shape : allshapes) {
            shape->draw();
            std::cout << shape->info() << std::endl;
        }
    }
    return 0;
}
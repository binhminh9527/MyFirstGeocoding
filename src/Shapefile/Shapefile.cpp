#include "Shapefile.h"
#include <iostream>
#include <vector>
#include <Logging.h>

Shapefile::~Shapefile() {
    for (IShape* shape : shapes) {
        delete shape;
    }
}
Shapefile::Shapefile(const std::string& filename)
{
    LoadShapefiles(filename);
    m_shapeType =  GetShapeTypefromFile();
    CreateAllShapes();

}

void Shapefile::CreateAllShapes()
{   
    int count = 0;
    uint32_t  fileLength = GetFileLength();
    m_shp.seekg(100, std::ios::beg); // Move to the end of the header

    while(1)
    {
        IShape* t_shape = nullptr;
        switch (m_shapeType)
        {
        case ShapeType::NULL_SHAPE:
            LOG("Null shape encountered.");
            break;
        case ShapeType::POINT :
        {
            m_shp.seekg(12, std::ios::cur); // Skip record number
            uint32_t contentLength = 16; // 2 doubles = 16 bytes
            
            double x = 0.0;
            m_shp.read(reinterpret_cast<char*>(&x), sizeof(x));
            
            double y = 0.0;
            m_shp.read(reinterpret_cast<char*>(&y), sizeof(y));

            t_shape = new PointShape(x,y);
            shapes.push_back(t_shape);
 
            break;
        }
        case ShapeType::POLYLINE :
            //t_shape = new PolylineShape(m_shp, count);
            //shapes.push_back(t_shape);
            //count++;
            break;
        case ShapeType::POLYGON :
            //t_shape = new PolygonShape(m_shp, count);
            //shapes.push_back(t_shape);
            //count++;
            break;
        default:
            LOG("ShapeType invalid.");
            break;
        }

        
    }
}

uint32_t  Shapefile::GetFileLength(){
    if (!m_shp.is_open()) {
        std::cerr << "Failed to open shapefile: " << std::endl;
        return 0;
    }
    m_shp.seekg(24, std::ios::beg);
    uint32_t big_fileLength = 0;
    m_shp.read(reinterpret_cast<char*>(&big_fileLength), sizeof(big_fileLength));

    return std::byteswap(big_fileLength) * 2;
}

void Shapefile::LoadShapefiles(const std::string& filename) {
    std::string shp_filename = filename + ".shp";
    std::string shx_filename = filename + ".shx";
    std::string dbf_filename = filename + ".dbf";

    if (!std::filesystem::exists(shp_filename)) {
        std::cerr << "Shapefile not found at: " << shp_filename << "\n";
        std::cerr << "Make sure the file is present in the repository root or update the path in main.cpp" << std::endl;
        return;
    }else {
        std::cout << "Loading shapefile: " << shp_filename << std::endl;
    }
    m_shp.open(shp_filename, std::ios::binary);
    if (!m_shp.is_open()) {
        std::cerr << "Failed to open shapefile: " << shp_filename << std::endl;
        return;
    }
}

ShapeType Shapefile::GetShapeTypefromFile()
{
    // Placeholder implementation
    if (!m_shp.is_open()) {
        std::cerr << "Shapefile is not open: " << std::endl;
        return ShapeType::NULL_SHAPE;
    }

    m_shp.seekg(32, std::ios::beg);
    ShapeType shapeTypeLE = ShapeType::NULL_SHAPE;
    m_shp.read(reinterpret_cast<char*>(&shapeTypeLE), sizeof(shapeTypeLE));

    return shapeTypeLE;
}

std::vector<IShape*> Shapefile::GetAllShapes() {
    std::cout << "Getting shapes from loaded shapefile." << std::endl;
    return std::vector<IShape*>();
}
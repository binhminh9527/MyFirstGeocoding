#include "Shapefile.h"
#include <iostream>
#include <vector>
#include <Logging.h>

Shapefile::~Shapefile() {
    for (IShape* shape : m_shapes) {
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

    switch (m_shapeType)
    {
    case ShapeType::NULL_SHAPE:
        LOG("Null shape encountered.");
        break;
    case ShapeType::POINT :
        while(1)
        {
            IShape* t_shape = nullptr;
            m_shp.seekg(12, std::ios::cur); // Skip record number
            
            double x = 0.0;
            m_shp.read(reinterpret_cast<char*>(&x), sizeof(x));
            
            double y = 0.0;
            m_shp.read(reinterpret_cast<char*>(&y), sizeof(y));
            t_shape = new PointShape(x,y);

            m_shapes.push_back(t_shape);
            if (m_shp.tellg() >= static_cast<std::streampos>(fileLength)) {
                break;
            } 
        }
        break;

    case ShapeType::POLYGON :
        while(1)
        {
            IShape* t_shape = nullptr;
            m_shp.seekg(12, std::ios::cur); // Skip record header and 4 bytes of shape type
            
            double xmin = 0.0; m_shp.read(reinterpret_cast<char*>(&xmin), sizeof(xmin));
            double ymin = 0.0; m_shp.read(reinterpret_cast<char*>(&ymin), sizeof(ymin));
            double xmax = 0.0; m_shp.read(reinterpret_cast<char*>(&xmax), sizeof(xmax));
            double ymax = 0.0; m_shp.read(reinterpret_cast<char*>(&ymax), sizeof(ymax));
            
            uint32_t NumParts = 0; m_shp.read(reinterpret_cast<char*>(&NumParts), sizeof(NumParts));
            uint32_t NumPoints = 0; m_shp.read(reinterpret_cast<char*>(&NumPoints), sizeof(NumPoints));

            std::vector<uint32_t> parts(NumParts);
            for (uint32_t i = 0; i < NumParts; ++i) {
                m_shp.read(reinterpret_cast<char*>(&parts[i]), sizeof(uint32_t));
            }
            
            std::vector<std::pair<double, double>> points(NumPoints);
            for (uint32_t i = 0; i < NumPoints; ++i) {
                double x = 0.0; m_shp.read(reinterpret_cast<char*>(&x), sizeof(x));
                double y = 0.0; m_shp.read(reinterpret_cast<char*>(&y), sizeof(y));
                points[i] = std::make_pair(x, y);
            }

            t_shape = new PolygonShape(xmin, ymin, xmax, ymax,
                                       NumParts, NumPoints,
                                       points, parts);
            
            m_shapes.push_back(t_shape);
            if (m_shp.tellg() >= static_cast<std::streampos>(fileLength)) {
                break;
            } 
        }
        break;
    case ShapeType::POLYLINE :
        //t_shape = new PolygonShape(m_shp, count);
        //m_shapes.push_back(t_shape);
        //count++;
        break;
    default:
        LOG("ShapeType invalid.");
        break;
    }
}

uint32_t Shapefile::GetFileLength(){
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

    m_shx.open(shx_filename, std::ios::binary);
    if (!m_shx.is_open()) {
        std::cerr << "Failed to open shapefile: " << shx_filename << std::endl;
        return;
    }

    m_dbf.open(dbf_filename, std::ios::binary);
    if (!m_dbf.is_open()) {
        std::cerr << "Failed to open shapefile: " << dbf_filename << std::endl;
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
    std::cout << "Getting m_shapes from loaded shapefile." << std::endl;
    return m_shapes;
}
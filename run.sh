cd "$(dirname "$0")"
make;
cd Input
python Generate_Point.py
python Generate_Polygons.py
cd ..
./MyFirstGeocoding
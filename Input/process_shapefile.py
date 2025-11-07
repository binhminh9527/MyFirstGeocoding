import shapefile  # pip install pyshp

# Create a writer for polygon shapefile
w = shapefile.Writer("test_polygons.shp", shapeType=shapefile.POLYGON)

# Define one attribute field (optional)
w.field("Name", "C")

# --- Polygon 1 ---
poly1 = [[
    [0, 0],
    [10, 0],
    [10, 10],
    [0, 10],
    [0, 0]
]]
w.poly(poly1)
w.record("Square1")

# --- Polygon 2 ---
poly2 = [[
    [20, 20],
    [25, 20],
    [25, 25],
    [20, 25],
    [20, 20]
]]
w.poly(poly2)
w.record("Square2")

# Save shapefile (creates .shp, .shx, .dbf)
w.close()

print("✅ Created test_polygons.shp (2 polygons)")
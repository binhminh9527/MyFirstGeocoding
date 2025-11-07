import shapefile  # pip install pyshp

# Create a writer for point shapefile
w = shapefile.Writer("test_points.shp", shapeType=shapefile.POINT)

# Define one attribute field (optional)
w.field("Name", "C")

# --- Point 1 ---
w.point(5, 5)
w.record("Point1")

# --- Point 2 ---
w.point(15, 15)
w.record("Point2")

# Save shapefile (creates .shp, .shx, .dbf)
w.close()

print("Created test_points.shp (2 points)")

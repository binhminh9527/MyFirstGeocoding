# MyFirstGeocoding
This repository is for geocoding and handling of shapefiles.

## Project Structure
The project is organized into several directories and files:

- **src/**: Contains the source code for the project.
  - **Shape/**: Contains the interface for shapes.
    - `IShape.h`: Defines the `IShape` interface with methods like `getArea()`, `getPerimeter()`, and `draw()`.
    - `IShape.cpp`: Implementation file for any common functionality related to the `IShape` interface.
  - **Shapefile/**: Handles the reading and processing of shapefiles.
    - `Shapefile.h`: Defines the `Shapefile` class with methods like `LoadShapefiles()`, `getShapes()`, and `saveOutput()`.
    - `Shapefile.cpp`: Contains the implementation of the `Shapefile` class methods.
  - **Test/**: Contains the main entry point for the application.
    - `main.cpp`: The main function that creates instances of the `Shapefile` class and interacts with the `IShape` interface.
  - **Common/**: Contains utility functions.
    - `utils.h`: Declares utility functions for file handling and data processing.
    - `utils.cpp`: Implements the utility functions declared in `utils.h`.

- **Input/**: Contains scripts for processing shapefiles.
  - `process_shapefile.py`: A Python script for reading and converting shapefile data.

- **Output/**: Contains configuration files.
  - `config.cfg`: Configuration file for output settings.

- **include/**: Intended for public headers that can be included in other parts of the project or by external projects.

- **Makefile**: Contains build instructions to compile the source files into object files and link them into a final binary.

- **.gitignore**: Specifies files and directories to be ignored by Git.

## Setup Instructions
1. Clone the repository:
   ```
   git clone <repository-url>
   cd MyFirstGeocoding
   ```

2. Build the project:
   ```
   make
   ```

3. Run the application:
   ```
   ./MyFirstGeocoding
   ```

## Usage
- The application can be used to load shapefiles, process shape data, and output results based on the configuration specified in `Output/config.cfg`.

## Contributing
Feel free to submit issues or pull requests for improvements or bug fixes.
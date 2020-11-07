/**
 * Implements a Zoo namespace with methods for constructing Grid objects containing various creatures in the Game of Life.
 *      - Creatures like gliders, light weight spaceships, and r-pentominos can be spawned.
 *          - These creatures are drawn on a Grid the size of their bounding box.
 *
 *      - Grids can be loaded from and saved to an ascii file format.
 *          - Ascii files are composed of:
 *              - A header line containing an integer width and height separated by a space.
 *              - followed by (height) number of lines, each containing (width) number of characters,
 *                terminated by a newline character.
 *              - (space) ' ' is Cell::DEAD, (hash) '#' is Cell::ALIVE.
 *
 *      - Grids can be loaded from and saved to an binary file format.
 *          - Binary files are composed of:
 *              - a 4 byte int representing the grid width
 *              - a 4 byte int representing the grid height
 *              - followed by (width * height) number of individual bits in C-style row/column format,
 *                padded with zero or more 0 bits.
 *              - a 0 bit should be considered Cell::DEAD, a 1 bit should be considered Cell::ALIVE.
 *
 * @author 964379
 * @date March, 2020
 */
#include "zoo.h"
#include <fstream>
// Include the minimal number of headers needed to support your implementation.
// #include ...

/**
 * Zoo::glider()
 *
 * Construct a 3x3 grid containing a glider.
 * https://www.conwaylife.com/wiki/Glider
 *
 * @example
 *
 *      // Print a glider in a Grid the size of its bounding box.
 *      std::cout << Zoo::glider() << std::endl;
 *
 *      +---+
 *      | # |
 *      |  #|
 *      |###|
 *      +---+
 *
 * @return
 *      Returns a Grid containing a glider.
 */
Grid Zoo::glider() {
	Grid grid(3, 3);
	grid.set(0, 2, Cell::ALIVE);
	grid.set(1, 2, Cell::ALIVE);
	grid.set(2, 2, Cell::ALIVE);
	grid.set(2, 1, Cell::ALIVE);
	grid.set(1, 0, Cell::ALIVE);
	return grid;
}

/**
 * Zoo::r_pentomino()
 *
 * Construct a 3x3 grid containing an r-pentomino.
 * https://www.conwaylife.com/wiki/R-pentomino
 *
 * @example
 *
 *      // Print an r-pentomino in a Grid the size of its bounding box.
 *      std::cout << Zoo::r_pentomino() << std::endl;
 *
 *      +---+
 *      | ##|
 *      |## |
 *      | # |
 *      +---+
 *
 * @return
 *      Returns a Grid containing a r-pentomino.
 */
Grid Zoo::r_pentomino() {
	Grid grid(3, 3);
	grid.set(1, 0, Cell::ALIVE);
	grid.set(2, 0, Cell::ALIVE);
	grid.set(0, 1, Cell::ALIVE);
	grid.set(1, 1, Cell::ALIVE);
	grid.set(1, 2, Cell::ALIVE);
	return grid;
}

/**
 * Zoo::light_weight_spaceship()
 *
 * Construct a 5x4 grid containing a light weight spaceship.
 * https://www.conwaylife.com/wiki/Lightweight_spaceship
 *
 * @example
 *
 *      // Print a light weight spaceship in a Grid the size of its bounding box.
 *      std::cout << Zoo::light_weight_spaceship() << std::endl;
 *
 *      +-----+
 *      | #  #|
 *      |#    |
 *      |#   #|
 *      |#### |
 *      +-----+
 *
 * @return
 *      Returns a grid containing a light weight spaceship.
 */
Grid Zoo::light_weight_spaceship() {
	Grid grid(5, 4);
	grid.set(1, 0, Cell::ALIVE);
	grid.set(4, 0, Cell::ALIVE);
	grid.set(0, 1, Cell::ALIVE);
	grid.set(0, 2, Cell::ALIVE);
	grid.set(4, 2, Cell::ALIVE);
	grid.set(0, 3, Cell::ALIVE);
	grid.set(1, 3, Cell::ALIVE);
	grid.set(2, 3, Cell::ALIVE);
	grid.set(3, 3, Cell::ALIVE);
	return grid;
}

/**
 * Zoo::load_ascii(path)
 *
 * Load an ascii file and parse it as a grid of cells.
 * Should be implemented using std::ifstream.
 *
 * @example
 *
 *      // Load an ascii file from a directory
 *      Grid grid = Zoo::load_ascii("path/to/file.gol");
 *
 * @param path
 *      The std::string path to the file to read in.
 *
 * @return
 *      Returns the parsed grid.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if:
 *          - The file cannot be opened.
 *          - The parsed width or height is not a positive integer.
 *          - Newline characters are not found when expected during parsing.
 *          - The character for a cell is not the ALIVE or DEAD character.
 */
Grid Zoo::load_ascii(std::string path) {
	//Convert path from string to char* to satisfy the constructor of ifstream.
	char *pathChar = const_cast<char*>(path.c_str());
	std::ifstream inFile(pathChar, std::ifstream::in);
	if (!inFile) {
		throw std::runtime_error("Unable to open the specified file.");
	}
	int width, height;
	//Read directly the width and height.
	inFile >> width >> height;
	if (width < 0 || height < 0) {
		throw std::runtime_error(
				"The parsed width or height is not a positive integer.");
	}
	char x;
	//Read the newline character between height and grid.
	inFile.get(x);
	Grid gridReturned(width, height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			inFile.get(x);
			if (x != ' ' && x != '#') {
				throw std::runtime_error(
						"The character for a cell is not the ALIVE or DEAD character.");
			}
			gridReturned.set(j, i, (Cell) x);
		}
		inFile.get(x);
		if (x != '\n') {
			throw std::runtime_error(
					"Newline characters are not found when expected during parsing.");
		}
	}
	//If errors occured.
	if (!inFile.good()) {
		if (inFile.eof()) {
			throw std::runtime_error("File ended unexpectedly.");
		} else {
			throw std::runtime_error("An error occured.");
		}
	}
	inFile.close();
	return gridReturned;
}

/**
 * Zoo::save_ascii(path, grid)
 *
 * Save a grid as an ascii .gol file according to the specified file format.
 * Should be implemented using std::ofstream.
 *
 * @example
 *
 *      // Make an 8x8 grid
 *      Grid grid(8);
 *
 *      // Save a grid to an ascii file in a directory
 *      try {
 *          Zoo::save_ascii("path/to/file.gol", grid);
 *      }
 *      catch (const std::exception &ex) {
 *          std::cerr << ex.what() << std::endl;
 *      }
 *
 * @param path
 *      The std::string path to the file to write to.
 *
 * @param grid
 *      The grid to be written out to file.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if the file cannot be opened.
 */
void Zoo::save_ascii(std::string path, Grid grid) {
	//Convert path from string to char* to satisfy the constructor of ifstream.
	char *pathChar = const_cast<char*>(path.c_str());
	std::ofstream outFile(pathChar, std::ofstream::out);
	if (!outFile) {
		throw std::runtime_error("Unable to open the specified file.");
	}
	outFile << grid.get_width() << ' ' << grid.get_height() << '\n';
	for (int i = 0; i < grid.get_height(); i++) {
		for (int j = 0; j < grid.get_width(); j++) {
			outFile << (char) grid(j, i);
		}
		outFile << '\n';
	}
	outFile.close();
}

/**
 * Zoo::load_binary(path)
 *
 * Load a binary file and parse it as a grid of cells.
 * Should be implemented using std::ifstream.
 *
 * @example
 *
 *      // Load an binary file from a directory
 *      Grid grid = Zoo::load_binary("path/to/file.bgol");
 *
 * @param path
 *      The std::string path to the file to read in.
 *
 * @return
 *      Returns the parsed grid.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if:
 *          - The file cannot be opened.
 *          - The file ends unexpectedly.
 */
Grid Zoo::load_binary(std::string path) {
	//Convert path from string to char* to satisfy the constructor of ifstream.
	char *pathChar = const_cast<char*>(path.c_str());
	std::ifstream inFile(pathChar, std::ifstream::in | std::ifstream::binary);
	if (!inFile) {
		throw std::runtime_error("Unable to open the specified file.");
	}
	int realWidth, realHeight;
	//Read the width and height for the grid as int sized char*.
	//char* is required for the read function.
	inFile.read((char*) &realWidth, sizeof(int));
	inFile.read((char*) &realHeight, sizeof(int));
	//Read byte by byte.
	char buffer[1];
	Grid gridReturned(realWidth, realHeight);
	int column = 0, row = 0;
	//Depending on the size of the matrix read enough bytes to complete the grid.
	for (int k = 0; k < realWidth * realHeight / 8 + 1; k++) {
		//Read a byte.
		inFile.read((char*) buffer, sizeof(char));
		//A byte has 8 bits and the read operation should consider only enough bits
		//to complete the grid.
		for (int i = 0;
				i < 8 && (column <= (realWidth - 1) && row <= (realHeight - 1));
				i++) {
			//Get the bits out of the byte by using shifting and AND on bits operations.
			if (((buffer[0] >> i) & 1) == 1) {
				gridReturned.set(column, row, Cell::ALIVE);
			}
			//Logic to assign the correct cell value in the grid at correct column,row.
			if (column + 1 == realWidth) {
				column = 0;
				row++;
			} else {
				column++;
			}
		}

	}
	//If any error with reading.
	if (!inFile.good()) {
		if (inFile.eof()) {
			throw std::runtime_error("File ended unexpectedly.");
		} else {
			throw std::runtime_error("An error occured.");
		}
	}
	inFile.close();
	return gridReturned;
}

/**
 * Zoo::save_binary(path, grid)
 *
 * Save a grid as an binary .bgol file according to the specified file format.
 * Should be implemented using std::ofstream.
 *
 * @example
 *
 *      // Make an 8x8 grid
 *      Grid grid(8);
 *
 *      // Save a grid to an binary file in a directory
 *      try {
 *          Zoo::save_binary("path/to/file.bgol", grid);
 *      }
 *      catch (const std::exception &ex) {
 *          std::cerr << ex.what() << std::endl;
 *      }
 *
 * @param path
 *      The std::string path to the file to write to.
 *
 * @param grid
 *      The grid to be written out to file.
 *
 * @throws
 *      Throws std::runtime_error or sub-class if the file cannot be opened.
 */
void Zoo::save_binary(std::string path, Grid grid) {
	//Convert path from string to char* to satisfy the constructor of ifstream.
	char *pathChar = const_cast<char*>(path.c_str());
	std::ofstream outFile(pathChar, std::ofstream::out | std::ofstream::binary);
	if (!outFile) {
		throw std::runtime_error("Unable to open the specified file.");
	}
	int realWidth = grid.get_width(), realHeight = grid.get_height();
	//Read the width and height for the grid as int sized char*.
	//char* is required for the read function.
	outFile.write((char*) &realWidth, sizeof(int));
	outFile.write((char*) &realHeight, sizeof(int));
	//Write byte by byte.
	char buffer[1];
	int column = 0, row = 0;
	//Depending on the size of the matrix write enough bytes to complete the grid.
	for (int k = 0; k < realWidth * realHeight / 8 + 1; k++) {
		//A byte has 8 bits and the read operation should consider only enough bits
		//to complete the grid.
		for (int i = 0;
				i < 8 && (column <= (realWidth - 1) && row <= (realHeight - 1));
				i++) {
			//Set the bits in the buffet by using shifting and OR on bits operations.
			if (grid(column, row) == Cell::ALIVE) {
				buffer[0] |= 1 << i;
			} else {
				buffer[0] |= 0 << i;
			}
			//Logic to assign the correct cell value in the grid at correct column,row.
			if (column + 1 == realWidth) {
				column = 0;
				row++;
			} else {
				column++;
			}

		}
		//Write a byte.
		outFile.write((char*) buffer, sizeof(char));
		//Reset the buffer.
		buffer[0] = 0;
	}
	outFile.close();
}

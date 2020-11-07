/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>
#include <fstream>

#include "../grid.h"
#include "../zoo.h"

SCENARIO( "saving a grid as an ascii file throws exceptions on error", "[zoo][save_ascii][exception]" ) {

    auto file_exists = [](const std::string &path) {
        // fstream destructor closes the file
        return std::ifstream(path).is_open();
    };

    GIVEN( "a grid with size 6x6 containing a glider" ) {

        Grid g(6);

        g.set(1, 3, Cell::ALIVE);
        g.set(2, 3, Cell::ALIVE);
        g.set(3, 3, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(2, 1, Cell::ALIVE);

        WHEN("a grid is saved as an ascii file to a valid directory do not throw an exception") {

            REQUIRE_NOTHROW( Zoo::save_ascii("../test_outputs/SAVE_ASCII_GLIDER_NOTHROW.gol", g) );
            REQUIRE(             file_exists("../test_outputs/SAVE_ASCII_GLIDER_NOTHROW.gol") );
        }

        WHEN("a grid is saved as an ascii file to a directory that does not exist throw an exception") {

            REQUIRE_THROWS(Zoo::save_ascii("../test_outputs/DOES_NOT_EXIST/DOES_NOT_EXIST.gol", g));
            REQUIRE(          !file_exists("../test_outputs/DOES_NOT_EXIST/DOES_NOT_EXIST.gol") );
        }
    }

} // SCENARIO



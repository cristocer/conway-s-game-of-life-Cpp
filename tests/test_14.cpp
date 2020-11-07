/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <fstream>
#include <string>

#include "../grid.h"
#include "../zoo.h"

SCENARIO( "a grid can be saved to disc as an ascii file", "[zoo][save_ascii]" ) {

    GIVEN( "a world with size 6x6 containing a glider" ) {

        Grid g(6);

        g.set(1, 3, Cell::ALIVE);
        g.set(2, 3, Cell::ALIVE);
        g.set(3, 3, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(2, 1, Cell::ALIVE);

//        +------+
//        |      |
//        |  #   |
//        |   #  |
//        | ###  |
//        |      |
//        |      |
//        +------+

        WHEN( "the grid is saved to as an ascii file" ) {

            Zoo::save_ascii("../test_outputs/SAVE_ASCII_GLIDER.gol", g);

            THEN("the glider is correctly written into the file") {

                // Expected value of test_glider.gol
                const std::string expected_contents = "6 6\n"
                                                      "      \n"
                                                      "  #   \n"
                                                      "   #  \n"
                                                      " ###  \n"
                                                      "      \n"
                                                      "      \n";

                std::ifstream file("../test_outputs/SAVE_ASCII_GLIDER.gol");
                REQUIRE( file.is_open() );

                // Read the whole file into a string
                const std::string file_contents((std::istreambuf_iterator<char>(file)),
                                            std::istreambuf_iterator<char>());

                REQUIRE( file_contents == expected_contents );
            }
        }

    } // GIVEN

} // SCENARIO
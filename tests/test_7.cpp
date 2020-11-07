/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>
#include <sstream>

#include "../grid.h"

SCENARIO( "grids can be serialized to an ascii ostream", "[grid][ostream]" ) {

    GIVEN( "a grid with size 4x3 containing a glider" ) {

        Grid g(4, 3);

        g.set(1, 2, Cell::ALIVE);
        g.set(2, 2, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(3, 1, Cell::ALIVE);
        g.set(2, 0, Cell::ALIVE);

//        +----+
//        |  # |
//        |   #|
//        | ###|
//        +----+

        REQUIRE(       g.get_width() == 4 );
        REQUIRE(      g.get_height() == 3 );
        REQUIRE( g.get_total_cells() == (4 * 3) );
        REQUIRE( g.get_alive_cells() == 5 );
        REQUIRE(  g.get_dead_cells() == (4 * 3) - 5 );
        REQUIRE( g.get(1, 2) == Cell::ALIVE );
        REQUIRE( g.get(2, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 1) == Cell::ALIVE );
        REQUIRE( g.get(2, 0) == Cell::ALIVE );

        WHEN( "the grid is written to a std::ostream object" ) {

            const std::string expected = "+----+\n"
                                         "|  # |\n"
                                         "|   #|\n"
                                         "| ###|\n"
                                         "+----+\n";

            // Serialize the grid to a string instead of to the console
            std::stringstream stream;
            stream << g;
            const std::string observed = stream.str();

            THEN( "the grid is correctly serialized and is printed with a border" ) {

                REQUIRE( observed == expected );
            }


        }

    } // GIVEN

    GIVEN( "a grid with size 5x4 containing a light weight spaceship" ) {

        Grid g(5, 4);
        g.set(1, 0, Cell::ALIVE);
        g.set(4, 0, Cell::ALIVE);
        g.set(0, 1, Cell::ALIVE);
        g.set(0, 2, Cell::ALIVE);
        g.set(4, 2, Cell::ALIVE);
        g.set(0, 3, Cell::ALIVE);
        g.set(1, 3, Cell::ALIVE);
        g.set(2, 3, Cell::ALIVE);
        g.set(3, 3, Cell::ALIVE);

//        +-----+
//        | #  #|
//        |#    |
//        |#   #|
//        |#### |
//        +-----+

        REQUIRE( g.get_width() == 5 );
        REQUIRE( g.get_height() == 4 );
        REQUIRE( g.get_alive_cells() == 9 );

        REQUIRE( g.get(1, 0) == Cell::ALIVE );
        REQUIRE( g.get(4, 0) == Cell::ALIVE );
        REQUIRE( g.get(0, 1) == Cell::ALIVE );
        REQUIRE( g.get(0, 2) == Cell::ALIVE );
        REQUIRE( g.get(4, 2) == Cell::ALIVE );
        REQUIRE( g.get(0, 3) == Cell::ALIVE );
        REQUIRE( g.get(1, 3) == Cell::ALIVE );
        REQUIRE( g.get(2, 3) == Cell::ALIVE );
        REQUIRE( g.get(3, 3) == Cell::ALIVE );

        WHEN( "the grid is written to a std::ostream object" ) {

            const std::string expected = "+-----+\n"
                                         "| #  #|\n"
                                         "|#    |\n"
                                         "|#   #|\n"
                                         "|#### |\n"
                                         "+-----+\n";

            // Serialize the grid to a string instead of to the console
            std::stringstream stream;
            stream << g;
            const std::string observed = stream.str();

            THEN( "the grid is correctly serialized and is printed with a border" ) {

                REQUIRE( observed == expected );
            }


        }

    } // GIVEN

} // SCENARIO


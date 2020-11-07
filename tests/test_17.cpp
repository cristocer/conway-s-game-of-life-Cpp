/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>

#include "../grid.h"
#include "../zoo.h"

SCENARIO( "from the zoo various known lifeforms can be constructed", "[zoo][lifeforms]" ) {

    GIVEN( "a default constructed grid" ) {

        Grid g;

        REQUIRE(g.get_width() == 0);
        REQUIRE(g.get_height() == 0);
        REQUIRE(g.get_total_cells() == 0);

        WHEN( "a glider is spawned from the zoo" ) {

            g = Zoo::glider();

//            +---+
//            | # |
//            |  #|
//            |###|
//            +---+

            THEN( "the glider is correctly initialized into the upper left corner of a 3x3 grid" ) {

                REQUIRE( g.get_width() == 3 );
                REQUIRE( g.get_height() == 3 );
                REQUIRE( g.get_alive_cells() == 5 );

                REQUIRE( g.get(0, 2) == Cell::ALIVE );
                REQUIRE( g.get(1, 2) == Cell::ALIVE );
                REQUIRE( g.get(2, 2) == Cell::ALIVE );
                REQUIRE( g.get(2, 1) == Cell::ALIVE );
                REQUIRE( g.get(1, 0) == Cell::ALIVE );
            }
        }

        WHEN( "a r-pentomino is spawned from the zoo" ) {

            g = Zoo::r_pentomino();

//            +---+
//            | ##|
//            |## |
//            | # |
//            +---+

            THEN( "the r-pentomino is correctly initialized into the upper left corner of a 3x3 grid" ) {

                REQUIRE( g.get_width() == 3 );
                REQUIRE( g.get_height() == 3 );
                REQUIRE( g.get_alive_cells() == 5 );

                REQUIRE( g.get(1, 0) == Cell::ALIVE );
                REQUIRE( g.get(2, 0) == Cell::ALIVE );
                REQUIRE( g.get(0, 1) == Cell::ALIVE );
                REQUIRE( g.get(1, 1) == Cell::ALIVE );
                REQUIRE( g.get(1, 2) == Cell::ALIVE );
            }
        }

        WHEN( "a light weight spaceship is spawned from the zoo" ) {

            g = Zoo::light_weight_spaceship();

//            +-----+
//            | #  #|
//            |#    |
//            |#   #|
//            |#### |
//            +-----+

            THEN( "the light weight spaceship is correctly initialized into the upper left corner of a 5x4 grid" ) {

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
            }
        }
    } // GIVEN
} // SCENARIO

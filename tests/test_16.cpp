/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>

#include "../grid.h"
#include "../zoo.h"

SCENARIO( "a grid can be saved to disc as a binary file", "[zoo][save_binary]" ) {

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

        WHEN( "the grid is saved as an binary file" ) {

            Zoo::save_binary("../test_outputs/SAVE_BINARY_GLIDER.bgol", g);

            THEN("the glider is correctly written into the file" ) {

                Grid h = Zoo::load_binary("../test_outputs/SAVE_BINARY_GLIDER.bgol");

//                +------+
//                |      |
//                |  #   |
//                |   #  |
//                | ###  |
//                |      |
//                |      |
//                +------+

                REQUIRE( h.get_width()  == 6 );
                REQUIRE( h.get_height() == 6 );
                REQUIRE( h.get_alive_cells() == 5 );

                REQUIRE( h.get(1, 3) == Cell::ALIVE );
                REQUIRE( h.get(2, 3) == Cell::ALIVE );
                REQUIRE( h.get(3, 3) == Cell::ALIVE );
                REQUIRE( h.get(3, 2) == Cell::ALIVE );
                REQUIRE( h.get(2, 1) == Cell::ALIVE );

            }
        }

    } // GIVEN

    GIVEN( "a world with size 6x6 that is fully alive" ) {

        Grid g(6);

        for (int y = 0; y < 6; y++) {
            for (int x = 0; x < 6; x++) {

                g.set(x, y, Cell::ALIVE);
            }
        }

        REQUIRE( g.get_width()  == 6 );
        REQUIRE( g.get_height() == 6 );
        REQUIRE( g.get_alive_cells() == (6 * 6) );

        WHEN( "the grid is saved to as an binary file" ) {

            Zoo::save_binary("../test_outputs/SAVE_BINARY_6x6.bgol", g);

            THEN("the grid is correctly written into the file and can be read back in" ) {

                Grid h = Zoo::load_binary("../test_outputs/SAVE_BINARY_6x6.bgol");

                REQUIRE( h.get_width()  == 6 );
                REQUIRE( h.get_height() == 6 );
                REQUIRE( h.get_alive_cells() == (6 * 6) );
            }
        }

    } // GIVEN

} // SCENARIO
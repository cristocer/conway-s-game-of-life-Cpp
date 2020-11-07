/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>

#include "../grid.h"

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
SCENARIO( "a grid can be accessed using operator() to set and get cell values", "[grid][indexing]" ) {

    GIVEN( "a grid with size 4x3 with all dead cells" ) {

        Grid g(4, 3);

        WHEN( "a glider is placed using operator()" ) {

            g(1, 2) = Cell::ALIVE;
            g(2, 2) = Cell::ALIVE;
            g(3, 2) = Cell::ALIVE;
            g(3, 1) = Cell::ALIVE;
            g(2, 0) = Cell::ALIVE;

//            +----+
//            |  # |
//            |   #|
//            | ###|
//            +----+

            THEN( "the glider is placed as expected" ) {

                REQUIRE(       g.get_width() == 4 );
                REQUIRE(      g.get_height() == 3 );
                REQUIRE( g.get_total_cells() == (4 * 3) );

                REQUIRE( g.get_alive_cells() == 5 );
                REQUIRE( g.get_dead_cells() == (4 * 3) - 5 );
                REQUIRE( g.get(1, 2) == Cell::ALIVE );
                REQUIRE( g.get(2, 2) == Cell::ALIVE );
                REQUIRE( g.get(3, 2) == Cell::ALIVE );
                REQUIRE( g.get(3, 1) == Cell::ALIVE );
                REQUIRE( g.get(2, 0) == Cell::ALIVE );
            }

            THEN( "the glider can be observed using operator()" ) {

                REQUIRE( g(1, 2) == Cell::ALIVE );
                REQUIRE( g(2, 2) == Cell::ALIVE );
                REQUIRE( g(3, 2) == Cell::ALIVE );
                REQUIRE( g(3, 1) == Cell::ALIVE );
                REQUIRE( g(2, 0) == Cell::ALIVE );

                REQUIRE( g(0, 2) == Cell::DEAD );
            }

            WHEN( "a grid is observed in a constant context" ) {

                const Grid &h = g;

                THEN( "the glider is placed as expected" ) {

                    REQUIRE(       h.get_width() == 4 );
                    REQUIRE(      h.get_height() == 3 );
                    REQUIRE( h.get_total_cells() == (4 * 3) );

                    REQUIRE( h.get_alive_cells() == 5 );
                    REQUIRE( h.get_dead_cells() == (4 * 3) - 5 );
                    REQUIRE( h.get(1, 2) == Cell::ALIVE );
                    REQUIRE( h.get(2, 2) == Cell::ALIVE );
                    REQUIRE( h.get(3, 2) == Cell::ALIVE );
                    REQUIRE( h.get(3, 1) == Cell::ALIVE );
                    REQUIRE( h.get(2, 0) == Cell::ALIVE );
                }

                THEN( "the glider can be observed using operator()" ) {

                    REQUIRE( h(1, 2) == Cell::ALIVE );
                    REQUIRE( h(2, 2) == Cell::ALIVE );
                    REQUIRE( h(3, 2) == Cell::ALIVE );
                    REQUIRE( h(3, 1) == Cell::ALIVE );
                    REQUIRE( h(2, 0) == Cell::ALIVE );

                    REQUIRE( h(0, 2) == Cell::DEAD );
                }

            }
        }

    } // GIVEN

} // SCENARIO


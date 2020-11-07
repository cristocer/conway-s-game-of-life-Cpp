/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"
#include "../world.h"

SCENARIO( "a world can be default constructed", "[world][constructor]" ) {

    GIVEN( "a default constructed world instance" ) {
        World w;

        THEN( "the width and height should be correct" ) {

            REQUIRE(w.get_width() == 0);
            REQUIRE(w.get_height() == 0);
            REQUIRE(w.get_total_cells() == 0);
        }

        THEN( "the population should be zero" ) {

            REQUIRE( w.get_alive_cells() == 0 );
            REQUIRE( w.get_dead_cells() == 0 );
        }
    }
}

SCENARIO( "a world can be constructed with a square edge size", "[world][constructor]" ) {

    GIVEN( "a world constructed with size 8x8" ) {
        World w(8);

        THEN( "the width and height should be correct" ) {

            REQUIRE( w.get_width() == 8 );
            REQUIRE( w.get_height() == 8 );
            REQUIRE( w.get_total_cells() == (8 * 8) );
        }

        THEN( "the population should be zero" ) {

            REQUIRE( w.get_alive_cells() == 0 );
            REQUIRE( w.get_dead_cells() == (8 * 8) );
        }
    }
}

SCENARIO( "a world can be constructed with a width and height", "[world][constructor]" ) {

    GIVEN( "a world constructed with size 8x4" ) {
        World w(8, 4);

        THEN( "the width and height should be correct" ) {

            REQUIRE( w.get_width() == 8 );
            REQUIRE( w.get_height() == 4 );
            REQUIRE( w.get_total_cells() == (8 * 4) );
        }

        THEN( "the population should be zero" ) {

            REQUIRE( w.get_alive_cells() == 0 );
            REQUIRE( w.get_dead_cells() == (8 * 4) );
        }
    }
}

SCENARIO( "a world can be constructed with a from a grid", "[world][constructor]" ) {

    GIVEN( "a grid of size 8x8 where the centre 4x4 is alive" ) {

        Grid g(8);

        for (int y = 2; y < 6; y++) {
            for (int x = 2; x < 6; x++) {

                g.set(x, y, Cell::ALIVE);
            }
        }

        WHEN( "a world is constructed from the grid" ) {

            World w(g);

            THEN( "the width and height should be that of the grid" ) {

                REQUIRE(       w.get_width() == 8 );
                REQUIRE(      w.get_height() == 8 );
                REQUIRE( w.get_total_cells() == (8 * 8) );
            }

            THEN( "the alive and dead counts should be the same as the grids" ) {

                REQUIRE( w.get_alive_cells() == (4 * 4) );
                REQUIRE(  w.get_dead_cells() == (8 * 8) - (4 * 4) );

                REQUIRE( w.get_alive_cells() == g.get_alive_cells() );
                REQUIRE(  w.get_dead_cells() ==  g.get_dead_cells() );
            }
        }
    }
}
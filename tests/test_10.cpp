/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"
#include "../world.h"

SCENARIO( "resizing a world correctly retains its contents", "[world][resize]" ) {

    GIVEN( "a world with size 8x8 where the centre 4x4 is alive" ) {

        Grid g(8, 8);

        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {

                g.set(x, y, Cell::ALIVE);
            }
        }

        World w(g);

        REQUIRE(       w.get_width() == 8       );
        REQUIRE(      w.get_height() == 8       );
        REQUIRE( w.get_total_cells() == (8 * 8) );
        REQUIRE( w.get_alive_cells() == (4 * 4) );
        REQUIRE(  w.get_dead_cells() == (8 * 8) - (4 * 4) );

        WHEN( "the world is resized to be 16x16" ) {

            w.resize(16, 16);

            THEN("the upper left 4x4 region should still be alive") {

                REQUIRE(w.get_alive_cells() == (4 * 4));
                REQUIRE(w.get_dead_cells() == (16 * 16) - (4 * 4));

                for (int y = 0; y < 4; y++) {
                    for (int x = 0; x < 4; x++) {

                        REQUIRE(w.get_state().get(x, y) == Cell::ALIVE);
                    }
                }
            }
        }

        WHEN( "the world is resized to be 2x8" ) {

            w.resize(2, 8);

            THEN( "the upper left 2x4 region should still be alive" ) {

                REQUIRE( w.get_alive_cells() == (2 * 4) );
                REQUIRE(  w.get_dead_cells() == (2 * 8) - (2 * 4) );

                for (int y = 0; y < 4; y++) {
                    for (int x = 0; x < 2; x++) {

                        REQUIRE( w.get_state().get(x, y) == Cell::ALIVE );
                    }
                }
            }

            WHEN( "the world is resized to be 2x2" ) {

                w.resize(2, 2);

                THEN( "the upper left 2x2 region should still be alive" ) {

                    REQUIRE( w.get_alive_cells() == (2 * 2) );
                    REQUIRE(  w.get_dead_cells() == 0 );

                    for (int y = 0; y < 2; y++) {
                        for (int x = 0; x < 2; x++) {

                            REQUIRE( w.get_state().get(x, y) == Cell::ALIVE );
                        }
                    }
                }
            }
        }

        WHEN( "the world is resized to be 8x2" ) {

            w.resize(8, 2);

            THEN( "the upper left 4x2 region should still be alive" ) {

                REQUIRE( w.get_alive_cells() == (4 * 2) );
                REQUIRE(  w.get_dead_cells() == (8 * 2) - (4 * 2) );

                for (int y = 0; y < 2; y++) {
                    for (int x = 0; x < 4; x++) {

                        REQUIRE( w.get_state().get(x, y) == Cell::ALIVE );
                    }
                }
            }

            WHEN( "the world is resized to be 2x2" ) {

                w.resize(2, 2);

                THEN("the upper left 2x2 region should still be alive") {

                    REQUIRE(w.get_alive_cells() == (2 * 2));
                    REQUIRE(w.get_dead_cells() == 0);

                    for (int y = 0; y < 2; y++) {
                        for (int x = 0; x < 2; x++) {

                            REQUIRE(w.get_state().get(x, y) == Cell::ALIVE);
                        }
                    }
                }
            }
        }

    } // GIVEN

} // SCENARIO
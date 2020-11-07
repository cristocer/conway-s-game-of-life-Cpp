/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"

SCENARIO( "grids can be merged from existing grids", "[grid][merge]" ) {

    GIVEN( "a grid with size 8x8, and two grids with size 4x4 that are fully alive and fully dead" ) {
        
        Grid w(8, 8);

        REQUIRE( w.get_alive_cells() == 0 );

        Grid dead_w(4, 4);

        REQUIRE( dead_w.get_alive_cells() == 0 );

        Grid alive_w(4, 4);

        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                
                alive_w.set(x, y, Cell::ALIVE);
            }   
        }

        REQUIRE( alive_w.get_alive_cells() == (4 * 4) );

        WHEN( "the centre 4x4 region is merged with the alive grid" ) {
            
            w.merge(alive_w, 2, 2);

            THEN( "the centre 4x4 region should be alive" ) {

                REQUIRE(       w.get_width() == 8 );
                REQUIRE(      w.get_height() == 8 );
                REQUIRE( w.get_alive_cells() == (4 * 4) );

                for (int y = 2; y < 6; y++) {
                    for (int x = 2; x < 6; x++) {
                        
                        REQUIRE( w.get(x, y) == Cell::ALIVE );
                    }   
                }
            }

            THEN( "the alive grid should remain unchanged" ) {

                REQUIRE(       alive_w.get_width() == 4 );
                REQUIRE(      alive_w.get_height() == 4 );
                REQUIRE( alive_w.get_alive_cells() == (4 * 4) );
            }

            WHEN( "the upper left 4x4 region is merged with the dead grid" ) {
            
                w.merge(dead_w, 0, 0);

                THEN( "the upper left 2x2 region of the centre 4x4 region should be dead" ) {

                    REQUIRE(       w.get_width() == 8 );
                    REQUIRE(      w.get_height() == 8 );
                    REQUIRE( w.get_alive_cells() == (4 * 4) - (2 * 2) );

                    for (int y = 2; y < 4; y++) {
                        for (int x = 2; x < 4; x++) {
                            
                            REQUIRE( w.get(x, y) == Cell::DEAD );
                        }   
                    }
                }

                THEN( "the dead grid should remain unchanged" ) {

                    REQUIRE(       dead_w.get_width() == 4 );
                    REQUIRE(      dead_w.get_height() == 4 );
                    REQUIRE( dead_w.get_alive_cells() == 0 );
                }
            }

            WHEN( "the upper left 4x4 region is merged with the dead grid using alive_only=false" ) {
            
                w.merge(dead_w, 0, 0, false);

                THEN( "the upper left 2x2 region of the centre 4x4 region should be dead" ) {

                    REQUIRE(       w.get_width() == 8 );
                    REQUIRE(      w.get_height() == 8 );
                    REQUIRE( w.get_alive_cells() == (4 * 4) - (2 * 2) );

                    for (int y = 2; y < 4; y++) {
                        for (int x = 2; x < 4; x++) {
                            
                            REQUIRE( w.get(x, y) == Cell::DEAD );
                        }   
                    }
                }

                THEN( "the dead grid should remain unchanged" ) {

                    REQUIRE(       dead_w.get_width() == 4 );
                    REQUIRE(      dead_w.get_height() == 4 );
                    REQUIRE( dead_w.get_alive_cells() == 0 );
                }
            }

            WHEN( "the upper left 4x4 region is merged with the dead grid using alive_only=true" ) {
            
                w.merge(dead_w, 0, 0, true);

                THEN( "the upper left 2x2 region of the centre 4x4 region should remain alive" ) {

                    REQUIRE(       w.get_width() == 8 );
                    REQUIRE(      w.get_height() == 8 );
                    REQUIRE( w.get_alive_cells() == (4 * 4) );

                    for (int y = 2; y < 4; y++) {
                        for (int x = 2; x < 4; x++) {

                            REQUIRE( w.get(x, y) == Cell::ALIVE );
                        }   
                    }
                }

                THEN( "the dead grid should remain unchanged" ) {

                    REQUIRE(       dead_w.get_width() == 4 );
                    REQUIRE(      dead_w.get_height() == 4 );
                    REQUIRE( dead_w.get_alive_cells() == 0 );
                }
            }
        }

    } // GIVEN
    
} // SCENARIO
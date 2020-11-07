/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"

SCENARIO( "sub-grids can be extracted from existing grids", "[grid][crop]" ) {

    GIVEN( "a grid with size 8x8" ) {
        
        Grid w(8, 8);

        REQUIRE(       w.get_width() == 8       );
        REQUIRE(      w.get_height() == 8       );
        REQUIRE( w.get_total_cells() == (8 * 8) );
        REQUIRE( w.get_alive_cells() == 0       );
        REQUIRE(  w.get_dead_cells() == (8 * 8) );

        WHEN( "the centre 4x4 region is set to be alive" ) {
            
            for (int y = 2; y < 6; y++) {
                for (int x = 2; x < 6; x++) {
                    
                    w.set(x, y, Cell::ALIVE);
                }   
            }
            
            THEN( "the alive and dead counts should appear updated" ) {

                REQUIRE( w.get_alive_cells() == (4 * 4) );
                REQUIRE(  w.get_dead_cells() == (8 * 8) - (4 * 4) );
            }

            WHEN( "the upper left 4x4 region is extracted" ) {
            
                Grid h = w.crop(0, 0, 4, 4);
                
                THEN( "the extracted region should be size 4x4 with the lower right 2x2 region alive" ) {

                    REQUIRE(  h.get_width() == 4 );
                    REQUIRE( h.get_height() == 4 );

                    REQUIRE( h.get_alive_cells() == (2 * 2) );
                    REQUIRE(  h.get_dead_cells() == (4 * 4) - (2 * 2) );

                    for (int y = 2; y < 4; y++) {
                        for (int x = 2; x < 4; x++) {
                            
                            REQUIRE( h.get(x, y) == Cell::ALIVE );
                        }   
                    }
                }
            }

            WHEN( "the upper right 4x4 region is extracted" ) {
            
                Grid h = w.crop(4, 0, 8, 4);

                THEN( "the extracted region should be size 4x4 with the lower left 2x2 region alive" ) {

                    REQUIRE(h.get_width() == 4 );
                    REQUIRE(h.get_height() == 4 );

                    REQUIRE(h.get_alive_cells() == (2 * 2) );
                    REQUIRE(h.get_dead_cells() == (4 * 4) - (2 * 2) );

                    for (int y = 2; y < 4; y++) {
                        for (int x = 0; x < 2; x++) {
                            
                            REQUIRE(h.get(x, y) == Cell::ALIVE );
                        }   
                    }
                }
            }

            WHEN( "the lower left 4x4 region is extracted" ) {
            
                Grid h = w.crop(0, 4, 4, 8);
                
                THEN( "the extracted region should be size 4x4 with the upper right 2x2 region alive" ) {

                    REQUIRE(h.get_width() == 4 );
                    REQUIRE(h.get_height() == 4 );

                    REQUIRE(h.get_alive_cells() == (2 * 2) );
                    REQUIRE(h.get_dead_cells() == (4 * 4) - (2 * 2) );

                    for (int y = 0; y < 2; y++) {
                        for (int x = 2; x < 4; x++) {
                            
                            REQUIRE(h.get(x, y) == Cell::ALIVE );
                        }   
                    }
                }
            }

            WHEN( "the lower right 4x4 region is extracted" ) {
            
                Grid h = w.crop(4, 4, 8, 8);
                
                THEN( "the extracted region should be size 4x4 with the upper left 2x2 region alive" ) {

                    REQUIRE(h.get_width() == 4 );
                    REQUIRE(h.get_height() == 4 );

                    REQUIRE(h.get_alive_cells() == (2 * 2) );
                    REQUIRE(h.get_dead_cells() == (4 * 4) - (2 * 2) );

                    for (int y = 0; y < 2; y++) {
                        for (int x = 0; x < 2; x++) {
                            
                            REQUIRE(h.get(x, y) == Cell::ALIVE );
                        }   
                    }
                }
            }
        }

    } // GIVEN
    
} // SCENARIO
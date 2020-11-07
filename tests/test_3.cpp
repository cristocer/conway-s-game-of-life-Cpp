/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"

SCENARIO( "resizing a grid correctly retains its contents", "[grid][resize]" ) {

    GIVEN( "a grid with size 8x8" ) {
        
        Grid w(8, 8);

        REQUIRE(       w.get_width() == 8       );
        REQUIRE(      w.get_height() == 8       );
        REQUIRE( w.get_total_cells() == (8 * 8) );
        REQUIRE( w.get_alive_cells() == 0       );
        REQUIRE(  w.get_dead_cells() == (8 * 8) );

        WHEN( "the upper left 4x4 region is set to be alive" ) {
            
            for (int y = 0; y < 4; y++) {
                for (int x = 0; x < 4; x++) {
                    
                    w.set(x, y, Cell::ALIVE);
                }   
            }
            
            THEN( "the alive and dead counts should appear updated" ) {

                for (int y = 0; y < 4; y++) {
                    for (int x = 0; x < 4; x++) {
                        
                        REQUIRE( w.get(x, y) == Cell::ALIVE );
                    }   
                }

                REQUIRE( w.get_alive_cells() == (4 * 4) );
                REQUIRE(  w.get_dead_cells() == (8 * 8) - (4 * 4) );
            }

            WHEN( "the grid is resized to be 16x16" ) {

                w.resize(16, 16);

                THEN("the upper left 4x4 region should still be alive") {

                    REQUIRE(w.get_alive_cells() == (4 * 4));
                    REQUIRE(w.get_dead_cells() == (16 * 16) - (4 * 4));

                    for (int y = 0; y < 4; y++) {
                        for (int x = 0; x < 4; x++) {

                            REQUIRE(w.get(x, y) == Cell::ALIVE);
                        }
                    }
                }
            }

            WHEN( "the grid is resized to be 2x8" ) {
            
                w.resize(2, 8);
                
                THEN( "the upper left 2x4 region should still be alive" ) {

                    REQUIRE( w.get_alive_cells() == (2 * 4) );
                    REQUIRE(  w.get_dead_cells() == (2 * 8) - (2 * 4) );

                    for (int y = 0; y < 4; y++) {
                        for (int x = 0; x < 2; x++) {
                            
                            REQUIRE( w.get(x, y) == Cell::ALIVE );
                        }   
                    }
                }

                WHEN( "the grid is resized to be 2x2" ) {
            
                    w.resize(2, 2);
                    
                    THEN( "the upper left 2x2 region should still be alive" ) {

                        REQUIRE( w.get_alive_cells() == (2 * 2) );
                        REQUIRE(  w.get_dead_cells() == 0 );

                        for (int y = 0; y < 2; y++) {
                            for (int x = 0; x < 2; x++) {
                                
                                REQUIRE( w.get(x, y) == Cell::ALIVE );
                            }   
                        }
                    }
                }
            }

            WHEN( "the grid is resized to be 8x2" ) {
            
                w.resize(8, 2);
                
                THEN( "the upper left 4x2 region should still be alive" ) {

                    REQUIRE( w.get_alive_cells() == (4 * 2) );
                    REQUIRE(  w.get_dead_cells() == (8 * 2) - (4 * 2) );

                    for (int y = 0; y < 2; y++) {
                        for (int x = 0; x < 4; x++) {
                            
                            REQUIRE( w.get(x, y) == Cell::ALIVE );
                        }   
                    }
                }

                WHEN( "the grid is resized to be 2x2" ) {
            
                    w.resize(2, 2);
                    
                    THEN( "the upper left 2x2 region should still be alive" ) {

                        REQUIRE( w.get_alive_cells() == (2 * 2) );
                        REQUIRE(  w.get_dead_cells() == 0 );

                        for (int y = 0; y < 2; y++) {
                            for (int x = 0; x < 2; x++) {
                                
                                REQUIRE( w.get(x, y) == Cell::ALIVE );
                            }   
                        }
                    }
                }
            }
        }

    } // GIVEN

} // SCENARIO
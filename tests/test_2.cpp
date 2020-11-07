/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"

SCENARIO( "resizing a grid correctly updates its observed size", "[grid][resize]" ) {

    GIVEN( "a default constructed grid that is empty" ) {
        
        Grid w;

        WHEN( "the width is set" ) {
            w.resize(2, 0);
            
            THEN( "the width should change and height should remain the same" ) {

                REQUIRE(       w.get_width() == 2 );
                REQUIRE(      w.get_height() == 0 );
                REQUIRE( w.get_total_cells() == 0 );
            }

            WHEN( "the height is set" ) {
                w.resize(2, 3);
                
                THEN( "the height should change and width should remain the same" ) {

                    REQUIRE(       w.get_width() == 2 );
                    REQUIRE(      w.get_height() == 3 );
                    REQUIRE( w.get_total_cells() == (2 * 3) );
                }
            }
        }

        WHEN( "the height is set" ) {
            w.resize(0, 2);
            
            THEN( "the height should change and width should remain the same" ) {

                REQUIRE(       w.get_width() == 0 );
                REQUIRE(      w.get_height() == 2 );
                REQUIRE( w.get_total_cells() == 0 );
            }

            WHEN( "the width is set" ) {
                w.resize(3, 2);
                
                THEN( "the width should change and height should remain the same" ) {

                    REQUIRE(       w.get_width() == 3 );
                    REQUIRE(      w.get_height() == 2 );
                    REQUIRE( w.get_total_cells() == (3 * 2) );
                }
            }
        }

        WHEN( "the width and height are set" ) {
            w.resize(3, 2);
            
            THEN( "the width and height should change" ) {

                REQUIRE(       w.get_width() == 3 );
                REQUIRE(      w.get_height() == 2 );
                REQUIRE( w.get_total_cells() == (3 * 2) );
            }
        }
    }
}
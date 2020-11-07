/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"

SCENARIO( "a grid can be default constructed", "[grid][constructor]" ) {

    GIVEN( "a default constructed grid instance" ) {
        Grid w;

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

SCENARIO( "a grid can be constructed with a square edge size", "[grid][constructor]" ) {

    GIVEN( "a grid constructed with size 8x8" ) {
        Grid w(8);

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

SCENARIO( "a grid can be constructed with a width and height", "[grid][constructor]" ) {

    GIVEN( "a grid constructed with size 8x4" ) {
        Grid w(8, 4);

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

    GIVEN( "a grid constructed with size 4x8" ) {
        Grid w(4, 8);

        THEN( "the width and height should be correct" ) {

            REQUIRE(w.get_width() == 4);
            REQUIRE(w.get_height() == 8);
            REQUIRE(w.get_total_cells() == (4 * 8));
        }

        THEN( "the population should be zero" ) {

            REQUIRE( w.get_alive_cells() == 0 );
            REQUIRE( w.get_dead_cells() == (4 * 8) );
        }
    }
}

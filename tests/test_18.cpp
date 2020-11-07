/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>

#include "../grid.h"

SCENARIO( "accessing a grid at an out of bounds coordinate throws an exception", "[grid][indexing][exception]" ) {

    GIVEN( "a grid constructed with size 6x4" ) {
        Grid g(6, 4);

        WHEN( "the grid is accessed at a valid coordinate do not throw exception" ) {

            REQUIRE_NOTHROW( g(5, 3) );
            REQUIRE_NOTHROW( g(5, 3) = Cell::ALIVE );
            REQUIRE_NOTHROW( g.get(5, 3) );
            REQUIRE_NOTHROW( g.set(5, 3, Cell::ALIVE) );
        }

        WHEN( "the grid is accessed at an x greater than the width throw exception" ) {

            REQUIRE_THROWS( g(10, 0) );
            REQUIRE_THROWS( g.get(10, 0) );
            REQUIRE_THROWS( g.set(10, 0, Cell::ALIVE) );
        }

        WHEN( "the grid is accessed at an x less than 0 throw exception" ) {

            REQUIRE_THROWS( g(-10, 0) );
            REQUIRE_THROWS( g.get(-10, 0) );
            REQUIRE_THROWS( g.set(-10, 0, Cell::ALIVE) );
        }

        WHEN( "the grid is accessed at an y greater than the height throw exception" ) {

            REQUIRE_THROWS( g(0, 10) );
            REQUIRE_THROWS( g(0, 10) = Cell::ALIVE );
            REQUIRE_THROWS( g.get(0, 10) );
            REQUIRE_THROWS( g.set(0, 10, Cell::ALIVE) );
        }

        WHEN( "the grid is accessed at an y less than 0 throw exception" ) {

            REQUIRE_THROWS( g(0, -10) );
            REQUIRE_THROWS( g(0, -10) = Cell::ALIVE );
            REQUIRE_THROWS( g.get(0, -10) );
            REQUIRE_THROWS( g.set(0, -10, Cell::ALIVE) );
        }
    }
}

SCENARIO( "cropping a grid at out of bounds coordinates throws an exception", "[grid][crop][exception]" ) {

    GIVEN( "a grid constructed with size 6x4" ) {
        Grid g(6, 4);

        WHEN( "the grid is accessed at a valid coordinate do not throw exception" ) {

            REQUIRE_NOTHROW( g.crop(0, 0, 6, 4) );
        }

        WHEN( "the grid is accessed at an x greater than the width throw exception" ) {

            REQUIRE_THROWS( g.crop(0, 0, 7, 4) );
        }

        WHEN( "the grid is accessed at an x less than 0 throw exception" ) {

            REQUIRE_THROWS( g.crop(-1, 0, 6, 4) );
        }

        WHEN( "the grid is accessed at an y greater than the height throw exception" ) {

            REQUIRE_THROWS( g.crop(0, 0, 6, 5) );
        }

        WHEN( "the grid is accessed at an y less than 0 throw exception" ) {

            REQUIRE_THROWS( g.crop(0, -1, 6, 4) );
        }
    }
}

SCENARIO( "cropping a grid at with inverted coordinates throws an exception", "[grid][crop][exception]" ) {

    GIVEN( "a grid constructed with size 4x4" ) {
        Grid g(4, 4);

        WHEN( "the grid is accessed at a valid coordinate do not throw exception" ) {

            REQUIRE_NOTHROW( g.crop(1, 1, 3, 3) );
        }

        WHEN( "the grid is accessed with x0 > x1 throw exception" ) {

            REQUIRE_THROWS( g.crop(3, 1, 1, 3) );
        }

        WHEN( "the grid is accessed with y0 > y1 throw exception" ) {

            REQUIRE_THROWS( g.crop(1, 3, 3, 1) );
        }
    }
}

SCENARIO( "merging a grid at out of bounds coordinates throws an exception", "[grid][merge][exception]" ) {

    GIVEN( "two grids constructed with size 4x4" ) {
        Grid g(4, 4);

        Grid h(4, 4);

        WHEN( "the grids are merged without going out of bounds do not throw an exception" ) {

            REQUIRE_NOTHROW( g.merge(h, 0, 0) );
        }

        WHEN( "the grids are merged such that the indices go out of bounds throw an exception" ) {

            REQUIRE_THROWS( g.merge(h, -1, 0) );
            REQUIRE_THROWS( g.merge(h,  1, 0) );
            REQUIRE_THROWS( g.merge(h, 0, -1) );
            REQUIRE_THROWS( g.merge(h, 0,  1) );
        }
    }
}



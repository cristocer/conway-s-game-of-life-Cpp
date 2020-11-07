/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>

#include "../grid.h"

SCENARIO( "grids can be rotated in 0 degree increments", "[grid][rotate]" ) {

    GIVEN( "a grid with size 4x3 containing a glider" ) {

        Grid g(4, 3);

        g.set(1, 2, Cell::ALIVE);
        g.set(2, 2, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(3, 1, Cell::ALIVE);
        g.set(2, 0, Cell::ALIVE);

//        +----+
//        |  # |
//        |   #|
//        | ###|
//        +----+

        REQUIRE(       g.get_width() == 4 );
        REQUIRE(      g.get_height() == 3 );
        REQUIRE( g.get_total_cells() == (4 * 3) );
        REQUIRE( g.get_alive_cells() == 5 );
        REQUIRE(  g.get_dead_cells() == (4 * 3) - 5 );
        REQUIRE( g.get(1, 2) == Cell::ALIVE );
        REQUIRE( g.get(2, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 1) == Cell::ALIVE );
        REQUIRE( g.get(2, 0) == Cell::ALIVE );

        WHEN( "the grid is rotated 0 degrees" ) {

            Grid h = g.rotate(0);

//        +----+
//        |  # |
//        |   #|
//        | ###|
//        +----+

            THEN( "the original grid is unchanged" ) {

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

            THEN( "the new grid has the same width and height" ) {

                REQUIRE(       h.get_width() == 4 );
                REQUIRE(      h.get_height() == 3 );
                REQUIRE( h.get_total_cells() == (4 * 3) );
            }

            THEN( "the new grid has the glider in the same place" ) {

                REQUIRE( h.get_alive_cells() == 5 );
                REQUIRE( h.get_dead_cells() == (4 * 3) - 5 );
                REQUIRE( h.get(1, 2) == Cell::ALIVE );
                REQUIRE( h.get(2, 2) == Cell::ALIVE );
                REQUIRE( h.get(3, 2) == Cell::ALIVE );
                REQUIRE( h.get(3, 1) == Cell::ALIVE );
                REQUIRE( h.get(2, 0) == Cell::ALIVE );
            }
        }

    } // GIVEN

} // SCENARIO

SCENARIO( "grids can be rotated in 90 degree increments", "[grid][rotate]" ) {

    GIVEN( "a grid with size 4x3 containing a glider" ) {

        Grid g(4, 3);

        g.set(1, 2, Cell::ALIVE);
        g.set(2, 2, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(3, 1, Cell::ALIVE);
        g.set(2, 0, Cell::ALIVE);

//        +----+
//        |  # |
//        |   #|
//        | ###|
//        +----+

        REQUIRE(       g.get_width() == 4 );
        REQUIRE(      g.get_height() == 3 );
        REQUIRE( g.get_total_cells() == (4 * 3) );
        REQUIRE( g.get_alive_cells() == 5 );
        REQUIRE(  g.get_dead_cells() == (4 * 3) - 5 );
        REQUIRE( g.get(1, 2) == Cell::ALIVE );
        REQUIRE( g.get(2, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 1) == Cell::ALIVE );
        REQUIRE( g.get(2, 0) == Cell::ALIVE );

        WHEN( "the grid is rotated 90 clockwise" ) {

            Grid h = g.rotate(1);

//            +---+
//            |   |
//            |#  |
//            |# #|
//            |## |
//            +---+

            THEN( "the original grid is unchanged" ) {

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

            THEN( "the new grid has the width and height swapped" ) {

                REQUIRE(       h.get_width() == 3 );
                REQUIRE(      h.get_height() == 4 );
                REQUIRE( h.get_total_cells() == (3 * 4) );
            }

            THEN( "the new grid has the glider correctly rotated 90 degrees" ) {

                REQUIRE( h.get_alive_cells() == 5 );
                REQUIRE( h.get_dead_cells() == (3 * 4) - 5 );
                REQUIRE( h.get(0, 1) == Cell::ALIVE );
                REQUIRE( h.get(0, 2) == Cell::ALIVE );
                REQUIRE( h.get(0, 3) == Cell::ALIVE );
                REQUIRE( h.get(1, 3) == Cell::ALIVE );
                REQUIRE( h.get(2, 2) == Cell::ALIVE );
            }

            WHEN( "the grid is rotated back 90 counter-clockwise" ) {

                Grid k = h.rotate(-1);

//                +----+
//                |  # |
//                |   #|
//                | ###|
//                +----+

                THEN( "the new grid has the width and height swapped back" ) {

                    REQUIRE(       k.get_width() == 4 );
                    REQUIRE(      k.get_height() == 3 );
                    REQUIRE( k.get_total_cells() == (4 * 3) );
                    REQUIRE( k.get_alive_cells() == 5 );
                    REQUIRE(  k.get_dead_cells() == (4 * 3) - 5 );
                }

                THEN( "the new grid has the glider back where it started" ) {

                    REQUIRE( k.get(1, 2) == Cell::ALIVE );
                    REQUIRE( k.get(2, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 1) == Cell::ALIVE );
                    REQUIRE( k.get(2, 0) == Cell::ALIVE );
                }
            }
        }

    } // GIVEN
    
} // SCENARIO

SCENARIO( "grids can be rotated in 180 degree increments", "[grid][rotate]" ) {

    GIVEN( "a grid with size 4x3 containing a glider" ) {

        Grid g(4, 3);

        g.set(1, 2, Cell::ALIVE);
        g.set(2, 2, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(3, 1, Cell::ALIVE);
        g.set(2, 0, Cell::ALIVE);

//        +----+
//        |  # |
//        |   #|
//        | ###|
//        +----+

        REQUIRE(       g.get_width() == 4 );
        REQUIRE(      g.get_height() == 3 );
        REQUIRE( g.get_total_cells() == (4 * 3) );
        REQUIRE( g.get_alive_cells() == 5 );
        REQUIRE(  g.get_dead_cells() == (4 * 3) - 5 );
        REQUIRE( g.get(1, 2) == Cell::ALIVE );
        REQUIRE( g.get(2, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 1) == Cell::ALIVE );
        REQUIRE( g.get(2, 0) == Cell::ALIVE );

        WHEN( "the grid is rotated 180 clockwise" ) {

            Grid h = g.rotate(2);

//            +----+
//            |### |
//            |#   |
//            | #  |
//            +----+

            THEN( "the original grid is unchanged" ) {

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

            THEN( "the new grid has the same width and height" ) {

                REQUIRE(       h.get_width() == 4 );
                REQUIRE(      h.get_height() == 3 );
                REQUIRE( h.get_total_cells() == (4 * 3) );
            }

            THEN( "the new grid has the glider correctly rotated 180 degrees" ) {

                REQUIRE( h.get_alive_cells() == 5 );
                REQUIRE( h.get_dead_cells() == (3 * 4) - 5 );
                REQUIRE( h.get(0, 0) == Cell::ALIVE );
                REQUIRE( h.get(1, 0) == Cell::ALIVE );
                REQUIRE( h.get(2, 0) == Cell::ALIVE );
                REQUIRE( h.get(0, 1) == Cell::ALIVE );
                REQUIRE( h.get(1, 2) == Cell::ALIVE );
            }

            WHEN( "the grid is rotated back 90 counter-clockwise" ) {

                Grid k = h.rotate(-2);

//                +----+
//                |  # |
//                |   #|
//                | ###|
//                +----+

                THEN( "the original grid is unchanged" ) {

                    REQUIRE(       h.get_width() == 4 );
                    REQUIRE(      h.get_height() == 3 );
                    REQUIRE( h.get_total_cells() == (4 * 3) );

                    REQUIRE( h.get_alive_cells() == 5 );
                    REQUIRE( h.get_dead_cells() == (3 * 4) - 5 );
                    REQUIRE( h.get(0, 0) == Cell::ALIVE );
                    REQUIRE( h.get(1, 0) == Cell::ALIVE );
                    REQUIRE( h.get(2, 0) == Cell::ALIVE );
                    REQUIRE( h.get(0, 1) == Cell::ALIVE );
                    REQUIRE( h.get(1, 2) == Cell::ALIVE );
                }

                THEN( "the new grid has the same width and height" ) {

                    REQUIRE(       k.get_width() == 4 );
                    REQUIRE(      k.get_height() == 3 );
                    REQUIRE( k.get_total_cells() == (4 * 3) );
                    REQUIRE( k.get_alive_cells() == 5 );
                    REQUIRE(  k.get_dead_cells() == (4 * 3) - 5 );
                }

                THEN( "the new grid has the glider back where it started" ) {

                    REQUIRE( k.get(1, 2) == Cell::ALIVE );
                    REQUIRE( k.get(2, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 1) == Cell::ALIVE );
                    REQUIRE( k.get(2, 0) == Cell::ALIVE );
                }
            }
        }

    } // GIVEN

} // SCENARIO

SCENARIO( "grids can be rotated in 270 degree increments", "[grid][rotate]" ) {

    GIVEN( "a grid with size 4x3 containing a glider" ) {

        Grid g(4, 3);

        g.set(1, 2, Cell::ALIVE);
        g.set(2, 2, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(3, 1, Cell::ALIVE);
        g.set(2, 0, Cell::ALIVE);

//        +----+
//        |  # |
//        |   #|
//        | ###|
//        +----+

        REQUIRE(       g.get_width() == 4 );
        REQUIRE(      g.get_height() == 3 );
        REQUIRE( g.get_total_cells() == (4 * 3) );
        REQUIRE( g.get_alive_cells() == 5 );
        REQUIRE(  g.get_dead_cells() == (4 * 3) - 5 );
        REQUIRE( g.get(1, 2) == Cell::ALIVE );
        REQUIRE( g.get(2, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 1) == Cell::ALIVE );
        REQUIRE( g.get(2, 0) == Cell::ALIVE );

        WHEN( "the grid is rotated 270 clockwise" ) {

            Grid h = g.rotate(3);

//            +---+
//            | ##|
//            |# #|
//            |  #|
//            |   |
//            +---+

            THEN( "the original grid is unchanged" ) {

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

            THEN( "the new grid has the width and height swapped" ) {

                REQUIRE(       h.get_width() == 3 );
                REQUIRE(      h.get_height() == 4 );
                REQUIRE( h.get_total_cells() == (3 * 4) );
            }

            THEN( "the new grid has the glider correctly rotated 270 degrees" ) {

                REQUIRE( h.get_alive_cells() == 5 );
                REQUIRE( h.get_dead_cells() == (3 * 4) - 5 );
                REQUIRE( h.get(1, 0) == Cell::ALIVE );
                REQUIRE( h.get(2, 0) == Cell::ALIVE );
                REQUIRE( h.get(0, 1) == Cell::ALIVE );
                REQUIRE( h.get(2, 1) == Cell::ALIVE );
                REQUIRE( h.get(2, 2) == Cell::ALIVE );
            }

            WHEN( "the grid is rotated back 270 degrees counter-clockwise" ) {

                Grid k = h.rotate(-3);

//                +----+
//                |  # |
//                |   #|
//                | ###|
//                +----+

                THEN( "the new grid has the width and height swapped back" ) {

                    REQUIRE(       k.get_width() == 4 );
                    REQUIRE(      k.get_height() == 3 );
                    REQUIRE( k.get_total_cells() == (4 * 3) );
                    REQUIRE( k.get_alive_cells() == 5 );
                    REQUIRE(  k.get_dead_cells() == (4 * 3) - 5 );

                }

                THEN( "the new grid has the glider back where it started" ) {

                    REQUIRE( k.get(1, 2) == Cell::ALIVE );
                    REQUIRE( k.get(2, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 1) == Cell::ALIVE );
                    REQUIRE( k.get(2, 0) == Cell::ALIVE );
                }
            }
        }

    } // GIVEN

} // SCENARIO

SCENARIO( "grids can be rotated in arbitrary multiples of 90 degree increments", "[grid][rotate]" ) {

    GIVEN( "a grid with size 4x3 containing a glider" ) {

        Grid g(4, 3);

        g.set(1, 2, Cell::ALIVE);
        g.set(2, 2, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(3, 1, Cell::ALIVE);
        g.set(2, 0, Cell::ALIVE);

//        +----+
//        |  # |
//        |   #|
//        | ###|
//        +----+

        REQUIRE(       g.get_width() == 4 );
        REQUIRE(      g.get_height() == 3 );
        REQUIRE( g.get_total_cells() == (4 * 3) );
        REQUIRE( g.get_alive_cells() == 5 );
        REQUIRE(  g.get_dead_cells() == (4 * 3) - 5 );
        REQUIRE( g.get(1, 2) == Cell::ALIVE );
        REQUIRE( g.get(2, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 2) == Cell::ALIVE );
        REQUIRE( g.get(3, 1) == Cell::ALIVE );
        REQUIRE( g.get(2, 0) == Cell::ALIVE );

        WHEN( "the grid is rotated (21 * 90) degrees clockwise" ) {

            Grid h = g.rotate(21);

//            +---+
//            |   |
//            |#  |
//            |# #|
//            |## |
//            +---+

            THEN( "the original grid is unchanged" ) {

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

            THEN( "the new grid has the width and height swapped" ) {

                REQUIRE(       h.get_width() == 3 );
                REQUIRE(      h.get_height() == 4 );
                REQUIRE( h.get_total_cells() == (3 * 4) );
            }

            THEN( "the new grid has the glider correctly rotated (21 * 90) degrees" ) {

                REQUIRE( h.get_alive_cells() == 5 );
                REQUIRE( h.get_dead_cells() == (3 * 4) - 5 );
                REQUIRE( h.get(0, 1) == Cell::ALIVE );
                REQUIRE( h.get(0, 2) == Cell::ALIVE );
                REQUIRE( h.get(0, 3) == Cell::ALIVE );
                REQUIRE( h.get(1, 3) == Cell::ALIVE );
                REQUIRE( h.get(2, 2) == Cell::ALIVE );
            }

            WHEN( "the grid is rotated back 90 counter-clockwise" ) {

                Grid k = h.rotate(-21);

//                +----+
//                |  # |
//                |   #|
//                | ###|
//                +----+

                THEN( "the new grid has the width and height swapped back" ) {

                    REQUIRE(       k.get_width() == 4 );
                    REQUIRE(      k.get_height() == 3 );
                    REQUIRE( k.get_total_cells() == (4 * 3) );
                    REQUIRE( k.get_alive_cells() == 5 );
                    REQUIRE(  k.get_dead_cells() == (4 * 3) - 5 );
                }

                THEN( "the new grid has the glider back where it started" ) {

                    REQUIRE( k.get(1, 2) == Cell::ALIVE );
                    REQUIRE( k.get(2, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 2) == Cell::ALIVE );
                    REQUIRE( k.get(3, 1) == Cell::ALIVE );
                    REQUIRE( k.get(2, 0) == Cell::ALIVE );
                }
            }
        }

    } // GIVEN

} // SCENARIO


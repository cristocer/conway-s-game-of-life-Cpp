/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"
#include "../world.h"

SCENARIO( "a world can be advanced explicitly using a cartesian coordinate system", "[world][step][advance][toroidal]" ) {

    GIVEN( "a world with size 6x6 containing a glider" ) {

        Grid g(6);

        g.set(1, 3, Cell::ALIVE);
        g.set(2, 3, Cell::ALIVE);
        g.set(3, 3, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(2, 1, Cell::ALIVE);

        World w(g);

//        +------+
//        |      |
//        |  #   |
//        |   #  |
//        | ###  |
//        |      |
//        |      |
//        +------+

        WHEN( "the world is advanced 12 steps using a cartesian coordinate system" ) {

            w.advance(12, false);

//            +------+
//            |      |
//            |      |
//            |      |
//            |      |
//            |    ##|
//            |    ##|
//            +------+

            THEN("the glider crashes into the bottom right corner of the grid") {

                REQUIRE(w.get_alive_cells() == 4);

                REQUIRE(w.get_state().get(4, 4) == Cell::ALIVE);
                REQUIRE(w.get_state().get(4, 5) == Cell::ALIVE);
                REQUIRE(w.get_state().get(5, 4) == Cell::ALIVE);
                REQUIRE(w.get_state().get(5, 5) == Cell::ALIVE);
            }
        }

    } // GIVEN

} // SCENARIO

SCENARIO( "a world can be advanced explicitly using a toroidal coordinate system", "[world][step][advance][toroidal]" ) {

    GIVEN( "a world with size 6x6 containing a glider" ) {

        Grid g(6);

        g.set(1, 3, Cell::ALIVE);
        g.set(2, 3, Cell::ALIVE);
        g.set(3, 3, Cell::ALIVE);
        g.set(3, 2, Cell::ALIVE);
        g.set(2, 1, Cell::ALIVE);

        World w(g);

//        +------+
//        |      |
//        |  #   |
//        |   #  |
//        | ###  |
//        |      |
//        |      |
//        +------+

        WHEN( "the world is advanced 12 steps using a toroidal coordinate system" ) {

            w.advance(11, true);
            w.step(true); // 12th step

//            +------+
//            |#   ##|
//            |      |
//            |      |
//            |      |
//            |     #|
//            |#     |
//            +------+

            THEN("the glider traverses the edge of the grid") {

                REQUIRE(w.get_alive_cells() == 5);

                REQUIRE(w.get_state().get(0, 0) == Cell::ALIVE);
                REQUIRE(w.get_state().get(4, 0) == Cell::ALIVE);
                REQUIRE(w.get_state().get(5, 0) == Cell::ALIVE);
                REQUIRE(w.get_state().get(0, 5) == Cell::ALIVE);
                REQUIRE(w.get_state().get(5, 4) == Cell::ALIVE);
            }

            WHEN( "the world is advanced 12 more steps using a toroidal coordinate system" ) {

                w.advance(12, true);

//                +------+
//                |      |
//                |  #   |
//                |   #  |
//                | ###  |
//                |      |
//                |      |
//                +------+

                THEN("the glider emerges from the top left corner and returns to its start position") {

                    REQUIRE(w.get_alive_cells() == 5);

                    REQUIRE(w.get_state().get(1, 3) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(2, 3) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(3, 3) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(3, 2) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(2, 1) == Cell::ALIVE);
                }
            }
        }

    } // GIVEN

} // SCENARIO
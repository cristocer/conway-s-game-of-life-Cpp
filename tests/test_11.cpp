/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"
#include "../world.h"

SCENARIO( "a world can be stepped forwards through time", "[world][step]" ) {

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

        WHEN( "the world is advanced one step" ) {

            w.step();

//            +------+
//            |      |
//            |      |
//            | # #  |
//            |  ##  |
//            |  #   |
//            |      |
//            +------+

            THEN("world observed state should reflect the rules having been applied") {

                REQUIRE(w.get_alive_cells() == 5);

                REQUIRE(w.get_state().get(2, 4) == Cell::ALIVE);
                REQUIRE(w.get_state().get(2, 3) == Cell::ALIVE);
                REQUIRE(w.get_state().get(3, 3) == Cell::ALIVE);
                REQUIRE(w.get_state().get(3, 2) == Cell::ALIVE);
                REQUIRE(w.get_state().get(1, 2) == Cell::ALIVE);
            }

            WHEN( "the world is advanced one more step" ) {

                w.step();

//                +------+
//                |      |
//                |      |
//                |   #  |
//                | # #  |
//                |  ##  |
//                |      |
//                +------+

                THEN("world observed state should reflect the rules having been applied twice") {

                    REQUIRE(w.get_alive_cells() == 5);

                    REQUIRE(w.get_state().get(1, 3) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(2, 4) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(3, 4) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(3, 3) == Cell::ALIVE);
                    REQUIRE(w.get_state().get(3, 2) == Cell::ALIVE);

                }
            }
        }

    } // GIVEN

} // SCENARIO

SCENARIO( "a world can be advanced one or more steps forwards", "[world][advance]" ) {

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

        WHEN( "the world is advanced one step" ) {

            w.advance(1);

//            +------+
//            |      |
//            |      |
//            | # #  |
//            |  ##  |
//            |  #   |
//            |      |
//            +------+

            THEN("world observed state should reflect the rules having been applied") {

                REQUIRE(w.get_alive_cells() == 5);

                REQUIRE(w.get_state().get(2, 4) == Cell::ALIVE);
                REQUIRE(w.get_state().get(2, 3) == Cell::ALIVE);
                REQUIRE(w.get_state().get(3, 3) == Cell::ALIVE);
                REQUIRE(w.get_state().get(3, 2) == Cell::ALIVE);
                REQUIRE(w.get_state().get(1, 2) == Cell::ALIVE);
            }
        }

        WHEN( "the world is advanced two steps" ) {

            w.advance(2);

//            +------+
//            |      |
//            |      |
//            |   #  |
//            | # #  |
//            |  ##  |
//            |      |
//            +------+

            THEN("world observed state should reflect the rules having been applied twice") {

                REQUIRE(w.get_alive_cells() == 5);

                REQUIRE(w.get_state().get(1, 3) == Cell::ALIVE);
                REQUIRE(w.get_state().get(2, 4) == Cell::ALIVE);
                REQUIRE(w.get_state().get(3, 4) == Cell::ALIVE);
                REQUIRE(w.get_state().get(3, 3) == Cell::ALIVE);
                REQUIRE(w.get_state().get(3, 2) == Cell::ALIVE);

            }
        }

    } // GIVEN

} // SCENARIO

SCENARIO( "by default there is a hard border at the edge of the world", "[world][step][advance]" ) {

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

        WHEN( "the world is advanced 12 steps" ) {

            w.advance(12);

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
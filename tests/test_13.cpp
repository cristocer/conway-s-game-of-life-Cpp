/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include "../grid.h"
#include "../zoo.h"

SCENARIO( "an ascii file can be read in from disc and parsed into a grid", "[zoo][load_ascii]" ) {

    GIVEN( "a default constructed world" ) {

        Grid g;

        REQUIRE(g.get_width() == 0);
        REQUIRE(g.get_height() == 0);
        REQUIRE(g.get_total_cells() == 0);

        WHEN( "glider.gol is loaded as an ascii file" ) {

            g = Zoo::load_ascii("../test_inputs/GLIDER.gol");

//            +------+
//            |      |
//            |  #   |
//            |   #  |
//            | ###  |
//            |      |
//            |      |
//            +------+

            THEN("the glider is correctly read into the constructed grid") {

                REQUIRE(g.get_alive_cells() == 5);

                REQUIRE(g.get(1, 3) == Cell::ALIVE);
                REQUIRE(g.get(2, 3) == Cell::ALIVE);
                REQUIRE(g.get(3, 3) == Cell::ALIVE);
                REQUIRE(g.get(3, 2) == Cell::ALIVE);
                REQUIRE(g.get(2, 1) == Cell::ALIVE);
            }
        }

    } // GIVEN

} // SCENARIO
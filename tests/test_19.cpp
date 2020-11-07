/**
* @author Dr. Joss Whittle
* @date March, 2020
*/

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>
#include <fstream>

#include "../zoo.h"

SCENARIO( "loading an ascii file throws exceptions on error", "[zoo][load_ascii][exception]" ) {

    auto file_exists = [](const std::string &path) {
        // fstream destructor closes the file
        return std::ifstream(path).is_open();
    };

    WHEN( "a valid and well formed file is loaded as an ascii file do not throw an exception" ) {

        REQUIRE(             file_exists("../test_inputs/GLIDER.gol") );
        REQUIRE_NOTHROW( Zoo::load_ascii("../test_inputs/GLIDER.gol") );
    }

    WHEN( "a non existent file is loaded as an ascii file throw an exception" ) {

        REQUIRE(           !file_exists("../test_inputs/DOES_NOT_EXIST.gol") );
        REQUIRE_THROWS( Zoo::load_ascii("../test_inputs/DOES_NOT_EXIST.gol") );
    }

    WHEN( "a malformed file that has negative edge sizes is loaded as an ascii file throw an exception" ) {

        REQUIRE(            file_exists("../test_inputs/MALFORMED_SIZE.gol") );
        REQUIRE_THROWS( Zoo::load_ascii("../test_inputs/MALFORMED_SIZE.gol") );
    }

    WHEN( "a malformed file that has data where a newline character should be is loaded as an ascii file throw an exception" ) {

        REQUIRE(            file_exists("../test_inputs/MALFORMED_NEWLINE.gol") );
        REQUIRE_THROWS( Zoo::load_ascii("../test_inputs/MALFORMED_NEWLINE.gol") );
    }

    WHEN( "a malformed file that ends unexpectedly is loaded as an ascii file throw an exception" ) {

        REQUIRE(            file_exists("../test_inputs/MALFORMED_CELL.gol") );
        REQUIRE_THROWS( Zoo::load_ascii("../test_inputs/MALFORMED_CELL.gol") );
    }

} // SCENARIO



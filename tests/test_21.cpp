/**
 * @author Dr. Joss Whittle
 * @date March, 2020
 */

// Uses Catch2 from https://github.com/catchorg/Catch2 under the BOOST license
#include "../catch2/catch.hpp"

#include <iostream>
#include <fstream>

#include "../zoo.h"

SCENARIO( "loading an binary file throws exceptions on error", "[zoo][load_binary][exception]" ) {

    auto file_exists = [](const std::string &path) {
        // fstream destructor closes the file
        return std::ifstream(path).is_open();
    };

    WHEN( "a valid and well formed file is loaded as an binary file do not throw an exception" ) {

        REQUIRE(              file_exists("../test_inputs/GLIDER.bgol") );
        REQUIRE_NOTHROW( Zoo::load_binary("../test_inputs/GLIDER.bgol") );
    }

    WHEN( "a non existent file is loaded as an binary file throw an exception" ) {

        REQUIRE(            !file_exists("../test_inputs/DOES_NOT_EXIST.bgol") );
        REQUIRE_THROWS( Zoo::load_binary("../test_inputs/DOES_NOT_EXIST.bgol") );
    }

    WHEN( "a malformed file that ends unexpectedly is loaded as an binary file throw an exception" ) {

        REQUIRE(             file_exists("../test_inputs/MALFORMED_DATA.bgol") );
        REQUIRE_THROWS( Zoo::load_binary("../test_inputs/MALFORMED_DATA.bgol") );
    }

} // SCENARIO



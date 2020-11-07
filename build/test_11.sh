set -x
cd "${0%/*}"
rm ../bin/test_11 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_11.cpp ../grid.cpp ../world.cpp ../bin/catch.o -o ../bin/test_11
../bin/test_11

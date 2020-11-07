set -x
cd "${0%/*}"
rm ../bin/test_12 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_12.cpp ../grid.cpp ../world.cpp ../bin/catch.o -o ../bin/test_12
../bin/test_12

set -x
cd "${0%/*}"
rm ../bin/test_10 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_10.cpp ../grid.cpp ../world.cpp ../bin/catch.o -o ../bin/test_10
../bin/test_10

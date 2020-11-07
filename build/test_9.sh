set -x
cd "${0%/*}"
rm ../bin/test_9 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_9.cpp ../grid.cpp ../world.cpp ../bin/catch.o -o ../bin/test_9
../bin/test_9

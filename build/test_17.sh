set -x
cd "${0%/*}"
rm ../bin/test_17 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_17.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_17
../bin/test_17

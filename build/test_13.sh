set -x
cd "${0%/*}"
rm ../bin/test_13 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_13.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_13
../bin/test_13

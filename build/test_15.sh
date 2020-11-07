set -x
cd "${0%/*}"
rm ../bin/test_15 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_15.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_15
../bin/test_15

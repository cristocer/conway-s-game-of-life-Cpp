set -x
cd "${0%/*}"
rm ../bin/test_14 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_14.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_14
../bin/test_14

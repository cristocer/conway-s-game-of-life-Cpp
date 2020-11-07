set -x
cd "${0%/*}"
rm ../bin/test_8 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_8.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_8
../bin/test_8

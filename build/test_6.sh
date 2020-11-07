set -x
cd "${0%/*}"
rm ../bin/test_6 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_6.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_6
../bin/test_6

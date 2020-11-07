set -x
cd "${0%/*}"
rm ../bin/test_4 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_4.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_4
../bin/test_4

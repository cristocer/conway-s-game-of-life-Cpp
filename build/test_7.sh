set -x
cd "${0%/*}"
rm ../bin/test_7 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_7.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_7
../bin/test_7

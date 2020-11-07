set -x
cd "${0%/*}"
rm ../bin/test_5 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_5.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_5
../bin/test_5

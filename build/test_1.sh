set -x
cd "${0%/*}"
rm ../bin/test_1 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_1.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_1
../bin/test_1

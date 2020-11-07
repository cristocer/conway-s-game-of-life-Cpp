set -x
cd "${0%/*}"
rm ../bin/test_2 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_2.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_2
../bin/test_2

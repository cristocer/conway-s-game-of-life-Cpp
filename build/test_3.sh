set -x
cd "${0%/*}"
rm ../bin/test_3 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_3.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_3
../bin/test_3

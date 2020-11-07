set -x
cd "${0%/*}"
rm ../bin/test_18 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_18.cpp ../grid.cpp ../bin/catch.o -o ../bin/test_18
../bin/test_18

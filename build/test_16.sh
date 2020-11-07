set -x
cd "${0%/*}"
rm ../bin/test_16 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_16.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_16
../bin/test_16

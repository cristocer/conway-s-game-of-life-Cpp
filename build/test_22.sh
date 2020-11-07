set -x
cd "${0%/*}"
rm ../bin/test_22 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_22.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_22
../bin/test_22

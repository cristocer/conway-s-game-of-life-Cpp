set -x
cd "${0%/*}"
rm ../bin/test_20 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_20.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_20
../bin/test_20

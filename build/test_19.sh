set -x
cd "${0%/*}"
rm ../bin/test_19 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_19.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_19
../bin/test_19

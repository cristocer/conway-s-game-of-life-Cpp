set -x
cd "${0%/*}"
rm ../bin/test_21 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_21.cpp ../grid.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_21
../bin/test_21

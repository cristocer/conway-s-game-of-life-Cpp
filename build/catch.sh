set -x
cd "${0%/*}"
rm ../bin/catch.o 2> /dev/null
g++ --std=c++11 -c ../catch2/catch_main.cpp -o ../bin/catch.o

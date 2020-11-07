set -x
cd "${0%/*}"
rm ../bin/test_all_monolithic 2> /dev/null
g++ --std=c++11 -Wall ../tests/test_1.cpp  ../tests/test_2.cpp  ../tests/test_3.cpp  ../tests/test_4.cpp  \
                      ../tests/test_5.cpp  ../tests/test_6.cpp  ../tests/test_7.cpp  ../tests/test_8.cpp  \
                      ../tests/test_9.cpp  ../tests/test_10.cpp ../tests/test_11.cpp ../tests/test_12.cpp \
                      ../tests/test_13.cpp ../tests/test_14.cpp ../tests/test_15.cpp ../tests/test_16.cpp \
                      ../tests/test_17.cpp ../tests/test_18.cpp ../tests/test_19.cpp ../tests/test_20.cpp \
                      ../tests/test_21.cpp ../grid.cpp ../world.cpp ../zoo.cpp ../bin/catch.o -o ../bin/test_all_monolithic
../bin/test_all_monolithic

NAME = unitTester
FLAGS = -Wall -Werror -Wextra
INCLUDES = includes
STD = -D LIBRARY=std
ALL = -D FLAGS=511
BONUS = -D FLAGS=480

basic:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} test/UnitTest.cpp -o ${NAME} 
all: 
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} ${ALL}  test/UnitTest.cpp -o ${NAME} 
bonus:
	@ clang++ ${FLAGS} -lgtest ${BONUS} -I ${INCLUDES} test/UnitTest.cpp -o ${NAME} 

stdlib: # MAKE WITH STD::LIBRARY TO TEST THE TESTER
	@ clang++ ${FLAGS} -lgtest ${STD} ${ALL} -I ${INCLUDES} test/UnitTest.cpp -o ${NAME} 

# TEST SPECIFICALLY ONE CONTAINER
vector:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=1 test/UnitTest.cpp -o ${NAME} 
list:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=2 test/UnitTest.cpp -o ${NAME} 
stack:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=4 test/UnitTest.cpp -o ${NAME} 
queue:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=8 test/UnitTest.cpp -o ${NAME} 
map:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=16 test/UnitTest.cpp -o ${NAME} 
deque:
	@ clang++ ${FLAGS} -lgtest -fsanitize=address -I ${INCLUDES} -D FLAGS=32 test/UnitTest.cpp -o ${NAME} 
set:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=64 test/UnitTest.cpp -o ${NAME} 
multiset:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=128 test/UnitTest.cpp -o ${NAME} 
multimap:
	@ clang++ ${FLAGS} -lgtest -I ${INCLUDES} -D FLAGS=256 test/UnitTest.cpp -o ${NAME} 
clean:
	rm ${NAME}

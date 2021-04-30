all: Stress_ball.o Jeans.o Stress_ball_test.o Jeans_test.o Collection-test.o 
	c++ -std=c++11 Stress_ball.o Jeans.o Stress_ball_test.o Jeans_test.o Collection-test.o -g -o test

Collection-test.o: Collection-test.cpp Collection.h
	c++ -std=c++11 -c Collection-test.cpp
Stress_ball.o: Stress_ball.h Stress_ball.cpp
	c++ -std=c++11 -c Stress_ball.cpp
Stress_ball_test.o: Stress_ball_test.cpp Collection.h Stress_ball.h
	c++ -std=c++11 -c Stress_ball_test.cpp
Jeans.o: Jeans.h Jeans.cpp
	c++ -std=c++11 -c Jeans.cpp
Jeans_test.o: Jeans_test.cpp Collection.h Jeans.h
	c++ -std=c++11 -c Jeans_test.cpp

clean:
	rm -f *.o test

run: test
	./test
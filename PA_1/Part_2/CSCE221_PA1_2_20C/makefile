all: main.o Collection.o Stress_ball.o
	c++ -std=c++11 Collection.o Stress_ball.o main.o -g -o test
Collection.o: Collection.h Collection.cpp
	c++ -std=c++11 -c Collection.cpp
Stress_ball.o: Stress_ball.h Stress_ball.cpp
	c++ -std=c++11 -c Stress_ball.cpp
main.o: main.cpp Collection.h Stress_ball.h
	c++ -std=c++11 -c main.cpp

clean:
	rm *.o test

run: test
	./test

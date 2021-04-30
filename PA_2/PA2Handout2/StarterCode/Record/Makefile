all: record

record: Record.o main.o
	c++ -fpermissive -g -std=c++11 Record.o main.o -o record

Record.o: Record.cpp Record.h
	c++ -fpermissive -g -std=c++11 -c Record.cpp

main.o: main.cpp Record.h
	c++ -fpermissive -std=c++11 -c main.cpp

clean:
	rm *.o record

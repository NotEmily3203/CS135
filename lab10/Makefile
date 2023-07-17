main: main.o time.o movie.o timeslot.o
	g++ -o main main.o time.o movie.o timeslot.o

tests: tests.o time.o movie.o timeslot.o
	g++ -o tests tests.o time.o movie.o timeslot.o

time.o: time.cpp time.h

movie.o: movie.cpp movie.h time.h

timeslot.o: timeslot.cpp timeslot.h movie.h time.h

main.o: main.cpp time.h movie.h timeslot.h

tests.o: tests.cpp doctest.h time.h movie.h timeslot.h

clean:
	rm -f main.o time.o movie.o timeslot.o tests.o 
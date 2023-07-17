main: main.o funcs.o
	g++ -o main main.o funcs.o
tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o
funcs: funcs.o
	g++ -o funcs funcs.o

main.o: main.cpp funcs.h
tests.o: tests.cpp doctest.h funcs.h
funcs.o: funcs.cpp funcs.h

clean:
	rm -f main.o tests.o funcs.o
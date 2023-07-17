main: main.o social.o network.o
	g++ -o main main.o social.o network.o
tests: tests.o social.o network.o
	g++ -o tests tests.o social.o network.o

main.o: main.cpp social.h network.h
tests.o: tests.cpp doctest.h social.h network.h
social.o: social.cpp social.h
network.o: network.cpp network.h social.h
clean:
	rm -f main.o social.o
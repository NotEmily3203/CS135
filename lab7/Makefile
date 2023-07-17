main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

unindent: unindent.o
	g++ -o unindent unindent.o

indent: indent.o
	g++ -o indent indent.o

indent.o: indent.cpp indent.h

unindent.o: unindent.cpp unindent.h

clean:
	rm -f main.o unindent.o indent.o
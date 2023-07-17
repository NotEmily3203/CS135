OBJECTS = caesar.o vigenere.o decrypt.o

main: main.o $(OBJECTS)
	g++ -o main main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ -o tests tests.o $(OBJECTS)

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

caesar: caesar.o
	g++ -o caesar caesar.o

vigenere: vigenere.o
	g++ -o vigenere vigenere.o

decrypt: decrypt.o
	g++ -o decrypt decrypt.o

caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp vigenere.h caesar.h

decrypt.o: decrypt.cpp decrypt.h

test-ascii.o: test-ascii.cpp

main.o: main.cpp $(OBJECTS)

tests.o: tests.cpp doctest.h $(OBJECTS)

clean:
	rm -f main.o $(OBJECTS) tests.o
CC=g++
LDFLAGS=-lglut -lGLU -lGL

main: main.o hangmanGame.o hangmanWord.o hangmanMan.o hangmanLexicon.o
	$(CC) hangmanGame.o hangmanWord.o hangmanMan.o hangmanLexicon.o main.o -o main $(LDFLAGS) 

main.o: main.cpp hangmanGame.h
	$(CC) main.cpp -c -o main.o

hangmanGame.o: hangmanGame.cpp hangmanGame.h
	$(CC) hangmanGame.cpp -c -o hangmanGame.o
	
hangmanMan.o: hangmanMan.cpp hangmanMan.h
	$(CC) hangmanMan.cpp -c -o hangmanMan.o

hangmanLexicon.o: hangmanLexicon.cpp hangmanLexicon.h
	$(CC) hangmanLexicon.cpp -c -o hangmanLexicon.o

hangmanWord.o: hangmanWord.cpp hangmanWord.h
	$(CC) hangmanWord.cpp -c -o hangmanWord.o

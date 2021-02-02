CCOPTIONS	= -Wall -g
CC			= g++ $(CCOPTIONS)

prog: main.o Calcul.o
	$(CC) main.o Calcul.o -o prog

prog_ok: main_ok.cpp Calcul.cpp
	$(CC) main_ok.cpp Calcul.cpp -o prog_ok


Calcul.o: Calcul.cpp Calcul.h
	$(CC) -c Calcul.cpp

main.o: main.cpp Calcul.h
	$(CC) -c main.cpp

clean:
	rm -rf *.o prog

CC = g++
OBJS_TEST = ./obj/mainTest.o ./obj/Pixel.o ./obj/Image.o
OBJS_EXEMPLE = ./obj/mainExemple.o ./obj/Pixel.o ./obj/Image.o
OBJS_AFFICHAGE = ./obj/mainAffichage.o ./obj/Pixel.o ./obj/Image.o
CFLAGS = -ggdb -Wall

all: ./bin/test ./bin/exemple ./bin/affichage

./bin/test: $(OBJS_TEST)
	$(CC) $(CFLAGS) $(OBJS_TEST) -o ./bin/test

./obj/mainTest.o: ./src/mainTest.cpp
	$(CC) $(CFLAGS) -c ./src/mainTest.cpp -o ./obj/mainTest.o

./bin/exemple: $(OBJS_EXEMPLE)
	$(CC) $(CFLAGS) $(OBJS_EXEMPLE) -o ./bin/exemple

./obj/mainExemple.o: ./src/mainExemple.cpp
	$(CC) $(CFLAGS) -c ./src/mainExemple.cpp -o ./obj/mainExemple.o

./bin/affichage: $(OBJS_AFFICHAGE)
	$(CC) $(CFLAGS) $(OBJS_AFFICHAGE) -o ./bin/affichage

./obj/mainAffichage.o: ./src/mainAffichage.cpp
	$(CC) $(CFLAGS) -c ./src/mainAffichage.cpp -o ./obj/mainAffichage.o

./obj/Pixel.o: ./src/Pixel.cpp ./src/Pixel.h
	$(CC) $(CFLAGS) -c ./src/Pixel.cpp -o ./obj/Pixel.o

./obj/Image.o: ./src/Image.cpp ./src/Image.h
	$(CC) $(CFLAGS) -c ./src/Image.cpp -o ./obj/Image.o

doc:
	doxygen doc/doxyfile

clean:
	rm ./obj/*.o
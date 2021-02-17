CC = g++
FLAGS = -ggdb -Wall

OBJS_TEST = ./obj/mainTest.o ./obj/Pixel.o ./obj/Image.o
OBJS_EXEMPLE = ./obj/mainExemple.o ./obj/Pixel.o ./obj/Image.o
OBJS_AFFICHAGE = ./obj/mainAffichage.o ./obj/Pixel.o ./obj/Image.o

# INCLUDES_DIR_SDL = -I/usr/include/SDL2 
# LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

all: ./bin/test ./bin/exemple ./bin/affichage

./bin/test: $(OBJS_TEST)
	$(CC) $(FLAGS) $(OBJS_TEST) -o ./bin/test.exe

./obj/mainTest.o: ./src/mainTest.cpp
	$(CC) $(FLAGS) -c ./src/mainTest.cpp -o ./obj/mainTest.o

./bin/exemple: $(OBJS_EXEMPLE)
	$(CC) $(FLAGS) $(OBJS_EXEMPLE) -o ./bin/exemple.exe

./obj/mainExemple.o: ./src/mainExemple.cpp
	$(CC) $(FLAGS) -c ./src/mainExemple.cpp -o ./obj/mainExemple.o

./bin/affichage: $(OBJS_AFFICHAGE)
	$(CC) $(FLAGS) $(OBJS_AFFICHAGE) -o ./bin/affichage.exe

./obj/mainAffichage.o: ./src/mainAffichage.cpp
	$(CC) $(FLAGS) -c ./src/mainAffichage.cpp -o ./obj/mainAffichage.o

./obj/Pixel.o: ./src/Pixel.cpp ./src/Pixel.h
	$(CC) $(FLAGS) -c ./src/Pixel.cpp -o ./obj/Pixel.o

./obj/Image.o: ./src/Image.cpp ./src/Image.h
	$(CC) $(FLAGS) -c ./src/Image.cpp -o ./obj/Image.o

doc:
	doxygen doc/doxyfile

clean:
	rm ./obj/*.o bin/test.exe bin/exemple.exe bin/affichage.exe
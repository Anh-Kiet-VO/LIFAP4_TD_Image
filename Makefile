CC = g++
FLAGS = -ggdb -Wall

OBJS_TEST = ./obj/mainTest.o ./obj/Pixel.o ./obj/Image.o
OBJS_EXEMPLE = ./obj/mainExemple.o ./obj/Pixel.o ./obj/Image.o
OBJS_AFFICHAGE = ./obj/mainAffichage.o ./obj/Pixel.o ./obj/Image.o

INCLUDES_DIR_SDL = -I/usr/include/SDL2 
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

all: ./bin/test ./bin/exemple ./bin/affichage

./bin/test: $(OBJS_TEST)
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL)  $(OBJS_TEST) -o ./bin/test $(LIBS_SDL)

./obj/mainTest.o: ./src/mainTest.cpp
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) -c ./src/mainTest.cpp -o ./obj/mainTest.o $(LIBS_SDL)

./bin/exemple: $(OBJS_EXEMPLE)
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) $(OBJS_EXEMPLE) -o ./bin/exemple $(LIBS_SDL)

./obj/mainExemple.o: ./src/mainExemple.cpp
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) -c ./src/mainExemple.cpp -o ./obj/mainExemple.o $(LIBS_SDL)

./bin/affichage: $(OBJS_AFFICHAGE)
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) $(OBJS_AFFICHAGE) -o ./bin/affichage $(LIBS_SDL)

./obj/mainAffichage.o: ./src/mainAffichage.cpp
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) -c ./src/mainAffichage.cpp -o ./obj/mainAffichage.o $(LIBS_SDL)

./obj/Pixel.o: ./src/Pixel.cpp ./src/Pixel.h
	$(CC) $(FLAGS) -c ./src/Pixel.cpp -o ./obj/Pixel.o 

./obj/Image.o: ./src/Image.cpp ./src/Image.h
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) -c ./src/Image.cpp -o ./obj/Image.o $(LIBS_SDL)

doc:
	doxygen -g doc/doxyfile

clean:
	rm ./obj/*.o ./bin/test ./bin/exemple ./bin/affichage
CC = g++
FLAGS = -ggdb -Wall

OBJS_TEST = ./obj/mainTest.o ./obj/Pixel.o ./obj/Image.o
OBJS_EXEMPLE = ./obj/mainExemple.o ./obj/Pixel.o ./obj/Image.o
OBJS_AFFICHAGE = ./obj/mainAffichage.o ./obj/Pixel.o ./obj/Image.o

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif

all: ./bin/test ./bin/exemple ./bin/affichage

./bin/test: $(OBJS_TEST)
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL)  $(OBJS_TEST) -o ./bin/test $(LIBS_SDL)

./obj/mainTest.o: ./src/mainTest.cpp ./src/Pixel.h ./src/Image.h
	$(CC) $(FLAGS) -c ./src/mainTest.cpp -o ./obj/mainTest.o 

./bin/exemple: $(OBJS_EXEMPLE)
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) $(OBJS_EXEMPLE) -o ./bin/exemple $(LIBS_SDL)

./obj/mainExemple.o: ./src/mainExemple.cpp ./src/Pixel.h ./src/Image.h
	$(CC) $(FLAGS) -c ./src/mainExemple.cpp -o ./obj/mainExemple.o 

./bin/affichage: $(OBJS_AFFICHAGE)
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) $(OBJS_AFFICHAGE) -o ./bin/affichage $(LIBS_SDL)

./obj/mainAffichage.o: ./src/mainAffichage.cpp ./src/Pixel.h ./src/Image.h
	$(CC) $(FLAGS) -c ./src/mainAffichage.cpp -o ./obj/mainAffichage.o 

./obj/Pixel.o: ./src/Pixel.cpp ./src/Pixel.h
	$(CC) $(FLAGS) -c ./src/Pixel.cpp -o ./obj/Pixel.o 

./obj/Image.o: ./src/Image.cpp ./src/Image.h ./src/Pixel.h
	$(CC) $(FLAGS) -c ./src/Image.cpp -o ./obj/Image.o 

doc:
	doxygen -g doc/image.doxy

clean:
	rm ./obj/*.o ./bin/*
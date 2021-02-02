OBJS_TEST = ./obj/mainTest.o ./obj/Pixel.o ./obj/Image.o
OBJS_EXEMPLE = ./obj/mainExemple.o ./obj/Pixel.o ./obj/Image.o
OBJS_AFFICHAGE = ./obj/mainAffichage.o ./obj/Pixel.o ./obj/Image.o
FLAGS = -ggdb -Wall

all: ./bin/test ./bin/exemple ./bin/affichage

./bin/test: $(OBJS_TEST)
	g++ $(FLAGS) $(OBJS_TEST) -o ./bin/test

./obj/mainTest.o: ./src/mainTest.cpp
	g++ $(FLAGS) -c ./src/mainTest.cpp -o ./obj/mainTest.o

./bin/exemple: $(OBJS_EXEMPLE)
	g++ $(FLAGS) $(OBJS_EXEMPLE) -o ./bin/exemple

./obj/mainExemple.o: ./src/mainExemple.cpp
	g++ $(FLAGS) -c ./src/mainExemple.cpp -o ./obj/mainExemple.o

./bin/affichage: $(OBJS_AFFICHAGE)
	g++ $(FLAGS) $(OBJS_AFFICHAGE) -o ./bin/affichage

./obj/mainAffichage.o: ./src/mainAffichage.cpp
	g++ $(FLAGS) -c ./src/mainAffichage.cpp -o ./obj/mainAffichage.o

./obj/Pixel.o: ./src/Pixel.cpp ./src/Pixel.h
	g++ $(FLAGS) -c ./src/Pixel.cpp -o ./obj/Pixel.o

./obj/Image.o: ./src/Image.cpp ./src/Image.h
	g++ $(FLAGS) -c ./src/Image.cpp -o ./obj/Image.o

clean:
	rm ./obj/*.o
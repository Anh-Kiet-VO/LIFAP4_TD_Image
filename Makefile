OBJS = ./obj/mainTest.o ./obj/Pixel.o ./obj/Image.o
FLAGS = -ggdb -Wall

all: ./bin/test

./bin/test: $(OBJS)
	g++ $(FLAGS) $(OBJS) -o ./bin/test

./obj/mainTest.o: ./src/mainTest.cpp
	g++ $(FLAGS) -c ./src/mainTest.cpp -o ./obj/mainTest.o

./obj/Pixel.o: ./src/Pixel.cpp ./src/Pixel.h
	g++ $(FLAGS) -c ./src/Pixel.cpp -o ./obj/Pixel.o

./obj/Image.o: ./src/Image.cpp ./src/Image.h
	g++ $(FLAGS) -c ./src/Image.cpp -o ./obj/Image.o

clean:
	rm *.o

veryclean:
	rm *
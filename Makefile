OBJS = mainTest.o Pixel.o Image.o
FLAGS = -ggdb -Wall

all: executable

executable: $(OBJS)
	g++ $(FLAGS) $(OBJS) -o executable

mainTest.o: mainTest.cpp
	g++ $(FLAGS) -c mainTest.cpp -o mainTest.o

Pixel.o: Pixel.cpp Pixel.h
	g++ $(FLAGS) -c Pixel.cpp -o Pixel.o

Image.o: Image.cpp Image.h
	g++ $(FLAGS) -c Image.cpp -o Image.o

clean:
	rm *.o

veryclean:
	rm *
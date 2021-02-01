all: executable

executable: mainTest.o Pixel.o Image.o
	g++ -g mainTest.o Pixel.o Image.o -o executable

mainTest.o: mainTest.cpp
	g++ -g -Wall -c mainTest.cpp -o mainTest.o

Pixel.o: Pixel.cpp Pixel.h
	g++ -g -Wall -c Pixel.cpp -o Pixel.o

Image.o: Image.cpp Image.h
	g++ -g -Wall -c Image.cpp -o Image.o

clean:
	rm *.o

veryclean:
	rm bin/*
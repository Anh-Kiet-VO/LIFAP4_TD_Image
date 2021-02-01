#include "Image.h"
#include <cassert>

Image::Image() {
	dimx = dimy = 0;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY) {
	assert(dimensionX >= 0 && dimensionY >= 0);
	dimx = dimensionX;
	dimy = dimensionY;
	tab = new Pixel [dimensionX*dimensionY];
}

Image::~Image() {
	delete [] tab;
	dimx = 0;
	dimy = 0;
}

Pixel Image::getPix(unsigned int x, unsigned int y) const {
	assert(x < dimx && y < dimy); 
	return tab[y * dimx + x];
}

void Image::setPix(const unsigned int x, const unsigned int y, const Pixel& couleur) {
	assert(x < dimx && y < dimx);
	tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel& couleur) {
	for(unsigned int i = Xmin ; i <= Xmax ; i++){
		for(unsigned int j = Ymin ; j <= Ymax ; j++){
			setPix(j, i, couleur);
		}
	}
}

void Image::effacer(const Pixel& couleur) {
	dessinerRectangle(0,0,dimx,dimy,couleur);
}

void Image::testRegression() {
	Image monIm (500,350);
	Pixel mesPix (254,253,252);

	assert(monIm.dimx == 500 && monIm.dimy == 350);
	assert(mesPix.getRouge() == 254 && mesPix.getVert() == 253 && mesPix.getBleu() == 252);
	
}
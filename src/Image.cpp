#include "Image.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

Image::Image() {
	dimx = dimy = 0;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY) {
	assert(dimensionX >= 0 && dimensionY >= 0);
	dimx = dimensionX;
	dimy = dimensionY;
	tab = new Pixel [dimx*dimy];
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
	assert(Xmin < Xmax && Ymin < Ymax && Xmin < dimx && Xmax <= dimx && Ymin < dimy && Ymax <= dimy);

	for(unsigned int i=Ymin; i<Ymax; i++) {
		for(unsigned int j=Xmin; j<Xmax; j++) {
			setPix(i, j, couleur);
		}
	}
}

void Image::effacer(const Pixel& couleur) {
	/* Faut mettre un assert ? */
	dessinerRectangle(0,0,dimx,dimy,couleur);
}

void Image::testRegression() {
	Image monIm (500,350);
	Pixel mesPix (31,68,50);

	assert(monIm.dimx == 500 && monIm.dimy == 350);
	assert(mesPix.getRouge() == 31 && mesPix.getVert() == 68 && mesPix.getBleu() == 50);
	
	/*monIm.*/dessinerRectangle(0, 0, 5, 5, mesPix);
	
	for(unsigned int i = 0 ; i < 5 ; i++) {
		for(unsigned int j = 0 ; j < 5 ; j++) {
			assert(getPix(i,j).getRouge() == 31);
			assert(getPix(i,j).getVert() == 68);
			assert(getPix(i,j).getBleu() == 50);
		}
	}

	effacer(mesPix);
	/* Test assert à faire */

}

void Image::sauver(const string & filename) const {
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());

    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    for (unsigned int y = 0 ; y < dimy ; y++) {
        for (unsigned int x = 0 ; x < dimx ; x++) {
            Pixel pix = getPix(x, y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());

	unsigned int r,g,b;
	string mot;

	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);

	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx * dimy];

    for(unsigned int y = 0 ; y < dimy ; y++) {
        for(unsigned int x = 0 ; x < dimx ; x++) {
            fichier >> r >> g >> b;
            getPix(x , y).setRouge(r);
            getPix(x , y).setVert(g);
            getPix(x , y).setBleu(b);
        }
	}
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole() {
    cout << "dimx = " << dimx << " ; dimy = " << dimy << endl;

	for(unsigned int x=0; x<dimx; x++) {
		for(unsigned int y=0; y<dimy; y++) {
			Pixel pix = getPix(x, y);
			cout << "[" << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << "] ";
		}
		cout << endl;
	}
}
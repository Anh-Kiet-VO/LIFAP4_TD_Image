#include "Image.h"
#include <cassert>
#include <fstream>
#include <stdlib.h>

#include <iostream>
using namespace std;

Image::Image() {
	dimx = dimy = 0;
	tab = nullptr;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY) {
	assert(dimensionX >= 0 && dimensionY >= 0);
	dimx = dimensionX;
	dimy = dimensionY;
	tab = new Pixel [dimx * dimy];
}

Image::~Image() {
	if(tab != nullptr) delete[] tab;
	dimx = 0;
	dimy = 0;
}

Pixel& Image::getPix(unsigned int x, unsigned int y) const {
	assert(x < dimx);
	assert(y < dimy);
	return tab[y * dimx + x];
}

void Image::setPix(const unsigned int x, const unsigned int y, const Pixel& couleur) {
	assert(x < dimx);
	assert(y < dimy);
	tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel& couleur) {
	assert(Xmin <= Xmax);
	assert(Xmin <= dimx);
	assert(Xmax <= dimx);
	assert(Ymin <= Ymax);
	assert(Ymin <= dimy);
	assert(Ymax <= dimy);
	for(unsigned int y = Ymin; y < Ymax; ++y) {
		for(unsigned int x = Xmin; x < Xmax; ++x) {
			setPix(x, y, couleur);
		}
	}
}

void Image::effacer(const Pixel& couleur) {
	dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression() {
	//Vérification des constructeurs
	assert(dimx >=0);
	assert(dimy >=0);

	Image monIm (10, 10);
	Pixel monPix (31, 68, 50);

	assert(monIm.dimx == 10 && monIm.dimy == 10);

	//Vérification des get
	assert(monPix.getRouge() == 31);
	assert(monPix.getVert() == 68);
	assert(monPix.getBleu() == 50);

	//Vérification des set
	monPix.setRouge(78);
	monPix.setVert(12);
	monPix.setBleu(104);

	assert(monPix.getRouge() == 78);
	assert(monPix.getVert() == 12);
	assert(monPix.getBleu() == 104);

	//Vérification de setPix et getPix
	monIm.setPix(3, 4, monPix);

	assert(monIm.getPix(3, 4).getRouge() == 78);
	assert(monIm.getPix(3, 4).getVert() == 12);
	assert(monIm.getPix(3, 4).getBleu() == 104);

	//Vérification de dessinerRectangle
	monIm.dessinerRectangle(0, 0, 5, 5, monPix);
	
	for(unsigned int i = 0; i < 5; i++) {
		for(unsigned int j = 0; j < 5; j++) {
			assert(monIm.getPix(i, j).getRouge() == 78);
			assert(monIm.getPix(i, j).getVert() == 12);
			assert(monIm.getPix(i, j).getBleu() == 104);
		}
	}

	//Vérification de effacer
	monIm.effacer(monPix);

	for(unsigned int i = 0; i < monIm.dimx; i++) {
		for(unsigned int j = 0; j < monIm.dimy; j++) {
			assert(monIm.getPix(i, j).getRouge() == 78);
			assert(monIm.getPix(i, j).getVert() == 12);
			assert(monIm.getPix(i, j).getBleu() == 104);
		}
	}
}

void Image::sauver(const string & filename) const {
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());

    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;

    for (unsigned int y = 0; y < dimy; ++y) {
        for (unsigned int x = 0; x < dimx; ++x) {
            Pixel &pix = getPix(x++, y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());

	unsigned char r, g, b;
	string mot;

	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);

	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx * dimy];

    for(unsigned int y = 0; y < dimy; y++) {
        for(unsigned int x = 0; x < dimx; x++) {
            fichier >> r >> g >> b;
            getPix(x, y).setRouge((unsigned char) r);
            getPix(x, y).setVert((unsigned char) g);
            getPix(x, y).setBleu((unsigned char) b);
        }
	}
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficher() {
	/*window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }*/
}

void Image::afficherConsole() {
    cout << "dimx = " << dimx << " ; dimy = " << dimy << endl;

	for(unsigned int x = 0; x < dimx; x++) {
		for(unsigned int y = 0; y < dimy; y++) {
			Pixel pix = getPix(x, y);
			cout << "[" << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << "] ";
		}
		cout << endl;
	}
}
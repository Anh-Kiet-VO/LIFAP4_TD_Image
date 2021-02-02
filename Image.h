#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <string>

using namespace std;

class Image{
  private:
    Pixel * tab;
    unsigned int dimx, dimy;
    
  public:
    // Constructeur par défaut de la classe: initialise dimx et dimy à 0
    // ce constructeur n'alloue pas de pixel
    Image();

    // Constructeur de la classe: initialise dimx et dimy (après vérification)
    // puis alloue le tableau de pixel dans le tas (image noire)
    Image(unsigned int dimensionX, unsigned int dimensionY);

    // Destructeur de la classe: déallocation de la mémoire du tableau de pixels
    // et mise à jour des champs dimx et dimy à 0
    ~Image();

    // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
    // la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
    Pixel getPix(unsigned int x, unsigned int y) const;

    // Mutateur : modifie le pixel de coordonnées (x,y)
    void setPix(const unsigned int x, const unsigned int y, const Pixel& couleur);

    // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
    void dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel& couleur);

    // Efface l'image en la remplissant de la couleur en paramètre
    // (en appelant dessinerRectangle avec le bon rectangle)
    void effacer(const Pixel& couleur);

    // Test regression du module Image et Pixel
    void testRegression();

    // Sauver une image dans un fichier
    void sauver(const string & filename) const;

    // Ouvrir une image depuis un fichier
    void ouvrir(const string & filename);

    // Afficher les valeurs des pixels sur la console
    void afficherConsole();
};

#endif
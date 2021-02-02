#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <string>

using namespace std;

class Image {
  private:
    /**
      @brief
        Le tableau 1D de pixel
    */
    Pixel * tab;

    /**
      @brief
       Les dimensions de l'image
    */
    unsigned int dimx, dimy;
    
  public:
    /**
      @brief
        Constructeur par défaut de la classe: initialise dimx et dimy à 
       ce constructeur n'alloue pas de pixel
    */
    Image();

    /**
      @brief
       Constructeur de la classe: initialise dimx et dimy (après vérification)
       puis alloue le tableau de pixel dans le tas (image noire)
    */
    Image(unsigned int dimensionX, unsigned int dimensionY);

    /**
      @brief
        Destructeur de la classe: déallocation de la mémoire du tableau de pixels
       et mise à jour des champs dimx et dimy à 0
    */
    ~Image();

    /**
      @brief
        Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
        la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
    */
    Pixel getPix(unsigned int x, unsigned int y) const;

    /**
      @brief
       Mutateur : modifie le pixel de coordonnées (x,y)
    */
    void setPix(const unsigned int x, const unsigned int y, const Pixel& couleur);

    /**
      @brief
        Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
    */
    void dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel& couleur);

    /**
      @brief
        Efface l'image en la remplissant de la couleur en paramètre
        (en appelant dessinerRectangle avec le bon rectangle)
    */
    void effacer(const Pixel& couleur);

    /**
      @brief
        Test regression du module Image et Pixel
    */
    void testRegression();

    /**
      @brief
       Sauver une image dans un fichier
    */
    void sauver(const string & filename) const;

    /**
      @brief
        Ouvrir une image depuis un fichier
    */
    void ouvrir(const string & filename);

    /**
      @brief
        Afficher les valeurs des pixels sur la console
    */
    void afficherConsole();

    /**
      @brief
        Affiche l'image dans une fenêtre SDL2
    */
    void afficher ();
};

#endif
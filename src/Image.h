#ifndef IMAGE_H
#define IMAGE_H
 
#include "Pixel.h"
#include <string>
 
/*
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
*/
 
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
    
    /* Pour gérer une image avec SDL2
    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;
    SDL_Window * window;
    SDL_Renderer * renderer;
    */
 
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
      @param dimensionX : entier
      @param dimensionY : entier
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
      @param x : entier
      @param y : entier
    */
    Pixel& getPix(unsigned int x, unsigned int y) const;
 
    /**
      @brief
       Mutateur : modifie le pixel de coordonnées (x,y)
      @param x : entier
      @param y : entier
      @param couleur : pixel
    */
    void setPix(const unsigned int x, const unsigned int y, const Pixel& couleur);
 
    /**
      @brief
        Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
      @param Xmin : entier
      @param Ymin : entier
      @param Xmax : entier
      @param Ymax : entier
      @param couleur : pixel
    */
    void dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel& couleur);
 
    /**
      @brief
        Efface l'image en la remplissant de la couleur en paramètre
        (en appelant dessinerRectangle avec le bon rectangle)
      @param couleur : pixel
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
      @param filename : chaine de caractères
    */
    void sauver(const string & filename) const;
 
    /**
      @brief
        Ouvrir une image depuis un fichier
      @param filename : chaine de caractères
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
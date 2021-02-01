#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <string>

class Image{
  private:
    Pixel * tab;
    unsigned int dimx, dimy;
    
  public:
    Image();
    Image(unsigned int dimensionX, unsigned int dimensionY);
    ~Image();

    Pixel getPix(unsigned int x, unsigned int y) const;
    void setPix(const unsigned int x, const unsigned int y, const Pixel& couleur);

    void dessinerRectangle(const unsigned int Xmin, const unsigned int Ymin, const unsigned int Xmax, const unsigned int Ymax, const Pixel& couleur);
    void effacer(const Pixel& couleur);

    void testRegression();

    void sauver(const string & filename) const;
    void ouvrir(const string & filename);
    void afficherConsole();
};

#endif
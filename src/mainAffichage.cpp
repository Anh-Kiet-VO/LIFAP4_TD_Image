#include "Image.h"
 
int main (int argc, char** argv) {
 
   Image image (10,10);
 
   Pixel bleu (21, 104, 219);
   Pixel orange (242, 174, 38);
   Pixel gris (229, 229, 229);
 
   image.effacer(bleu);
   image.dessinerRectangle(1, 4, 8, 5, orange);
   image.dessinerRectangle(2, 3, 6, 6, orange);
   image.dessinerRectangle(3, 2, 5, 7, orange);
   image.setPix(8,3,orange);
   image.setPix(8,6,orange);
   image.setPix(2,4,gris);
 
   image.afficher();
 
   return 0;
}

/* - - - - - - - Je sais pas c'est quoi srx - - - - - - - 
#include "Pixel.h"
#include "Image.h"
#include <iostream>

using namespace std;

int main() {
    Pixel monPixel (7, 10, 3);
    Image monImage (500, 500);
    //cout << monPixel.getRouge() << " " << monPixel.getVert() << " " << monPixel.getBleu();
    //cout << endl;
     
    monImage.dessinerRectangle(0,4,0,8,monPixel);
    
    return 0;
}
*/
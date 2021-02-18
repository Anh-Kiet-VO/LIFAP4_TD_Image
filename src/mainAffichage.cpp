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
   image.setPix(8, 3, orange);
   image.setPix(8, 6, orange);
   image.setPix(2, 4, gris);
 
   image.afficherConsole();
 
   return 0;
}
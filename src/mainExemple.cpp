#include "Image.h"
 
int main() {
 
    Pixel bleu (170, 207, 224);
    Pixel rouge (241, 47, 4);
    Pixel vert (23, 232, 37);
    Pixel noir (0, 0, 0);
 
    Image image1 (64, 48);
    image1.effacer(bleu);
    image1.dessinerRectangle(32, 24, 46, 35, rouge);
    image1.setPix(6, 10, noir);
    image1.setPix(41, 30, vert);
    image1.sauver("./data/image1.ppm");
 
    Image image2;
    image2.ouvrir("./data/image1.ppm");
    image2.dessinerRectangle(2, 2, 7, 13, vert);
    image2.dessinerRectangle(38, 18, 43, 46, noir);
    image2.sauver("./data/image2.ppm");
 
    return 0;
}
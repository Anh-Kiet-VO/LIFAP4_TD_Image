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
#include "Pixel.h"
#include <cassert>

Pixel::Pixel() {
  
  r = g = b = 0;
}

Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb) {
  r = nr;
  g = ng;
  b = nb;
}

unsigned char Pixel::getRouge() const {
  return r;
}

unsigned char Pixel::getVert() const {
  return g;
}

unsigned char Pixel::getBleu() const {
  return b;
}

void Pixel::setRouge(unsigned char rouge) {
	assert(rouge >= 0);
  r = rouge;
}

void Pixel::setVert(unsigned char vert) {
  assert(vert >= 0);
	g = vert;
}

void Pixel::setBleu(unsigned char bleu) {
  assert(bleu >= 0);
	b = bleu;
}
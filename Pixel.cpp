#include "Pixel.h"
#include <cassert>

Pixel::Pixel() {
  
  r = g = b = 0;
}

Pixel::Pixel(unsigned int nr, unsigned int ng, unsigned int nb) {
  r = nr;
  g = ng;
  b = nb;
}

unsigned int Pixel::getRouge() const {
  return r;
}

unsigned int Pixel::getVert() const {
  return g;
}

unsigned int Pixel::getBleu() const {
  return b;
}

void Pixel::setRouge(unsigned int rouge) {
	assert(rouge >= 0);
  r = rouge;
}

void Pixel::setVert(unsigned int vert) {
  assert(vert >= 0);
	g = vert;
}

void Pixel::setBleu(unsigned int bleu) {
  assert(bleu >= 0);
	b = bleu;
}
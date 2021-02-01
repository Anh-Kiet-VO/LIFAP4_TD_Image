#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
	private:
		unsigned int r, g, b;

	public:
		Pixel();
		Pixel(unsigned int nr, unsigned int ng, unsigned int nb);

		unsigned int getRouge() const;
		unsigned int getVert() const;
		unsigned int getBleu() const;

		void setRouge(unsigned int nr);
		void setVert(unsigned int nv);
		void setBleu(unsigned int nb);
};

#endif
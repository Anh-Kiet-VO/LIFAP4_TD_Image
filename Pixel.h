#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
  private:
    /**
      @brief
		    Les composantes du pixel, unsigned int en C++
		*/
    unsigned int r, g, b;

  public:
    /**
      @brief
		    Les composantes du pixel, unsigned int en C++
	  */
    Pixel();

    /**
      @brief
		    Constructeur de la classe : initialise r,g,b avec les paramètres
	  */
    Pixel(unsigned int nr, unsigned int ng, unsigned int nb);

    /**
      @brief
		   Accesseur : récupère la composante rouge du pixel
  	*/
    unsigned int getRouge() const;

    /**
      @brief
		    Accesseur : récupère la composante verte du pixel
		*/
    unsigned int getVert() const;

    /**
      @brief
		    Accesseur : récupère la composante bleue du pixel
		*/
    unsigned int getBleu() const;

    /**
      @brief
		    Mutateur : modifie la composante rouge du pixel
		*/
    void setRouge(unsigned int nr);

    /**
      @brief
		    Mutateur : modifie la composante verte du pixel
		*/
    void setVert(unsigned int nv);

    /** 
      @brief
		    Mutateur : modifie la composante bleue du pixel
		*/
    void setBleu(unsigned int nb);
};

#endif
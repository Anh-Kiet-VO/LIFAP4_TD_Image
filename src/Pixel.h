#ifndef PIXEL_H
#define PIXEL_H

class Pixel
{
  private:
    /**
      @brief
		    Les composantes du pixel, unsigned int en C++
		*/
    unsigned char r, g, b;

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
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

    /**
      @brief
		   Accesseur : récupère la composante rouge du pixel
  	*/
    unsigned char getRouge() const;

    /**
      @brief
		    Accesseur : récupère la composante verte du pixel
		*/
    unsigned char getVert() const;

    /**
      @brief
		    Accesseur : récupère la composante bleue du pixel
		*/
    unsigned char getBleu() const;

    /**
      @brief
		    Mutateur : modifie la composante rouge du pixel
		*/
    void setRouge(unsigned char nr);

    /**
      @brief
		    Mutateur : modifie la composante verte du pixel
		*/
    void setVert(unsigned char nv);

    /** 
      @brief
		    Mutateur : modifie la composante bleue du pixel
		*/
    void setBleu(unsigned char nb);
};

#endif
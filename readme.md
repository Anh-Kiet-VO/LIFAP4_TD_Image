# LIFAP4 - TD Image

À faire :
* SDL2 ==> afficher(), afficherBoucle()
=> Le poisson est handicapé / zoomDezoom de notre afficherBoucle

### Étudiants :
Kévin CUZIN (p1909458 - kevin.cuzin@etu.univ-lyon1.fr)  
Anh-Kiet VO (p1907921 - anhkiet.vo@etu.univ-lyon1.fr)  
Cécilia NGUYEN (p1908025 - cecilia.nguyen@etu.univ-lyon1.fr)

-----------------

### Module : 

Ce module permet d'afficher et de gérer une image. Celui-ci est en quelque sorte un tableau à 2 dimensions de largeur dimX et de hauteur dimY, dont les élements sont des pixels.

Organisation de l'archive :  
* /bin : Fichiers executable
* /obj : Fichiers .o
* /src : Fichiers .cpp et .h
* /doc : Documentation  

-----------------

### Compilation :

Afin de pouvoir compiler le programme, il faut utiliser le Makefile.  

Rendez-vous dans le dossier P1909458_P1907921_P1908025 :
```
cd P1909458_P1907921_P1908025
```

Puis pour compiler le programme utiliser la commande :  
```
make
```  

-----------------

### Exécution :

La compilation vous a crée 3 fichiers executable :  
* "affichage"
* "exemple"
* "test"

Pour pouvoir les exécuter rendez-vous d'abord dans le dossier /bin :
```
cd /bin
```

Pour exécuter "affichage" : 
```
./affichage
```

Pour exécuter "exemple" : 
```
./exemple
```

Pour exécuter "test" : 
```
./test
```

-----------------

### Documentation :

La documentation a été généré automatiquement via [Doxygen](https://www.doxygen.nl/index.html)  

Pour pouvoir accéder à la documentation :  
```
doxygen doc/image.doxy
```

Puis pour afficher la documentation :
```
[nom_de_votre_navigateur] doc/html/index.html
```

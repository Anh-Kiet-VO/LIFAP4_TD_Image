# LIFAP4 - TD Image

## Étudiants
Kévin CUZIN (p1909458 - kevin.cuzin@etu.univ-lyon1.fr)  
Anh-Kiet VO (p1907921 - anhkiet.vo@etu.univ-lyon1.fr)  
Cécilia NGUYEN (p1908025 - cecilia.nguyen@etu.univ-lyon1.fr)

-----------------

### Module : 

Ce module permet d'afficher et de gérer une image. Celui-ci est en quelque sorte un tableau à 2 dimensions de largeur dimX et de hauteur dimY, dont les élements sont des pixels.

Organisation de l'archive :  
* /bin : Fichiers .exe
* /obj : Fichiers .o
* /src : Fichiers .cpp et .h
* /doc : Documentation  
* /TD_Valgrind : TD Outils - Partie 2 : Gestion de mémoire/Optimisation de code

-----------------

### Compilation :

Afin de pouvoir compiler le programme, il faut utiliser le Makefile.  

Rendez-vous dans le dossier p1909458_p1907921_p1908025 :
```
cd p1909458_p1907921_p1908025
```


Il faut avoir préalablement enlevé les fichiers non compatible (.o) sinon le Makefile ne fonctionnera pas :  
```
rm ./obj/*.o
```

Puis pour compiler le programme utiliser la commande :  
```
make
```  

-----------------

### Exécution :

La compilation vous a crée 3 fichiers .exe :  
* "affichage.exe"
* "exemple.exe"
* "test.exe"

Pour pouvoir les éxecuter rendez-vous d'abord dans le dossier /bin :
```
cd /bin
```

Pour éxecuter "affichage.exe" : 
```
./affichage
```

Pour éxecuter "exemple.exe" : 
```
./exemple
```

Pour éxecuter "test.exe" : 
```
./test
```

-----------------

### Documentation :

La documentation a été généré automatiquement via [Doxygen](https://www.doxygen.nl/index.html)  

Pour pouvoir accéder à la documentation :  
```
doxygen doc/image.dox
```

Puis pour afficher la documentation :
```
[nom_de_votre_navigateur] doc/html/index.html
```

(Ou rendez-vous au chemin doc/html/index.html)


prog:text.o indice.o cinematique.o logo.o main.o jeu.o trigo.o col.o map.o personage.o enemie.o main.o 
	gcc text.o indice.o cinematique.o logo.o jeu.o trigo.o col.o map.o personage.o enemie.o main.o -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
personage.o: personage.c
	gcc -c personage.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
Map.o: map.c
	gcc -c map.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
enemie.o: enemie.c
	 gcc -c enemie.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
col.o: col.c
	gcc -c col.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
trigo.o: trigo.c
	gcc -c trigo.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c 
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
jeu.o:jeu.c 
	gcc -c jeu.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
logo.o:logo.c 
	gcc -c logo.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
cinematique.o:cinematique.c 
	gcc -c cinematique.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
text.o: text.c
	gcc -c text.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
indice.o: text.c
	gcc -c indice.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
 
 
 

 

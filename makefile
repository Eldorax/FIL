tokenize.exe: elementArbre.o main.o arbre.o encodage.o modele.o arg.o
	g++ -Wall elementArbre.o arbre.o encodage.o modele.o main.o arg.o -o tokenize.exe
	#./tokenize.exe lexique.txt train.fr

main.o: main.cpp elementArbre.h arbre.h encodage.h modele.h arg.h
	g++ -std=c++11 -Wall -c main.cpp -o main.o

Arbre: arbre.cpp arbre.h elementArbre.h encodage.h
	g++ -Wall -c arbre.cpp -o arbre.o

elementArbre.o: elementArbre.cpp elementArbre.h
	g++ -Wall -c elementArbre.cpp -o elementArbre.o

encodage.o: encodage.cpp encodage.h
	g++ -Wall -c encodage.cpp -o encodage.o

modele.o: modele.h modele.cpp
	g++ -std=c++11 -Wall -c modele.cpp -o modele.o
	
arg.o: arg.h arg.cpp
	g++ -std=c++11 -Wall -c arg.cpp -o arg.o

codetomot.exe: codetomot.c
	g++ -Wall -o codetomot.exe codetomot.c

test: tokenize.exe codetomot.exe
	./tokenize.exe lexique.txt train.fr | ./codetomot.exe lexique.txt

clean:
	rm -f *.o *~ *.exe

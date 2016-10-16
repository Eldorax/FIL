tokenize.exe: elementArbre.o main.o arbre.o encodage.o codetomot.exe
	g++ -Wall elementArbre.o arbre.o encodage.o main.o -o tokenize.exe
	./tokenize.exe lexique.txt train.fr

main.o: main.cpp elementArbre.h arbre.h encodage.h
	g++ -Wall -c main.cpp -o main.o

Arbre: arbre.cpp arbre.h elementArbre.h encodage.h
	g++ -Wall -c arbre.cpp -o arbre.o

elementArbre.o: elementArbre.cpp elementArbre.h
	g++ -Wall -c elementArbre.cpp -o elementArbre.o

encodage.o: encodage.cpp encodage.h
	g++ -Wall -c encodage.cpp -o encodage.o

codetomot.exe: codetomot.c
	gcc -Wall -o codetomot.exe codetomot.c

test: tokenize.exe codetomot.exe
	./tokenize.exe lexique.txt train.fr | ./codetomot.exe lexique.txt

clean:
	rm -f *.o *~ *.exe

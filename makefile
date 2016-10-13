COMP=g++


main.exe: elementArbre.o main.o arbre.o encodage.o
	g++ -Wall elementArbre.o arbre.o encodage.o main.o -o main.exe
	./main.exe

main.o: main.cpp elementArbre.h arbre.h encodage.h
	g++ -Wall -c main.cpp -o main.o

Arbre: arbre.cpp arbre.h elementArbre.h encodage.h
	g++ -Wall -c arbre.cpp -o arbre.o

elementArbre.o: elementArbre.cpp elementArbre.h
	g++ -Wall -c elementArbre.cpp -o elementArbre.o

encodage.o: encodage.cpp encodage.h
	g++ -Wall -c encodage.cpp -o encodage.o

clean:
	rm -f *.o *~ *.exe

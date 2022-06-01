
arithprog_make : addmake.o mainmake.o	#final executable is depenedent on 2 files#
	gcc -o arithprog_make addmake.o mainmake.o 	
	
addmake.o : add.c
	gcc -c -o addmake.o add.c

mainmake.o : main.c
	gcc -c -o mainmake.o main.c

clean :
	rm -f addmake.o mainmake.o arithprog_make

sectiondemo : sectionsdemo.o add.o
	gcc -o sectiondemo sectionsdemo.c add.c

add.o : add.c
	gcc -c -o add.o add.c

sectionsdemo.o : sectionsdemo.c
	gcc -c -o sectionsdemo.o sectionsdemo.c

clean :
	rm -f sectiondemo sectionsdemo.o add.o

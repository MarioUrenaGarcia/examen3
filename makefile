#Este es el archivo de makefile para (appGTK.c)

appGTK.exe: appGTK.o funC.o funGTK.o
	gcc appGTK.o funC.o funGTK.o -o appGTK.exe `pkg-config --libs gtk+-2.0`

funGTK.o: funGTK.c defGTK.h
	gcc -c funGTK.c `pkg-config --cflags gtk+-2.0`

funC.o: funC.c defGTK.h
	gcc -c funC.c `pkg-config --cflags gtk+-2.0`

appGTK.o: appGTK.c defGTK.h
	gcc -c appGTK.c `pkg-config --cflags gtk+-2.0`

#Este es el archivo de makefile para (NOMBRE DEL ARCHIVO PRINCIPAL)

plantilla.exe: app.o funC.o funGTK.o
	gcc app.o funC.o funGTK.o -o app.exe `pkg-config --libs gtk+-2.0`

funGTK.o: funGTK.c defPlantilla.h
	gcc -c funGTK.c `pkg-config --cflags gtk+-2.0`

funC.o: funC.c defPlantilla.h
	gcc -c funC.c `pkg-config --cflags gtk+-2.0`

app.o: app.c defPlantilla.h
	gcc -c app.c `pkg-config --cflags gtk+-2.0`

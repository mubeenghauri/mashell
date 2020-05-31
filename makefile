# makefile for materm.c

materm: mashell.c materm.c
	gcc -o mashell mashell.c
	gcc -Wall -o materm materm.c `pkg-config --cflags --libs gtk+-3.0 vte-2.91`

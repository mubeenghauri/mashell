# makefile for materm.c

# mashell: mashell.c
	# gcc -o mashell mashell.

materm: materm.c
	gcc -Wall -o materm materm.c `pkg-config --cflags --libs gtk+-3.0 vte-2.91`

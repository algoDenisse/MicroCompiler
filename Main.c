#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
#include "scanner.c"

// HOLAAAAAA
int main( int argc, char *argv[] )
{
	open_file(); // esta en scanner.h
	if (file) {
		printf("Abri el archivo. \n");
		read_file();
		close_file();
	}
	else{
		printf("Problema al abrir el archivo. \n");
	}
	
	
}
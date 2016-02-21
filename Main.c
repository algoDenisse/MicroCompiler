#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
#include "scanner.c"

// HOLAAAA
int main( int argc, char *argv[] )
{
	read_file();
	// Leer buffer
	//fwrite(file_buffer , 1 , len , stdout);
	close_file();

	scan();
	free(file_buffer);

	
}

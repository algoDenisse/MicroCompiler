#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
#include "scanner.c"
#include "parser.c"

// HOLAAAA
int main( int argc, char *argv[] )
{
	int i;
	get_tokens();
	// Leer buffer
	
	close_file();

	free(file_buffer);
	free(token_buffer);

	//fwrite( reserved_words_array, 1 , 4, stdout);
	 // prueba de compilacion
	statement();
}

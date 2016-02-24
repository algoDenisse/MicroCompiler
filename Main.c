#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
#include "scanner.c"
#include "parser.c"

// HOLAAAA
int main( int argc, char *argv[] )
{
	int i;
	read_file();

	//get_tokens();
	// Leer buffer
	next_token();
	system_goal();
	//match(INTLITERAL);
	//match(BEGIN);
	close_file();

	free(file_buffer);
	free(token_buffer);

	//fwrite( reserved_words_array, 1 , 4, stdout);
	 // prueba de compilacion
	//statement();
}

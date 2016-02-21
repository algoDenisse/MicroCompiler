#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>

int main( int argc, char *argv[] )
{
	FILE *file;
	int len, c, filePos;
	char *token_buffer;

	if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else{
    	// agarra archivo desde la consola
    	file = fopen( argv[1], "r" );
		if (file) {
			// Buscar la posicion final del archivo
			fseek(file, 0, SEEK_END);
			// Obtener el tamanno del archivo
			len = ftell(file);
			/* GUardar memoria para todo el contenido */
			token_buffer = malloc(sizeof(char) *(len+1));
			if(!token_buffer) fclose(file), fputs("memory alloc fails",stderr),exit(1);
			// BUscar la posicion inicial del archivo
			filePos = fseek(file, 0L, SEEK_SET);
			printf("Inicio del archivo: %d\n", filePos);

			// Llena buffer con los ch del archivo
			while ((c = getc(file)) != EOF)
	        	token_buffer[filePos++] = c;
			
	  		token_buffer[filePos++] = '\0'; //Agreagarle final de texto
	  		// Leer buffer
	  		fwrite(token_buffer , 1 , len , stdout);

	  		memset(token_buffer, 0, len);
	  		printf("YA limpie el buffer\n");

	  		fwrite(token_buffer , 1 , len , stdout);

		    fclose(file);
		    free(token_buffer);
		 }
	  
	   	return(0);

    }

}
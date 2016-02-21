#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
#include "scanner.h"

void open_file(){
   char filename [100]="";
   printf( "Enter a value :");
   scanf("%s",filename);
   file = fopen( filename, "r" );		
}

void read_file(){
	// ingresa la totalidad del archivo en el file_buffer
	open_file();
	if (file) {
		// Buscar la posicion final del archivo
		fseek(file, 0, SEEK_END);
		// Obtener el tamanno del archivo
		len = ftell(file);
		len_token_buffer = len;
		/* GUardar memoria para todo el contenido */
		file_buffer = malloc(sizeof(char) *(len+1));
		token_buffer= malloc(sizeof(char) *(len+1));
		if(!file_buffer) fclose(file), fputs("memory alloc fails",stderr),exit(1);
		// BUscar la posicion inicial del archivo
		filePos = fseek(file, 0L, SEEK_SET);
		
		// Llena buffer con los ch del archivo
		while ((c = getc(file)) != EOF)
	       	file_buffer[filePos++] = c;		
	  	file_buffer[filePos++] = '\0'; //Agreagarle final de texto
	  	// Inicializamos la posicion incial del file_buffer
	  	filePos = 0;
	  	// Inicializamos la posicion incial del token_buffer
	  	charPos = 0; 

	}
	else{
		printf("Problema al abrir el archivo. \n");
	}
}


int get_next_char(){
	int chr = file_buffer[filePos++];
	return chr;
}

void close_file(){
	fclose(file);
}

void buffer_char(char c){
	token_buffer[charPos++] = c;
	printf("CharPos --> %d\n", charPos);
}

void clear_buffer_char(){
	memset(token_buffer, 0, len);
}

token check_reserved(){
	return END;
}
void scan(void){
	int in_char, i;
	clear_buffer_char();

	if(file_buffer[0] == 0) printf("Archivo vacio.\n");

	for(i = 0; i <= len; i++){
		in_char = get_next_char();
		if(isspace(in_char)){
			continue;
		} 
		else if (isalpha(in_char)){
			buffer_char(in_char);
		}
	}
	for (i = 0; i <=len_token_buffer; i++){
		printf("%d\n", token_buffer[i] );
	}

/*	while ((in_char = get_next_char()) != EOF){
		if(isspace(in_char)) continue;
		else if (isalpha(in_char)){
			//buffer_char(in_char);
			printf("es letraaa");
		}

	} */
//	for(i = 0; i < 4; i++){
//		in_char = get_next_char();
//		printf("La pos actual del file_buffer: %d\n", in_char);
//	}

	//printf(" Dato ingresado %d\n", in_char ); 
	//if (feof(in_char)){

	//}
}
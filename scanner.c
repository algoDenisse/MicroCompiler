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
	//Meter los caracteres al buffer hasta que encuentre un espacio en blanco.
	token_buffer[charPos++] = c;	
}

void clear_token_buffer(){
	memset(token_buffer, 0, len);
	charPos = 0;
}

token check_reserved(){
	int letter, c;
	bool reserved;
	//Recorrer el token buffer, revisando su primera letra
	for(letter= 0; letter < len_tb; letter++){
		if ( 'B'== toupper(token_buffer[letter])){
			reserved = true;
			for(c = 0; c < 5; c++){
				if (begin_buffer[c] != toupper(token_buffer[letter++])){
					reserved = false;
					break;
				}
			}
			if(reserved == true){
				printf("1. es un BEGIN\n");
				return BEGIN;
			}else{
				printf("es un ID\n");
				return ID;
			}

			break;
		}else if ('E' == toupper(token_buffer[letter])){
			reserved = true;
			for(c = 0; c < 3; c++){
				if (end_buffer[c] != toupper(token_buffer[letter++])){
					reserved = false;
					break;
				}
			}
			if(reserved == true){
				printf("2. es un END\n");
				return END;
			}else{
				printf("es un ID\n");
				return ID;
			}
			break;
		}else if ('W' == toupper(token_buffer[letter])){
			reserved = true;
			for(c = 0; c < 5; c++){
				if (write_buffer[c] != toupper(token_buffer[letter++])){
					reserved = false;
					break;
				}
			}
			if(reserved == true){
				printf("3. es un WRITE\n");
				return WRITE;
			}else{
				printf("es un ID\n");
				return ID;
			}
			break;
		}else if ('R' == toupper(token_buffer[letter])){
			reserved = true;
			for(c = 0; c < 4; c++){
				if (read_buffer[c] != toupper(token_buffer[letter++])){
					reserved = false;
					break;
				}
			}
			if(reserved == true){
				printf("4. es un READ\n");
				return READ;
			}else{
				printf("es un ID\n");
				return ID;
			}
			break;
		}else{
			printf("es un ID\n");
			return ID;
		}
	}
}
token scan(void){
	int in_char, i;
	clear_token_buffer();

	//Si el primer caracter del file_buffer es 0, entonces el archivo esta vacio
	if(file_buffer[0] == 0) printf("Archivo vacio.\n");

	//Mientras no encuentre un fin del archivo
	while ((in_char = get_next_char()) != '\0'){ 
		if(isspace(in_char)){
			continue;
		} 
		else if (isalpha(in_char)){
			len_tb = 0;
			//printf("PALABRA\n" );
			buffer_char(in_char);
			len_tb++; // Aumenta variable que me indicara el tamanno del token buffer.
			for (c = get_next_char(); isalnum(c) || c == '_'; c = get_next_char()){
				buffer_char(c);
				len_tb++;
			}
			filePos--; // para que no se coma el siguiente ch despues de haber llenado el buffer
			return check_reserved();
			//break;
		}
		else if (isdigit(in_char)){
			printf("DIGITO\n");
			buffer_char(in_char);
			for (c = get_next_char(); isalnum(c) || c == '_'; c = get_next_char()){
				buffer_char(c);
			}
			filePos--;
			return INTLITERAL;
		}
		else if(in_char == '('){
			printf("PARENTESIS DERECHO %d\n", in_char);
			return LPAREN;
		
		}else if(in_char == ')'){
			printf("PARENTESIS IZQUIERDO %d\n", in_char);
			return RPAREN;


		}else if(in_char == ';'){
			printf("PUNTO Y COMMA %d\n", in_char);
			return SEMICOLON;

		}else if(in_char == ','){
			printf("COMMA %d\n", in_char);
			return COMMA;

		}else if(in_char == '+'){
			printf("MAS %d\n", in_char);
			return PLUSOP;
		}else if (in_char == ':'){
			//Buscando a '='
			c = get_next_char();
			if(c == '='){
				//break
				printf("ASSIGNACION %d\n",in_char + c);
				return ASSIGNOP;
			}else{
				printf("LEXICAL ERRORRRRRRRRRRRR%d\n", in_char);
				break;
			}

		}else if(in_char == '-'){
			//Buscando el inicio del comentario --
			c = get_next_char();
			if (c == '-'){
				do{
					in_char = get_next_char();
					
				}while (in_char != '\n'); 
				printf("COMMENTARIO\n");
				break;
				//SE CAE SI NO HAY CAMBIO DE LINEA

			}else{
				printf("MENOS %d\n",in_char);
				return MINUSOP;
			}
		}else{
			printf("LEXICAL ERROR %d\n", in_char);
			break;
		}

	}
}

void print_token_buffer(){
	int i;
	printf("IMPRIMIENDO TOKEN BUFFER\n");
	//Prueba para ver que hay en el token_buffer.
	for (i = 0; i <=len_token_buffer; i++){
		printf("%d\n", token_buffer[i] );
	}
}

void get_tokens(){
	read_file();
	token ejemplo;
	while(filePos != len){
		ejemplo = scan();
		printf("token %d\n", ejemplo );
	}

}

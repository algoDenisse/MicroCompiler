#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
#include "scanner.h"

void open_file(){
   char filename [100]="";
   printf( "Enter a value : ");
   scanf("%s",filename);
   file = fopen( filename, "r" );		
}

void read_file(){
	open_file();
	if (file){
		len = ftell(file);
		//token_buffer= malloc(sizeof(char) *(len+1));
	}
	else{
		printf("Problema al abrir el archivo\n");
		exit(0);
	}
	
}


void close_file(){
	fclose(file);
}

void buffer_char(char c){
	token_buffer[charPos++] = c;	
}

void clear_token_buffer(){
	memset(token_buffer, 0, 5);
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
				return BEGIN;
			}else{
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
				return END;
			}else{
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
				return WRITE;
			}else{
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
				return READ;
			}else{
				return ID;
			}
			break;
		}else{
			return ID;
		}
	}
}
token scanner(void){
	int in_char, i;
	clear_token_buffer();

	if (feof(file)){
		return SCANEOF;
	}
		//Mientras no encuentre un fin del archivo
	len_tb = 0;//tamanno del buffer
	while ((in_char = getc(file)) != EOF){ 
		if(isspace(in_char)){
			continue;
		} 
		else if (isalpha(in_char)){
			
			buffer_char(in_char);
			len_tb++; // Aumenta variable que me indicara el tamanno del token buffer.
			for (c = getc(file); isalnum(c) || c == '_'; c = getc(file)){
				buffer_char(c);
				len_tb++;
			}
			ungetc(c, file);// para que no se coma el siguiente ch despues de haber llenado el buffer
			return check_reserved();
		}
		else if (isdigit(in_char)){
			buffer_char(in_char);
			for (c = getc(file); isalnum(c) || c == '_'; c = getc(file)){
				buffer_char(c);
			}
			ungetc(c, file);
			return INTLITERAL;
		}
		else if(in_char == '('){
			printf("PARENTESIS DERECHO %d\n", in_char);
			return LPAREN;
		
		}else if(in_char == ')'){
			printf("PARENTESIS IZQUIERDO %d\n", in_char);
			return RPAREN;


		}else if(in_char == ';'){
			return SEMICOLON;

		}else if(in_char == ','){
			return COMMA;

		}else if(in_char == '+'){
			return PLUSOP;
		}else if (in_char == ':'){
			//Buscando a '='
			c = getc(file);
			if(c == '='){
				return ASSIGNOP;
			}else{
				lexical_error(in_char);
				break;
			}

		}else if(in_char == '-'){
			//Buscando el inicio del comentario --
			c = getc(file);
			if (c == '-'){
				do{
					in_char = getc(file);
				
					
				}while (in_char != '\n'); 
				

			}else{
				ungetc(c, file);
				return MINUSOP;
			}
		}else{
			lexical_error(in_char);
			break;
		}

	}
		
}

void lexical_error(int character){
	printf("LEXICAL ERROR %d\n", character);
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
		ejemplo = scanner();
		printf("token %d\n", ejemplo );
	}

}

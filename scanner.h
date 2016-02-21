#ifndef SCANNER_H
#define SCANNER_H
#endif

#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
/*--Definicion de variables-----------------------------------------------------------------------------------------------*/
FILE *file;
int len, len_token_buffer, c, filePos, charPos;
char *file_buffer;
char *token_buffer;



/*Representa el conjunto de tipos de tokens*/
typedef enum token_types{
	BEGIN,END,READ,WRITE,ID,INTLITERAL,LPAREN,RPAREN,SEMICOLON,COMMA,
	ASSIGNOP,PLUSOP,MINUSOP,SCANEOF
} token;
/*------------------------------------------------------------------------------------------------------------------------*/

/*--Definicion de Funciones-----------------------------------------------------------------------------------------------*/

extern token scanner(void); // Produce un stream de representaciones de tokes

void open_file();

void read_file();

int get_next_char();

void close_file();

void buffer_char(char c);
 
void clear_buffer_char();

token check_reserved();

void scan(void);

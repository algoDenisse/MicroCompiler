#ifndef SCANNER_H
#define SCANNER_H
#endif

#include <stdio.h>
#include <string.h> /* memset */
#include <stdlib.h>
#include "global.h" /*datos globales*/
/*--Definicion de variables-----------------------------------------------------------------------------------------------*/
FILE *file;
int len, len_token_buffer, c, comment_char, filePos, charPos,len_tb;
char *token_buffer;
char begin_buffer[5] = "BEGIN";
char end_buffer[3] = "END";
char read_buffer[4] = "READ";
char write_buffer[5] = "WRITE";

/*Representa el conjunto de tipos de tokens*/
/*typedef enum token_types{
	BEGIN,END,READ,WRITE,ID,INTLITERAL,LPAREN,RPAREN,SEMICOLON,COMMA,
	ASSIGNOP,PLUSOP,MINUSOP,SCANEOF
} token;
------------------------------------------------------------------------------------------------------------------------
typedef enum {false=0, true=1} bool;*/
/*--Definicion de Funciones-----------------------------------------------------------------------------------------------*/

extern token scanner(void); // Produce un stream de representaciones de tokes

void open_file();

void read_file();

void close_file();

void buffer_char(char c);
 
void clear_token_buffer();

token check_reserved();

void print_token_buffer();

void get_tokens();

int get_token_len();

void lexical_error();

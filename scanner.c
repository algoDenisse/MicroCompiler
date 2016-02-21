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
	while ((c = getc(file)) != EOF)
		 putchar(c);
}

void close_file(){
	fclose(file);
}

void buffer_char(char c){
	token_buffer[filePos++] = c;
}

void clear_buffer_char(){
	memset(token_buffer, 0, len);
}

token check_reserved(){
	return END;
}
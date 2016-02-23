#ifndef PARSER_H
#define PARSER_H
#endif

//#include "global.h" /*datos globales*/

/*--------------------------------------------------------------------------------------------------------------------------------------*/

void statement();
void id_list();
void expression();
void expr_list();
void add_op();
void primary();

/*--------------------------*/
token next_token();
void match(token t);
void sintax_error(token t);
#ifndef PARSER_H
#define PARSER_H
#endif

//#include "global.h" /*datos globales*/

/*--------------------------------------------------------------------------------------------------------------------------------------*/

void statement(void);
void id_list(void);
void expression(void);
void expr_list(void);
void add_op(void);
void primary(void);
void program(void);
void system_goal(void);
void statement_list(void);

/*--------------------------*/
token next_token();
void match(token t);
void sintax_error(token t);
token current_token;
#ifndef PARSER_H
#define PARSER_H
#endif

//#include "global.h" /*datos globales*/
#define MAXIDLEN 33
typedef char string[MAXIDLEN];


char symbol_table[1024][1024];

/*for operators*/
typedef struct operator {
	enum op {PLUS,MINUS} operator;
} op_rec;

/*expression types*/
enum expr{IDEXPR,LITERALEXPR,TEMPEXPR};

/*for <primary> and <expression>*/
typedef struct expression{
	enum expr kind;
	union{
		string name; /*for IDEXPR,TEMPEXPR*/
		int val; /*for LITERALEXPR*/

	};
}expr_rec;

/*--------------------------------------------------------------------------------------------------------------------------------------*/

void statement(void);
void id_list(void);
void expression (expr_rec *result);
void expr_list(void);
void add_op(op_rec* p_operand);
void primary(expr_rec* p_operand);
void program(void);
void system_goal(void);
void statement_list(void);

/*--------------------------*/
token next_token();
void match(token t);
void sintax_error(token t);
token current_token;
token nextev_token;
token previous_currentToken;

const char * get_token_name(token t);

//Semanctic Records for micro grammar symbols

/*---------------Definicion de Rutinas Semanticas------------*/

char *symbols[9];
void start();
void finish();
void ident();
void assign(expr_rec target,expr_rec source);
op_rec process_op();
expr_rec gen_infix(expr_rec e1,op_rec op,expr_rec e2);
void read_id(expr_rec in_var);
expr_rec process_id();
expr_rec process_literal(void);
op_rec  process_op(void);

void write_expr(expr_rec out_expr);
//void expression(expr_rec *result);
bool lookup(string s);
void check_id(string s);
void enter(string s);

void generate();
void extract();

void open_outputFile();
void close_outputFile();

/*Variables necesarias*/
FILE *output_file;
int symTable_count = 0;
char previous_tokenbuffer[5];
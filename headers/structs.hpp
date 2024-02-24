#ifndef STRUCTS_HPP
# define STRUCTS_HPP

#include <iostream>

typedef enum e_type
{
	MOV,
	ADD,
	SUB,
	DIV,
	MUL,
	INC,
	DEC,
	REG,
	MEM,
	COMMA,
	LITERAL,
	NEW_LINE
}	I_type;

/* Instruction Set*/
/*					  [0] [1] [2]*/
/* str::string[n] ->  mov rax  5 */
typedef struct s_Instruction
{
	/* data */
	struct s_Instruction *next;
	struct s_Instruction *prev;
}	Instruction;

typedef struct s_Analyse
{
	int			Priority;
	I_type		type;
	std::string	Token;
	struct s_Analyse *next;
	struct s_Analyse *prev;
}	Analyse;

void			lstback(Instruction **pars, Instruction* add);
int				lstsize(Instruction *lst);
Instruction*	lstlast(Instruction *lst);
Instruction*	lstadd( void );

void		lstback(Analyse **pars, Analyse* add);
int			lstsize(Analyse *lst);
Analyse*	lstlast(Analyse *lst);
Analyse*	lstadd(std::string Tok, int Priority, I_type type);

#endif
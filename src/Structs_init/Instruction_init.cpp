#include "structs.hpp"

void			lstback(Instruction **pars, Instruction *add);
int				lstsize(Instruction *lst);
Instruction*	lstlast(Instruction *lst);
Instruction*	lstadd( void );

Instruction* lstadd( void )
{
	Instruction	*res;

	if (!(res = (Instruction *)malloc(sizeof(Instruction))))
		return NULL;
	res->next = NULL;
	res->prev = NULL;
	return res;
}

void	lstback(Instruction **pars, Instruction *add)
{
	Instruction	*tmp;

	tmp = lstlast(*pars);
	if (!tmp)
		*pars = add;
	else
	{
		tmp->next = add;
		add->prev = tmp;
	}
}

Instruction* lstlast(Instruction *lst)
{
	Instruction	*tmp;

	tmp = lst;
	if (!tmp)
		return NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return tmp;
}

int	lstsize(Instruction *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		(lst) = (lst)->next;
	}
	return i;
}
#include "structs.hpp"


Analyse* lstadd(std::string	Tok, int Priority, I_type type)
{
	Analyse	*res;

	if (!(res = (Analyse *)malloc(sizeof(Analyse))))
		return NULL;
	res->Priority = Priority;
	res->Token = Tok;
	res->type = type;
	res->next = NULL;
	res->prev = NULL;
	return res;
}

void	lstback(Analyse **pars, Analyse *add)
{
	Analyse	*tmp;

	tmp = lstlast(*pars);
	if (!tmp)
		*pars = add;
	else
	{
		tmp->next = add;
		add->prev = tmp;
	}
}

Analyse	*lstlast(Analyse *lst)
{
	Analyse	*tmp;

	tmp = lst;
	if (!tmp)
		return NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return tmp;
}

int	lstsize(Analyse *lst)
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
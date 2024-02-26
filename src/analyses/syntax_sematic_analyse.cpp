#include "Analyses.hpp"

void analyse_instructions(Analyse *pars)
{
	for (Analyse *tmp = pars; tmp; tmp = tmp->next)
	{
		if (tmp->type == ERROR)
		{
			throw AnalyseExc(tmp->Token, ERROR);
		}
	}
}

void	syntax_sematic_analyse(Analyse *pars)
{
	try
	{
		analyse_instructions(pars);
	}
	catch(AnalyseExc& ex)
	{
		if (ex.getFlag() == ERROR)
			ex.not_instruction();
	}
	
}
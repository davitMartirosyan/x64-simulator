#include "Lexical.hpp"
#include <fstream>

void check_instructions(Analyse** list, std::string tok);

Analyse* lexical_analyse(std::string filename)
{
	Analyse *list;
	std::string tok;
	std::ifstream fin;
	try
	{
    	fin.open(filename);
	}
	catch (const std::exception& exp)
	{
		std::cout << "Can't open File." << std::endl;\
	}
	while (!fin.eof())
	{
		std::getline(fin, tok);
		int pos = tok.find(' ', 0);
		if (pos != -1)
		{
			check_instructions(&list, tok.substr(0, pos));
			tok = tok.substr(pos + 1, tok.length());
		}
		pos = tok.find(',', 0);
		if (pos != -1)
		{
			check_instructions(&list, tok.substr(0, pos));
			check_instructions(&list, tok.substr(pos, 1));
			check_instructions(&list, tok.substr(pos + 1, tok.length()));
			if (tok[tok.length()] != '\0')
				check_instructions(&list, "\n");
			continue ;
		}
		check_instructions(&list, tok.substr(0, tok.length()));
		if (tok[tok.length()] != '\0')
			check_instructions(&list, "\n");
		tok = "";
	}
	for (Analyse *tmp = list; tmp; tmp = tmp->next)
	{
		std::cout << "Token : " + tmp->Token;
		std::cout << "| Priority : " << tmp->Priority;
		std::cout << "| Type : " << tmp->type << std::endl;
	}
	return list;
}

void check_instructions(Analyse** list, std::string tok)
{
	if (tok == "mov")
		lstback(list, lstadd(tok, 3, MOV));
	else if (tok == "add")
		lstback(list, lstadd(tok, 3, ADD));
	else if (tok == "sub")
		lstback(list, lstadd(tok, 3, SUB));
	else if (tok == "div")
		lstback(list, lstadd(tok, 3, DIV));
	else if (tok == "mul")
		lstback(list, lstadd(tok, 3, MUL));
	else if (tok == "inc")
		lstback(list, lstadd(tok, 3, INC));
	else if (tok == "dec")
		lstback(list, lstadd(tok, 3, DEC));
	else if (tok == "rax" || tok ==  "rbx" || tok == "rcx" || tok == "rdx" || tok == "rsi" \
										|| tok ==  "rdi" || tok == "rsp" || tok == "rbp")
		lstback(list, lstadd(tok, 2, REG));
	else if (tok == "[arr]")
		lstback(list, lstadd(tok, 2, MEM));
	else if (tok == ",")
		lstback(list, lstadd(tok, 1, COMMA));
	else if (tok == "\n")
		lstback(list, lstadd(tok, 1, ERROR));
	else
		lstback(list, lstadd(tok, 0, ERROR));
}


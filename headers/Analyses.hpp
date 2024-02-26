#ifndef ANALYSES_HPP
# define ANALYSES_HPP

#include "structs.hpp"

class AnalyseExc : public std::exception
{
private:
	int flag;
	std::string Token;
public:
	AnalyseExc(){};
	AnalyseExc(std::string &Token, int flag){this->Token = Token;this->flag = flag;};
	std::string& getToken(){return this->Token;} const
	int getFlag() {return this->flag;}
	void not_instruction() const
	{
		std::cout << "There are no instructions : " << '"' + this->Token + "\"." << std::endl;
	}
};

Analyse*	lexical_analyse(std::string file);
void		syntax_sematic_analyse(Analyse *pars);


#endif
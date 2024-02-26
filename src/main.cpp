#include "blink.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "BUS.hpp"
#include "structs.hpp"
#include "Analyses.hpp"
#include <string>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error !!!" << std::endl;
        return 1;
    }
    std::string filename = av[1];
    if (filename.length() < 4 ||  filename.compare(filename.length() - 4, 4, ".asm"))
    {
        std::cout << "Error File Name !!!" << std::endl;
		return 1;
    }
    std::cout << "BOOT Loader" << std::endl;
    CPU cpu;
    RAM ram;
    Analyse *pars;
	pars = lexical_analyse(filename);
	syntax_sematic_analyse(pars);
    return (0);
}
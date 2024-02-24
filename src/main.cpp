#include "blink.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "BUS.hpp"
#include "structs.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::cout << "BOOT Loader" << std::endl;
    CPU cpu;
    RAM ram;
    Analyse *pars;

    lstback(&pars, lstadd("Hello", 2, MOV));
    lstback(&pars, lstadd("World", 1, ADD));

    std::cout << "Tok : " << pars->Token << ", Prioryti : " << pars->Priority << ", Enum : " << pars->type << std::endl;
    std::cout << "Tok : " << pars->next->Token << ", Prioryti : " << pars->next->Priority << ", Enum : " << pars->next->type << std::endl;
    
    return (0);
}
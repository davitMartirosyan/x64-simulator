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
    Instruction *Set;

    lstback(&pars, lstadd("mov", 2, MOV));
    lstback(&pars, lstadd("rax", 1, REG));
    lstback(&pars, lstadd("5", 0, LITERAL));
    lstback(&pars, lstadd("\n", 0, NEW_LINE));

    lstback(&pars, lstadd("mov", 2, MOV));
    lstback(&pars, lstadd("rbx", 1, REG));
    lstback(&pars, lstadd("10", 0, LITERAL));
    lstback(&pars, lstadd("\n", 0, NEW_LINE));

    lstback(&pars, lstadd("add", 2, ADD));
    lstback(&pars, lstadd("rax", 1, REG));
    lstback(&pars, lstadd("rbx", 1, REG));
    lstback(&pars, lstadd("\n", 0, NEW_LINE));

    Analyse *tmp = pars;
    lstback(&Set, lstadd(tmp));
    std::cout << Set->line[0] + "  " << Set->line[1] + " " << Set->line[2] << Set->line[3];
    for (int i = 0; i < 4; ++i)
        tmp = tmp->next;
    lstback(&Set, lstadd(tmp));
    std::cout << Set->next->line[0] + "  " << Set->next->line[1] + " " << Set->next->line[2] << Set->next->line[3];
    for (int i = 0; i < 4; ++i)
        tmp = tmp->next;
    lstback(&Set, lstadd(tmp));
    std::cout << Set->next->next->line[0] + "  " << Set->next->next->line[1] + " " << Set->next->next->line[2] << Set->next->next->line[3];
    return (0);
}
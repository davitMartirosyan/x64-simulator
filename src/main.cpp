#include "blink.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "BUS.hpp"
#include "structs.hpp"
#include "Analyses.hpp"

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

// int main(int ac, char** av)
// {
//     CPU cpu;
//     BUS bus;
//     RAM ram;

//     ram.load("mov rax, 5");
//     // ram.load("mov rbx,6");
//     // ram.load("add rax,rbx");
//     size_t cicle = 0;
//     while (cicle < ram.getLastInstructionAddress())
//     {
//         cpu.setCBus(0);
//         bus.control_bus(cpu, ram);
//         bus.data_bus(cpu, ram);
//         // bus.address_bus(cpu, ram);
//         cicle++;
//     }
    
//     // bus.data_bus(cpu, ram);
// }
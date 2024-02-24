#include "blink.hpp"
#include "CPU.hpp"
#include "RAM.hpp"
#include "BUS.hpp"

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    std::cout << "BOOT Loader" << std::endl;
    CPU cpu;
    RAM ram;
    
    return (0);
}
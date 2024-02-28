#include "CPU.hpp"

CPU::CPU( void ) : cBus(0)
{
    // std::cout << "Central Processing Unit is ready" << std::endl;
}

CPU::~CPU()
{
    
}

int CPU::getCBus( void )
{
    return (cBus);
}

void CPU::setCBus(int cbus)
{
    cBus = cbus;
}
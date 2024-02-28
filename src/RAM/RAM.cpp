#include "RAM.hpp"

RAM::RAM( void ) : address(0)
{
    // std::cout << "RAM is Ready" << std::endl;
    
}

RAM::~RAM()
{
    
}

int RAM::getLastInstructionAddress( void )
{
    return (address);
}

void RAM::load(std::string const &instruction)
{
    ins.push_back(instruction);
    address++;
}

std::string const &RAM::fetch(int addr)
{
    return (ins[addr]);
}
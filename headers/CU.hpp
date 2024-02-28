#ifndef CU_HPP
#define CU_HPP
#include "blink.hpp"

/*
Instruction Set

        mov reg, lit        add reg, lit         sub reg, lit          mul reg, lit          div reg, lit           inc reg
        mov reg, reg        add reg, reg         sub reg, reg          mul reg, reg          div reg, reg           dec reg
        mov reg, mem        add reg, mem         sub reg, mem          mul reg, mem          div reg, mem
        mov mem, reg        add mem, reg         sub mem, reg          mul mem, reg          div mem, reg
        mov mem, mem        add mem, mem         sub mem, mem          mul mem, mem          div mem, mem

*/

class CU
{
    public:
        CU( void );
        ~CU();
    public:
        void decoder(std::string const &instruction);
    private:
        // std::map<std::string, Instruction> instructionSet;
    public:
        void mov(int* r1, int lit);
        void mov(int* r1, int* r2);
        void mov(int* reg, long int* mem);
        void mov(long int* mem, int *reg);
        void mov(long int* mem1, long int* mem2);
    public:
        void add(int* r1, int lit);
        void add(int* r1, int* r2);
        void add(int* reg, long int* mem);
        void add(long int* mem, int *reg);
        void add(long int* mem1, long int* mem2);
};

#endif
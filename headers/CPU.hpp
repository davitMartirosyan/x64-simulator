#ifndef CPU_HPP
#define CPU_HPP
#include "blink.hpp"
#include "ALU.hpp"
#include "CU.hpp"

/*
Instruction Set

        mov reg, lit        add reg, lit         sub reg, lit          mul reg, lit          div reg, lit           inc reg
        mov reg, reg        add reg, reg         sub reg, reg          mul reg, reg          div reg, reg           dec reg
        mov reg, mem        add reg, mem         sub reg, mem          mul reg, mem          div reg, mem
        mov mem, reg        add mem, reg         sub mem, reg          mul mem, reg          div mem, reg
        mov mem, mem        add mem, mem         sub mem, mem          mul mem, mem          div mem, mem

*/

class CPU : public ALU, public CU
{
    public:
        CPU( void );
        ~CPU();
    private:
        int rip;
    private:
        int rax;
        int rbx;
        int rcx;
        int rdx;
    private:
        int rdi;
        int rsi;
    private:
        int rsp;
        int rbp;
    private:
        int r[7];
    private:
        int xmm[8];
	private:
		int rflags[16];
    private:
};

#endif

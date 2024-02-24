#ifndef CPU_HPP
#define CPU_HPP
#include "blink.hpp"
#include "ALU.hpp"
#include "CU.hpp"
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
// inherit from CU (Control Unit) class
// inherit from ALU (Arithmetic Control Unit) class

#endif

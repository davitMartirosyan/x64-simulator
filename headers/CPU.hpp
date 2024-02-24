#ifndef CPU_HPP
#define CPU_HPP

class CPU : public ALU
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
}
// inherit from CU (Control Unit) class
// inherit from ALU (Arithmetic Control Unit) class

#endif

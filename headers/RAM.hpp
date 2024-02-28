#ifndef RAM_HPP
#define RAM_HPP
#include "blink.hpp"

class RAM
{
    public:
        RAM( void );
        ~RAM();
    private:
        int address; // prefix -> 0x value starts from 0 to ... | example 0x0, 0x1, 0x2
        //std::vector<Instruction>    // struct of linked list of instructions
        // std::vector<std::vector<std::string> > ins;
        std::vector<std::string> ins;
        /*
        [       [0]    [1]  [2]
          1 -> "mov", "rax", "5",
          2 -> "add", "rax", "10"
        ]
        */
    public:
      int getLastInstructionAddress( void );
      void load(std::string const &instruction);
      std::string const &fetch(int addr);
};

#endif

#ifndef BUS_HPP
#define BUS_HPP
#include "blink.hpp"
#include "CPU.hpp"
#include "RAM.hpp"

class BUS
{
	public:
		BUS( void );
		~BUS();
	public:
		void data_bus(CPU const &cpu, RAM const &ram);
		void address_bus(CPU const &cpu, RAM const &ram);
		void control_bus(CPU const &cpu, RAM const &ram);
};

#endif

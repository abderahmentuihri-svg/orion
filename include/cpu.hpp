#pragma once

#include <cstdint>
#include "bus.hpp"

// main cpu struct
struct cpu_t {
	bus_t* bus = new bus_t;
	
	uint8_t a, x, y, p, sp,
		opcode, data_bus;

	uint16_t pc, addr_bus;

	bool reset;
	bool irq;
	bool nmi;
	bool prev_nmi;
	bool instr_complete;

	uint8_t cycles;
	uint8_t instr_size;
	
	void reset_cpu();
	void handle_nmi();
	void handle_irq();
	void clock();
};

// load helper functions
void load_a(cpu_t* cpu, uint8_t value);
void load_x(cpu_t* cpu, uint8_t value);
void load_y(cpu_t* cpu, uint8_t value);

// transfer helper functions
void tax(cpu_t* cpu);
void tay(cpu_t* cpu);
void tsx(cpu_t* cpu);
void txa(cpu_t* cpu);
void txs(cpu_t* cpu);
void tya(cpu_t* cpu);

// store helper functions
void store_a(cpu_t* cpu);
void store_x(cpu_t* cpu);
void store_y(cpu_t* cpu);

// flag setting helper functions
void set_c();
void set_z();
void set_i();
void set_d();
void set_b();
void set_v();
void set_n();

// flag clearing helper functions
void clear_c();
void clear_z();
void clear_i();
void clear_d();
void clear_b();
void clear_v();
void clear_n();

#include "../cpu/cpu.h"
#include "bus.h"
void write(uint16_t address, cpu_t *cpu){
	cpu->data_bus=mem[address];
}
uint8_t read(uint16_t address){
	return mem[address];
}

#include "memory.h"
uint8_t memory_t::read(uint32_t address){
	if (address<=0x401000){
		return ram[address];
	}
	else if (address<=0x409000){
		return rom[address-0x401000];
	}
	else if (address>409000){
		assert(false && "out-of-bounds mem read");
	}
}
void memory_t::write(uint32_t address,uint8_t value){
	if (address<=0x401000){
		ram[address]=value;
	}
}

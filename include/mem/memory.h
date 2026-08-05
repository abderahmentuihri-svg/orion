#pragma once
#include <cstdint>
#include <cassert>
struct memory_t {
	uint8_t ram[0x401000];//all the ram, 4MB+16KB
	uint8_t rom[0x8000];
	uint8_t read(uint32_t address);
	void write(uint32_t address,uint8_t value);
};

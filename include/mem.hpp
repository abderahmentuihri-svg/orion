#pragma once
#include <cstdint>
#include <cassert>
#define FRAM_START 0x000000 // Fixed RAM
#define FRAM_SIZE  0x4000
#define FRAM_END   0x003FFF

#define BRAM_START 0x004000 // Banked RAM physical storage
#define BANK_SIZE  0x4000
#define BRAM_SIZE  0x400000 // 4 MB total
#define BRAM_END   0x403FFF

#define ROM_START  0x404000
#define ROM_SIZE   0x8000
#define ROM_END    0x40BFFF
struct memory_t {
    uint8_t ram[0x404000]; // 4MB + 16KB
    uint8_t rom[0x8000];   // 32KB
    uint8_t read(uint32_t address);
    void write(uint32_t address, uint8_t value);
};

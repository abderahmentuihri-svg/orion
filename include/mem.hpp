#pragma once
#include <cstdint>
#include <cassert>

#define FRAM_START 0x000000 // Fixed RAM
#define FRAM_SIZE  0x8000
#define FRAM_END   0x007FFF

#define BRAM_START 0x008000 // Banked RAM physical storage
#define BANK_SIZE  0x7000
#define BRAM_SIZE  0x700000 // 7 MB total
#define BRAM_END   0x6FFFFF

#define ROM_START  0x700000
#define ROM_SIZE   0x1000
#define ROM_END    0x700FFF

struct memory_t {
    uint8_t ram[0x708000]; // 32 KB fixed + 7 MB banked
    uint8_t rom[0x1000];   // 4 KB

    uint8_t read(uint32_t address);
    void write(uint32_t address, uint8_t value);
};

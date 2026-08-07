#pragma once
#include "mem.hpp"
struct bus_t {
    memory_t* mem;
    void write(uint16_t address, uint8_t value);
    uint8_t read(uint16_t address);
};

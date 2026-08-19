#pragma once
#include "mem.hpp"
struct bus_t {
    memory_t* mem = new memory_t;
    void write(uint16_t address, uint8_t value);
    uint8_t read(uint16_t address);
};

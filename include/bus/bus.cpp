#include "bus.h"
#include "../mem/memory.h"
#include <cassert>

void bus_write(uint16_t address, uint8_t value, memory_t& mem){
    if (address < 0x4000){
        // fixed RAM
        mem.write(address, value);
    }
    else if (address < 0x8000){
        // banked RAM
        uint32_t bank = mem.read(0x3FFF);
        uint32_t offset = address - 0x4000;
        mem.write(bank * 16384 + offset, value);
    }
    else{
        assert(false && "write to ROM");
    }
}

uint8_t bus_read(uint16_t address, memory_t& mem){
    if (address < 0x4000){
        return mem.read(address);
    }
    else if (address < 0x8000){
        uint32_t bank = mem.read(0x3FFF);
        uint32_t offset = address - 0x4000;
        return mem.read(bank * 16384 + offset);
    }
    else if (address <= 0xFFFF){
        // ROM
        return mem.read(0x401000 + (address - 0x8000));
    }
    else{
        assert(false && "segmentation fault");
        return 0;
    }
}

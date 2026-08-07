#include "../include/bus/bus.h"
#include <cassert>
void bus_t::write(uint16_t address, uint8_t value){
    if (address < 0x4000){
        // fixed RAM
        mem->write(address, value);
    }
    else if (address < ROM_SIZE){
        // banked RAM
        uint8_t bank = mem->read(0x3FFF);
        uint32_t offset = address - 0x4000;

        mem->write(bank * 16384 + offset, value);
    }
    else{
        // ROM
        assert(false && "error: write to ROM");
    }
}

uint8_t bus_t::read(uint16_t address){
    if (address < 0x4000){
        // fixed RAM
        return mem->read(address);
    }
    else if (address < ROM_SIZE){
        // banked RAM
        uint8_t bank = mem->read(0x3FFF);
        uint32_t offset = address - 0x4000;

        return mem->read(bank * 16384 + offset);
    }
    else{
        // ROM
        return mem->read(RAM_SIZE + (address - ROM_SIZE));
    }
}

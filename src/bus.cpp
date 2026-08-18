#include "../include/bus.hpp"
#include <cassert>

void bus_t::write(uint16_t address, uint8_t value) {
    if (address < 0x8000) {
        // Fixed RAM
        mem->write(address, value);
    }
    else if (address < 0xF000) {
        // Banked RAM
        uint8_t bank = mem->read(0x7FFF);
        uint32_t offset = address - 0x8000;

        mem->write(
            FRAM_SIZE + bank * BANK_SIZE + offset,
            value
        );
    }
    else {
        // ROM
        assert(false && "error: write to ROM");
    }
}

uint8_t bus_t::read(uint16_t address) {
    if (address < 0x8000) {
        // Fixed RAM
        return mem->read(address);
    }
    else if (address < 0xF000) {
        // Banked RAM
        uint8_t bank = mem->read(0x7FFF);
        uint32_t offset = address - 0x8000;

        return mem->read(
            FRAM_SIZE + bank * BANK_SIZE + offset
        );
    }
    else {
        // ROM
        return mem->read(
            ROM_START + (address - 0xF000)
        );
    }
}

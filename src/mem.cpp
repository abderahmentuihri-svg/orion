#include "../include/mem.hpp"
uint8_t memory_t::read(uint32_t address){
    if (address < ROM_START){
        return ram[address];
    }
    else if (address < (ROM_SIZE+ROM_START)){
        return rom[address - ROM_START];
    }
    else{
        assert(false && "segmentation fault");
        return 0;
    }
}

void memory_t::write(uint32_t address, uint8_t value){
    if (address < ROM_START){
        ram[address] = value;
    }
    else{
        assert(false && "write to ROM");
    }
}

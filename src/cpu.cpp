#include "../include/cpu.hpp"
#include "../include/bus.hpp"

// these are all just helper functions, NOT THE ACTUAL OPCODES THIS PROJECT USES

// power-on/reset sequence
void cpu_t::reset_cpu() {
    switch (cycles) {
        case 1:
            break;

        case 2:
            addr_bus++;
            break;

        case 3:
            addr_bus = sp + 0x100;
            break;

        case 4:
            addr_bus = (sp - 1) + 0x100;
            break;

        case 5:
            addr_bus = (sp - 2) + 0x100;
            break;

        case 6:
            addr_bus = 0xfffc;
            pc = bus->read(addr_bus);
            break;

        case 7:
            addr_bus = 0xfffd;
            pc = bus->read(addr_bus) << 8;
            cycles = 0;
            break;
    }
}

// NMI
void cpu_t::handle_nmi() {
    // todo: handle nmi
}

// clock
void cpu_t::clock() {
    if (!reset) {
        reset_cpu();
        instr_complete = true;
    }

    else if ((!nmi) && prev_nmi && instr_complete) {
        instr_complete = false;
    }

    else if (!irq && !(p & 4) && instr_complete) {
        instr_complete = false;
    }

    else {
        opcode = bus;
    }

    cycles++;
    return;
}

// load helper functions
void load_a(cpu_t* cpu, uint8_t value) {
    cpu->a = value;
}

void load_a_addr(cpu_t* cpu) {
    cpu->a = cpu->data_bus;
}

void load_x(cpu_t* cpu, uint8_t value) {
    cpu->x = value;
}

void load_x_addr(cpu_t* cpu) {
    cpu->x = cpu->data_bus;
}

void load_y(cpu_t* cpu, uint8_t value) {
    cpu->y = value;
}

void load_y_addr(cpu_t* cpu) {
    cpu->y = cpu->data_bus;
}

// transfer helper functions
void tax(cpu_t* cpu) {
    cpu->x = cpu->a;
}

void tay(cpu_t* cpu) {
    cpu->y = cpu->a;
}

void tsx(cpu_t* cpu) {
    cpu->x = cpu->sp;
}

void txa(cpu_t* cpu) {
    cpu->a = cpu->x;
}

void txs(cpu_t* cpu) {
    cpu->sp = cpu->x;
}

void tya(cpu_t* cpu) {
    cpu->a = cpu->y;
}

// store helper functions
void store_a(cpu_t* cpu) {
    cpu->data_bus = cpu->a;
}

void store_x(cpu_t* cpu) {
    cpu->data_bus = cpu->x;
}

void store_y(cpu_t* cpu) {
    cpu->data_bus = cpu->y;
}

// flag setting helper functions
void set_c(cpu_t* cpu) {
    cpu->p |= 0b00000001;
}

void set_z(cpu_t* cpu) {
    cpu->p |= 0b00000010;
}

void set_i(cpu_t* cpu) {
    cpu->p |= 0b00000100;
}

void set_d(cpu_t* cpu) {
    cpu->p |= 0b00001000;
}

void set_b(cpu_t* cpu) {
    cpu->p |= 0b00010000;
}

void set_v(cpu_t* cpu) {
    cpu->p |= 0b01000000;
}

void set_n(cpu_t* cpu) {
    cpu->p |= 0b10000000;
}

// flag clearing helper functions
void clear_c(cpu_t* cpu) {
    cpu->p &= ~(0b00000001);
}

void clear_z(cpu_t* cpu) {
    cpu->p &= ~(0b00000010);
}

void clear_i(cpu_t* cpu) {
    cpu->p &= ~(0b00000100);
}

void clear_d(cpu_t* cpu) {
    cpu->p &= ~(0b00001000);
}

void clear_b(cpu_t* cpu) {
    cpu->p &= ~(0b00010000);
}

void clear_v(cpu_t* cpu) {
    cpu->p &= ~(0b01000000);
}

void clear_n(cpu_t* cpu) {
    cpu->p &= ~(0b10000000);
}            

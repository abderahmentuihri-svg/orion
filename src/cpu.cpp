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
	    instr_complete = true;
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
	instr_complete = false;
        reset_cpu();
        instr_complete = true;
    }

    else if ((!nmi) && prev_nmi && instr_complete) {
        instr_complete = false;
    }

    else if (!irq && !(p & 4) && instr_complete) {
        instr_complete = false;
    }

    else if (cycles == 0) {
        opcode = bus->read(pc);
	pc++;
	cycles++;
    }
    else{
	switch(opcode){
		case 0x0A:
			bus->read(pc);
			if (a&0b10000000) {
				set_c();
			}
			a<<=1;
			if (a==0) {
				set_z();
			}
			if (a&0b10000000) {
				set_n();
			}
			break;
		case 0x4A:
			bus->read(pc);
			if (a&0b10000000) {
				set_c();
			}
			a<<=1;
			if (a==0) {
				set_z();
			}
			if (a&0b10000000) {
				set_n();
			}
			break;
		case 0x2A:
			bus->read(pc);
			if (a&0b1000000) {
				set_c();
			}
			a <<= 1;
			a |= p & 0b00000001;
			if (a==0) {
				set_z();
			}
			if (a&0b10000000) {
				set_n();
			}
			break;
		case 0x6A:
			bus->read(pc);
			if (a&0b00000001){
				set_c();
			}
			a >>= 1;
			a |= p & 0x80;
			if (a == 0) {
				set_z();
			}
			if (a&0x80){
				set_n();
			}
			break;
		case 0x18:
			bus->read(pc);
			clear_c();
			break;
		case 0xD8:
			bus->read(pc);
			clear_d();
			break;
		case 0x58:
			clear_i();
			break;
		case 0xB8:
			clear_v();
			break;
		case 0x38:
			set_c();
			break;
		case 0xF8:
			set_d();
			break;
		case 0x78:
			set_i();
			break;
		case 0xAA:
			tax();
			if (x==0){
				set_z();
			}
			if (x&0x80){
				set_n();
			}
			break;
		case 0xA8:
			tay();
			if (y==0){
				set_z();
			}
			if (y&0x80){
				set_n();
			}
			break;
		case 0xBA:
			tsx();
			if (x==0){
				set_z();
			}
			if (x&0x80){
				set_n();
			}
			break;
		case 0x8A:
			txa();
			if (a==0){
				set_z();
			}
			if (a&0x80){
				set_n();
			}
			break;
		case 0x9A:
			txs();
			if (sp==0){
				set_z();
			}
			if (sp & 0x80){
				set_n();
			}
			break;
		case 0x98:
			tya();
			if (a==0){
				set_z();
			}
			if (a & 0x80){
				set_n();
			}
			break;
		case 0xEA:
			bus->read(pc);
			break;
		case 0xCA:
			bus->read(pc);
			x--;
			if (x==0){
				set_z();
			}
			if (x&0x80){
				set_n();
			}
			break;
		case 0x88:
			bus->read(pc);
			y--;
			if (x==0){
				set_z();
			}
			if (x&0x80){
				set_n();
			}
			break;
		case 0xE8:
			x++;
			if (x==0){
				set_z();
			}

    }

    cycles++;
    return;
}

// load helper functions
void load_a(uint8_t value) {
    a = value;
}

void load_x(uint8_t value) {
    x = value;
}

void load_y(uint8_t value) {
    y = value;
}


// transfer helper functions
void tax() {
    x = a;
}

void tay() {
    y = a;
}

void tsx() {
    x = sp;
}

void txa() {
    a = x;
}

void txs() {
    sp = x;
}

void tya() {
    a = y;
}

// store helper functions
void store_a() {
    data_bus = a;
}

void store_x() {
    data_bus = x;
}

void store_y(cpu_t* cpu) {
    cpu->data_bus = cpu->y;
}

// flag setting helper functions
void set_c() {
    p |= 0b00000001;
}

void set_z() {
    p |= 0b00000010;
}

void set_i() {
    p |= 0b00000100;
}

void set_d() {
    p |= 0b00001000;
}

void set_b() {
    p |= 0b00010000;
}

void set_v() {
    p |= 0b01000000;
}

void set_n() {
    p |= 0b10000000;
}

// flag clearing helper functions
void clear_c() {
    p &= ~(0b00000001);
}

void clear_z() {
    p &= ~(0b00000010);
}

void clear_i() {
    p &= ~(0b00000100);
}

void clear_d() {
    p &= ~(0b00001000);
}

void clear_b() {
    p &= ~(0b00010000);
}

void clear_v() {
    p &= ~(0b01000000);
}

void clear_n() {
    p &= ~(0b10000000);
}            

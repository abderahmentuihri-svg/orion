#include <cstdint>
#pragma once
enum cpu_state
{
    FETCH,
    EXECUTE,
    RESET,
    INTERRUPT
};
//main cpu struct
//--------------------------------------
struct cpu_t{			      //|
uint8_t a,x,y,p,sp,temp1,temp2,	      //|
	opcode,data_bus;	      //|
cpu_state state;		      //|
	uint16_t pc,addr_bus;         //|
	bool reset;		      //|
	uint8_t cycles;		      //|
	void reset_cpu();	      //|
};				      //|  
//--------------------------------------
//load helper functions
//------------------------------------------
void load_a(cpu_t*cpu,uint8_t value);    //|
void load_x(cpu_t*cpu,uint8_t value);    //|
void load_y(cpu_t*cpu,uint8_t value);    //|
//------------------------------------------
//transfer helper functions
//---------------------
void tax(cpu_t*cpu);//|
void tay(cpu_t*cpu);//|
void tsx(cpu_t*cpu);//|
void txa(cpu_t*cpu);//|
void txs(cpu_t*cpu);//|
void tya(cpu_t*cpu);//|
//---------------------
//store helper functions
//-------------------------
void store_a(cpu_t*cpu);//|
void store_x(cpu_t*cpu);//|
void store_y(cpu_t*cpu);//|
//-------------------------
//flag setting helper functions
//-----------------------
void set_c(cpu_t*cpu);//|
void set_z(cpu_t*cpu);//|
void set_i(cpu_t*cpu);//|
void set_d(cpu_t*cpu);//|
void set_b(cpu_t*cpu);//|
void set_v(cpu_t*cpu);//|
void set_n(cpu_t*cpu);//|
//-----------------------
//flag clearing helper functions
//-------------------------
void clear_c(cpu_t*cpu);//|
void clear_z(cpu_t*cpu);//|
void clear_i(cpu_t*cpu);//|
void clear_d(cpu_t*cpu);//|
void clear_b(cpu_t*cpu);//|
void clear_v(cpu_t*cpu);//|
void clear_n(cpu_t*cpu);//|
//-------------------------

#include "../include/cpu.hpp"
#include "../include/bus.hpp"
#include "../include/mem.hpp"
int main(){
	cpu_t cpu;
	while (true){
		if (!cpu.reset){
			cpu.reset_cpu();
		}
		else if (prev_nmi && !nmi){
			//nmi logic
		}
		else if (!irq){
			//irq logic
		}
		else{//main instruction cycle
			cpu.addr_bus=PC;
			data_bus=cpu.bus->bus_read(addr_bus);
		}
		cycles++;
	}
	return 0;
}


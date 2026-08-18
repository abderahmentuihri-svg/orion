#include "../include/cpu.hpp"
#include "../include/bus.hpp"
#include "../include/mem.hpp"
int main(){
	cpu_t cpu;
	while (1){
		cpu.clock();
	}
	return 0;
}


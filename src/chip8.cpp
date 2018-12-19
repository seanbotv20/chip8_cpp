#include "chip8.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <array>

Chip8::Chip8() {
	state = UNLOADED;
	programCounter = PROGRAM_START;
	memory = MemoryManager();
}

void Chip8::load_program(std::vector<char> program) {
	for(int i = 0; i < program.size(); i++) {
		this->memory.writeMemory(PROGRAM_START + i, program[i]);
	}

	this->state = LOADED;
}

void Chip8::run() {

	std::cout << "STARTING PROGRAM\n";

	for(;;) {
		unsigned char command = this->memory.getMemory(this->programCounter);
		this->advance_counter();

		std::cout << "0x" << std::hex << (unsigned int)command << std::endl;

		usleep(10000);
	}

	std::cout << "END OF PROGRAM" << '\n';
}

void Chip8::advance_counter() {
	this->programCounter++;

	if (programCounter > MAX_MEMORY_SIZE)
		programCounter = PROGRAM_START;
}
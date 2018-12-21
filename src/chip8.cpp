#include "chip8.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <vector>
#include <array>

Chip8::Chip8() : display(DEFAULT_DISPLAY_WIDTH, DEFAULT_DISPLAY_HEIGHT) {
	state = UNLOADED;
	programCounter = PROGRAM_START;
}

void Chip8::load_program(std::vector<char> program) {
	for(unsigned int i = 0; i < program.size(); i++) {
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

		usleep(1000);
	}

	std::cout << "END OF PROGRAM" << '\n';
}

void Chip8::advance_counter() {
	this->programCounter++;

	if (programCounter > MAX_MEMORY_SIZE)
		programCounter = PROGRAM_START;
}

void Chip8::run_instruction(unsigned char instruction) {

	// Most commands are defined by the most significant nibble
	switch( instruction >> 12) {
		case 0x0:
			
			break;
		case 0x1:
			break;
		default:
			break;
	}
}

//void Chip8::run_instruction_
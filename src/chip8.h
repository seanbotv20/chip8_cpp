#include "MemoryManager.h"

#ifndef CHIP8_H
#define CHIP8_H

#define MAX_MEMORY_SIZE 0xFFF
#define PROGRAM_START 0x200

enum state {UNLOADED, LOADED, RUNNING, AWAITING};

class Chip8 {

	public:
		Chip8();
		void run();
		void load_program(std::vector<char> program);

	private:
		enum state state;
		MemoryManager memory;
		int programCounter;

		void advance_counter();
};

#endif
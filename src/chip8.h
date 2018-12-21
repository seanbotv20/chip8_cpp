#include "MemoryManager.h"
#include "Display.h"

#ifndef CHIP8_H
#define CHIP8_H

#define MAX_MEMORY_SIZE 0xFFF
#define PROGRAM_START 0x200

#define DEFAULT_DISPLAY_WIDTH 64
#define DEFAULT_DISPLAY_HEIGHT 32

enum state {UNLOADED, LOADED, RUNNING, AWAITING};

class Chip8 {

	public:
		Chip8();
		void run();
		void load_program(std::vector<char> program);

	private:
		enum state state;
		int programCounter;

		MemoryManager memory;
		Display display;

		void advance_counter();
		void run_instruction(unsigned char instruction);
};

#endif
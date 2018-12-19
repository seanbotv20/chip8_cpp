#include <iostream>
#include <fstream>
#include <vector>
#include "chip8.h"

std::vector<char> load_file(char filepath[]) {
	std::ifstream file;
	file.open(filepath, std::ios::binary | std::ios::ate);

	if (file.good()) {
		int size = file.tellg();
		char* data = new char[size];

		file.seekg(0);
		file.read(data, size);
		file.close();

		std::vector<char> program = std::vector<char>(size);

		// Common pattern for assignment from array
		program.assign(data, data + size);

		return program;
	}

	std::cout << "Couldn't open file: " << filepath << "n";
	return std::vector<char>();
}

int main(int argc, const char *argv[])
{
	if (argc > 1) {
		Chip8 emulator = Chip8();

		std::vector<char> data = load_file( (char*)argv[1] );

		if (data.size() > 0) {
			emulator.load_program(data);
			emulator.run();
		}

		std::cout << "Program data loaded\n";
		return 1;
	}

	std::cout << "No program specified\n";
	return 1;
}
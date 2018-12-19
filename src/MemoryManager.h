#include <map>
#include <vector>


#ifndef MEMORY_H
#define MEMORY_H

class MemoryManager {

	public:
		MemoryManager();
		char getMemory(int address);
		void writeMemory(int address, char data);
		void writeManyMemory(int address, std::vector<char> data);
		void clearMemory(int address);
		void clearAllMemory();

	private:
		std::map<int,char> memoryMap;
};

#endif
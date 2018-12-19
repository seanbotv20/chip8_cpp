#include "MemoryManager.h"

MemoryManager::MemoryManager() {
	memoryMap = std::map<int,char>();
}

char MemoryManager::getMemory(int address) {

	auto search = this->memoryMap.find(address);

	if (search != this->memoryMap.end())
		return search->second;

	return 0x00;
}

void MemoryManager::writeMemory(int address, char data) {
	this->memoryMap.insert_or_assign(address, data);
}

void MemoryManager::writeManyMemory(int address, std::vector<char> data) {
	for (const auto &datum : data) {
		this->writeMemory(address, datum);
		address++;
	}
}

void MemoryManager::clearMemory(int address) {
	this->memoryMap.erase(address);
}

void MemoryManager::clearAllMemory() {
	this->memoryMap.clear();
}

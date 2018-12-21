#include "Register.h"

#define 8_BIT_MAX 0xFF
#define 16_BIT_MAX 0xFFFF


Register::Register(Bits bits) {
	this->bits = bits;
	this->value = 0;
}

void Register::setValue(int value) {
	if (bits == 8_BITS)
		this->value = (value & 8_BIT_MAX);
	else if (bits == 6_BITS)
		this->value = (value & ~16_BIT_MAX)
}

int Register::getValue() {
	return this->value;
}

void Register::increment(int amount = 1) {
	this->value += amount;

	if (bits == 8_BITS && (unsigned int)this->value > 8_BIT_MAX)
		this->value = 0;
	else if (bits == 16_BITS && (unsigned int)this->value > 16_BIT_MAX)
		this->value = 0;

}

void Register::decrement(int amount = 1) {
	this->value -= amount;

	if (bits == 8_BITS && (unsigned int)this->value > 8_BIT_MAX)
		this->value = 0;
	else if (bits == 16_BITS && (unsigned int)this->value > 16_BIT_MAX)
		this->value = 0;

}
#ifndef REGISTER_H
#define REGISTER_H

enum Bits {8_BIT, 16_BIT};

class Register {
	public:
		Register(Bits bits);
		void setValue(int value);
		int getValue();
		void increment(int amount = 1);
		void decrement(int amount = 1);

	private:
		Bits bits;
		int value;
}

#endif
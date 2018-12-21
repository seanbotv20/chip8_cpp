#include "Display.h"

Display::Display(int width, int height) :framebuffer(width, (std::vector<bool>(height, false)) ) {
	this->width = width;
	this->height = height;
}

void Display::clear() {
	for( std::vector<bool>& row : this->framebuffer )
		for(int i = 0; i < row.size(); i++)
			row[i] = false;
		// for(auto& column : row)
			// column = false;
}

bool Display::displaySprite(std::vector<char> sprite, int x, int y) {
	return false;
}

bool Display::writePixel(int x, int y, bool value) {
	bool erased = !(this->framebuffer[x][y] ^ value); // XNOR gives us if the pixel will be erased

	this->framebuffer[x][y] = this->framebuffer[x][y] ^ value; //XOR equals

	return erased;
}
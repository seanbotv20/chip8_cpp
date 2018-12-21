#include <vector>

#ifndef DISPLAY_H
#define DISPLAY_H


class Display {

	public: 
		Display(int width, int height);
		void clear();
		bool displaySprite(std::vector<char> sprite, int x, int y);
	private:
		bool writePixel(int x, int y, bool value);

		std::vector< std::vector<bool> > framebuffer;
		int height;
		int width;
};

#endif
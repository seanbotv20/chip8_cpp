# chip8
A C++ chip8 emulator/interpreter

Chip-8 is a theoretical micro-computer including an instruction set, input system, display and audio.
This is an experiment in emulator writing using the C++11 standard.

Currently all it does is load a program into memory and then print the instructions indefinitely.

## Building
I've tested the build system and program on MinGW, your milage may vary.
```mkdir Build
cd Build
cmake ..```

## Running

Chip8 accepts chip8 programs in raw format (8-bit instructions in little endian)

`chip8 "<path to chip8 program>"`

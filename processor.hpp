#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <iostream>
#include <array>
#include "r_types.hpp"

#define REGISTER_COUNT 32
#define MEMORY_SIZE 200

class Processor {
    public:
    std::array<u32, REGISTER_COUNT> registers = {0};
    std::array<u32, MEMORY_SIZE> memory = {0};

    u16 program_counter = -1;

    i32 fetch_instruction() {
        program_counter++;
        return memory[program_counter];
    }

    u0 execute_instruction(u32 instruction) {
        u32 opcode = instruction & 0b111111;

        switch (opcode) {
            case 0b000000: {
                // R-Type instruction

                u32 rs = (instruction >> 6) & 0b11111;
                u32 rt = (instruction >> 11) & 0b11111;
                u32 rd = (instruction >> 16) & 0b11111;
                u32 shift = (instruction >> 21) & 0b11111;
                u32 funct = (instruction >> 26) & 0b111111;

                switch (funct) {
                    case 0b100000: {
                        // add instruction
                        registers[rd] = (i32)registers[rs] + (i32)registers[rt];
                        break;
                    }
                    case 0b100001: {
                        // addu instruction
                        registers[rd] = registers[rs] + registers[rt];                    
                        break;
                    }
                    case 0b100100: {
                        // and instruction
                        registers[rd] = registers[rs] & registers[rt];
                    }
                }
                break;
            }
        }
    }
};

#endif
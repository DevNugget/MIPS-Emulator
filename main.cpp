#include "processor.hpp"

i32 main() {
    Processor proc;

    proc.registers[1] = 4;
    proc.registers[2] = 2;

    proc.execute_instruction(0b10000000000000110001000001000000);

    std::cout << "Result: " << proc.registers[3] << '\n';

    return 0;
}
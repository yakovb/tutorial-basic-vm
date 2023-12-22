#include <stdbool.h>
#include <stdio.h>

#define instr_ptr (registers[PC])
#define stack_ptr (registers[SP])

typedef enum { PSH, ADD, POP, SET, JMP, HLT } InstructionSet;
typedef enum { A, B, C, D, E, F, PC, SP, NUM_OF_REGISTERS } Registers;

const int program[] = {PSH, 5, PSH, 6, ADD, POP, JMP, 0, HLT};

bool running = true;
int stack[256];
int registers[NUM_OF_REGISTERS];

int fetch() { return program[instr_ptr]; }

void eval(int instr) {
  switch (instr) {
    case HLT: {
      running = false;
      break;
    }
    case PSH: {
      stack_ptr++;
      stack[stack_ptr] = program[++instr_ptr];
      break;
    }
    case POP: {
      registers[A] = stack[stack_ptr--];
      printf("popped %d\n", registers[A]);
      break;
    }
    case ADD: {
      registers[A] = stack[stack_ptr--];
      registers[B] = stack[stack_ptr--];
      registers[C] = registers[A] + registers[B];
      stack[++stack_ptr] = registers[C];
      break;
    }
    case JMP: {
      instr_ptr = program[++instr_ptr];
      instr_ptr--;
      break;
    }
  }
}

int main() {
  while (running) {
    eval(fetch());
    instr_ptr++;
  }
}

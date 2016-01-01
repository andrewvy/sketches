#include <stdbool.h>
#include <stdio.h>

typedef enum {
  PSH, // PSH, value
  ADD, // ADD
  SUB, // SUB
  MUL, // MUL
  POP, // POP
  SET, // SET, register name, value
  GET, // GET, register name
  HLT,  // HLT
  UNDEFINED_INS = 0xFF
} InstructionSet;

typedef enum {
  A, B, C, D, E, F, SP, IP,
  NUM_OF_REGISTERS
} Registers;

static const char *RegisterNames[] = {
  "A", "B", "C", "D", "E", "F", "SP", "IP"
};

const int program[] = {
  PSH, 5,
  PSH, 6,
  ADD,
  POP,
  SET, B, 4,
  SET, A, 5,
  GET, B,
  GET, A,
  MUL,
  HLT
};

#define STACK_SIZE 1024
int stack[STACK_SIZE];
int registers[NUM_OF_REGISTERS];
#define sp (registers[SP])
#define ip (registers[IP])

bool running = true;

void eval(int instr) {
  switch (instr) {
    case HLT: {
      printf("Halted successfully.\n");
      running = false;
      break;
    }
    case PSH: {
      sp++;
      stack[sp] = program[++ip];
      printf("PUSH %d\n", program[ip]);
      break;
    }
    case POP: {
      int val_popped = stack[sp--];
      printf("POP %d\n", val_popped);
      break;
    }
    case ADD: {
      int a = stack[sp--];
      int b = stack[sp--];

      int result = b + a;
      printf("ADD %d\n", result);

      sp++;
      stack[sp] = result;
      break;
    }
    case SUB: {
      int a = stack[sp--];
      int b = stack[sp--];

      int result = b - a;
      printf("SUB %d\n", result);

      sp++;
      stack[sp] = result;
      break;
    }
    case MUL: {
      int a = stack[sp--];
      int b = stack[sp--];

      int result = b * a;
      printf("MUL %d\n", result);

      sp++;
      stack[sp] = result;
      break;
    }
    case SET: {
      int reg = program[++ip];
      registers[reg] = program[++ip];
      printf("SET REG %s TO %d\n", RegisterNames[reg], program[ip]);
      break;
    }
    case GET: {
      sp++;
      int reg = program[++ip];
      stack[sp] = registers[reg];
      printf("GET REG %s %d\n", RegisterNames[reg], registers[reg]);
      break;
    }
    case UNDEFINED_INS: {
      printf("Undefined instruction. Exiting.\n");
      running = false;
      break;
    }
  }
}

int fetch() {
  return program[ip];
}

int main() {
  for (int i = 0; i < NUM_OF_REGISTERS; i++) {
    registers[i] = 0;
  }

  for (int i = 0; i < STACK_SIZE; i++) {
    stack[i] = 0xFF;
  }

  while (running) {
    eval(fetch());
    ip++;
  }

  return 0;
}

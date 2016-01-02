#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>

typedef enum {
  PSH = 1, // PSH, value
  ADD, // ADD
  SUB, // SUB
  MUL, // MUL
  POP, // POP
  SET, // SET, register name, value
  GET, // GET, register name
  IFG, // IFG, performs next instruction only if b>a
  IFL, // IFL, performs next instruction only if b<a
  PRT, // PRT, pops and prints stack value
  HLT,  // HLT
  UNDEFINED_INS
} InstructionSet;

typedef enum {
  A, B, C, D, E, F, SP, IP,
  NUM_OF_REGISTERS
} Registers;

static const char *RegisterNames[] = {
  "A", "B", "C", "D", "E", "F", "SP", "IP"
};

// How much to advance IP
static int SkipTable[12] = {
  [PSH] = 2, [ADD] = 1, [SUB] = 1,
  [MUL] = 1, [POP] = 1, [SET] = 3,
  [GET] = 2, [IFG] = 1, [IFL] = 1,
  [PRT] = 1, [HLT] = 0
};

#define PROGRAM_SIZE 1024
#define STACK_SIZE 1024
#define DEBUG_MODE 0
int program[PROGRAM_SIZE];
int stack[STACK_SIZE];
int registers[NUM_OF_REGISTERS];
#define sp (registers[SP])
#define ip (registers[IP])

bool running = true;

void die(const char *message) {
  printf("ERROR: %s\n", message);
  exit(1);
}

void pchk(int number) {
  if (sp + number > STACK_SIZE) die("Stack pointer out of bounds");
}

void mchk(int number) {
  if (sp - number < 0) die("Stack pointer out of bounds");
}

void skip_instruction(int next_instruction) {
  ip += SkipTable[next_instruction];
}

void eval(int instr) {
  int a = stack[sp];
  int b = stack[sp-1];

  switch (instr) {
    case HLT: {
      printf("Halted successfully.\n");
      running = false;
      break;
    }
    case PSH: {
      pchk(1);
      stack[++sp] = program[++ip];
      if (DEBUG_MODE) printf("PUSH %d\n", program[ip]);
      break;
    }
    case POP: {
      mchk(1);
      int val_popped = stack[sp--];
      if (DEBUG_MODE) printf("POP %d\n", val_popped);
      break;
    }
    case ADD: {
      mchk(2);
      int result = b + a;
      if (DEBUG_MODE) printf("ADD %d\n", result);
      stack[++sp] = result;
      break;
    }
    case SUB: {
      mchk(2);
      int result = b - a;
      if (DEBUG_MODE) printf("SUB %d\n", result);
      stack[++sp] = result;
      break;
    }
    case MUL: {
      mchk(2);
      int result = b * a;
      if (DEBUG_MODE) printf("MUL %d\n", result);

      stack[++sp] = result;
      break;
    }
    case SET: {
      int reg = program[++ip];
      registers[reg] = program[++ip];
      if (DEBUG_MODE) printf("SET REG %s TO %d\n", RegisterNames[reg], program[ip]);
      break;
    }
    case GET: {
      pchk(1);
      int reg = program[++ip];
      stack[++sp] = registers[reg];
      if (DEBUG_MODE) printf("GET REG %s %d\n", RegisterNames[reg], registers[reg]);
      break;
    }
    case IFG: {
      mchk(2);

      // if b > a perform next instruction
      // else skip it
      if (!(b > a)) {
        skip_instruction(program[ip+1]);
      }


      break;
    }
    case IFL: {
      mchk(2);

      // if b < a perform next instruction
      // else skip it
      if (!(b < a)) {
        skip_instruction(program[ip+1]);
      }

      break;
    }
    case PRT: {
      // print whatever is in the stack
      int val_popped = stack[sp--];
      printf("%c", (char) val_popped);
      break;
    }
    case UNDEFINED_INS: {
      die("Undefined instruction. Exiting.");
      running = false;
      break;
    }
  }
}

int fetch() {
  return program[ip];
}

FILE* load_from_file(const char *filename) {
  FILE* file = fopen(filename, "r+");

  if (!file) die("Could not load file");

  return file;
}

int read_instruction(char *ins) {
  if (strcmp(ins, "PSH") == 0) {
    return PSH;
  } else if (strcmp(ins, "ADD") == 0) {
    return ADD;
  } else if (strcmp(ins, "SUB") == 0) {
    return SUB;
  } else if (strcmp(ins, "MUL") == 0) {
    return MUL;
  } else if (strcmp(ins, "POP") == 0) {
    return POP;
  } else if (strcmp(ins, "SET") == 0) {
    return SET;
  } else if (strcmp(ins, "GET") == 0) {
    return GET;
  } else if (strcmp(ins, "IFG") == 0) {
    return IFG;
  } else if (strcmp(ins, "IFL") == 0) {
    return IFL;
  } else if (strcmp(ins, "PRT") == 0) {
    return PRT;
  } else if (strcmp(ins, "HLT") == 0) {
    return HLT;
  } else {
    return 0;
  }
}

void read_program(FILE *file) {
  int pc = 0;
  int instruction = 0;
  int arg = 0;
  char line[100];
  char *ins;

  while (1) {
    if (fgets(line, 100, file) == NULL) break;
    char *nl = strchr(line, '\n');
    if (nl) *nl = 0;

	// This instruction is a comment, ignore.
	if (line[0] == '#') continue;

    ins = strtok(line, " ");
    instruction = read_instruction(ins);

    if (!instruction) die("Undefined instruction in program. Exiting.");
    program[pc] = instruction;

    // Run strtok again to skip over the current instruction.
    ins = strtok(NULL, " ");

    // Set the arguments for the rest of the instruction.
    while (ins != NULL) {
      pc++;

      if (strcmp(ins, "A") == 0) {
        arg = A;
      } else if (strcmp(ins, "B") == 0) {
        arg = B;
      } else if (strcmp(ins, "C") == 0) {
        arg = C;
      } else if (strcmp(ins, "D") == 0) {
        arg = D;
      } else if (strcmp(ins, "E") == 0) {
        arg = E;
      } else if (strcmp(ins, "F") == 0) {
        arg = F;
      } else if (strcmp(ins, "SP") == 0) {
        arg = SP;
      } else if (strcmp(ins, "IP") == 0) {
        arg = IP;
      } else {
        arg = atoi(ins);
      }

      program[pc] = arg;
      ins = strtok(NULL, " ");
    }

    pc++;
  }
}

void clear_registers() {
  for (int i = 0; i < NUM_OF_REGISTERS; i++) {
    registers[i] = 0;
  }
}

void clear_program() {
  for (int i = 0; i < PROGRAM_SIZE; i++) {
    program[i] = UNDEFINED_INS;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) die("Usage: mac <program_file>");

  char *filename = argv[1];
  FILE* file = load_from_file(filename);

  clear_registers();
  clear_program();
  read_program(file);

  while (running) {
    eval(fetch());
    ip++;
  }

  return 0;
}

#ifndef PORTIO_H
#define PORTIO_H

#include <stdint.h>

struct regs {
  uint32_t gs, fs, es, ds;
  uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
  uint32_t int_no, err_code;
  uint32_t eip, cs, eflags, useresp, ss;
};

unsigned char inportb(unsigned short _port);

void outportb(unsigned short _port, unsigned char _data);

#endif
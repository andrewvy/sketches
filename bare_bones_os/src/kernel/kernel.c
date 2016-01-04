#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/fault.h>
#include <kernel/idt.h>
#include <kernel/irq.h>

void kernel_early(void) {
  terminal_initialize();

  gdt_install();
  idt_install();
  isrs_install();
  irq_install();

  // Allow interrupts
  __asm__ __volatile__ ("sti");
}

void kernel_main(void) {
  terminal_writestring("Kernel loaded successfully!\n");
}

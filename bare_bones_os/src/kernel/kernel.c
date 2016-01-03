#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include <kernel/tty.h>

void kernel_early(void) {
  terminal_initialize();
}

void kernel_main(void) {
  terminal_writestring("KERNEL: OS-0.0.1\n");
  terminal_writestring("BY: ANDREW VY\n");
}

#ifndef _KBD_H
#define _KBD_H

#include <kernel/portio.h>
#include <kernel/irq.h>
#include <kernel/tty.h>
#include <kernel/util/log.h>

void keyboard_handler(struct regs *r);
void keyboard_install();

#endif

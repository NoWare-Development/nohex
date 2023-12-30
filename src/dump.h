#ifndef DUMP_H_
#define DUMP_H_

#include <stdint.h>
#include <stdbool.h>

#include "settings.h"

void print_file_hex(uint8_t *buffer, uint32_t bytes, bool hide_zeros);
void dump_to_file(settings sets, char **argv, uint8_t *buffer, uint32_t bytes);

#endif // DUMP_H_

#ifndef STREAM_H_
#define STREAM_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void stream_to_file(FILE *fp, uint8_t *buffer, uint32_t bytes_count, bool hide_zeros);

#endif // STREAM_H_

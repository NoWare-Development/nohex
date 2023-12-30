#ifndef STREAM_H_
#define STREAM_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "settings.h"

void stream_to_file(FILE *fp, uint8_t *buffer, uint32_t bytes_count, settings sets);

#endif // STREAM_H_

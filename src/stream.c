#include "stream.h"

void stream_to_file(FILE *fp, uint8_t *buffer, uint32_t bytes_count, bool hide_zeros) {
  fprintf(fp, "| Address  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F |\n");
  fprintf(fp, "| -------- | ----------------------------------------------- |\n");

  uint32_t pads = 0;
  for (uint32_t i = 0; i < bytes_count; i++) {
    if (i % 0x10 == 0) {
      if (i != 0)
        fprintf(fp, "|\n");

      fprintf(fp, "| %.8X | ", i);
    }

    if (buffer[i] == 0 && hide_zeros) fprintf(fp, ".. ");
    else fprintf(fp, "%.2X ", buffer[i]);

    pads += 3;
  }

  for (; pads % 48 != 0; pads++)
    fprintf(fp, " ");

  fprintf(fp, "|\n");
}

#include "stream.h"

void stream_to_file(FILE *fp, uint8_t *buffer, uint32_t bytes_count, settings sets) {
  if (sets.data) {
    fprintf(fp, "| Address  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F | Data             |\n");
    fprintf(fp, "| -------- | ----------------------------------------------- | ---------------- |\n");
  }
  else {
    fprintf(fp, "| Address  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F |\n");
    fprintf(fp, "| -------- | ----------------------------------------------- |\n");
  }

  uint32_t pads = 0;
  uint32_t data_indices = 0;
  for (uint32_t i = 0; i < bytes_count; i++) {
    if (i % 0x10 == 0) {
      data_indices = i;

      if (i != 0) {
        if (sets.data) fprintf(fp, "| ");
        else fprintf(fp, "|\n");

        data_indices -= 0x10;

        if (sets.data) {
          for (; data_indices < i; data_indices++) {
            if (buffer[data_indices] > 31 && buffer[data_indices] < 127)
              fprintf(fp, "%c", (char)buffer[data_indices]);
            else fprintf(fp, ".");
          }
          fprintf(fp, " |\n");
        }
      }

      fprintf(fp, "| %.8X | ", i);
    }

    if (buffer[i] == 0 && sets.hide_zeros) fprintf(fp, ".. ");
    else fprintf(fp, "%.2X ", buffer[i]);

    pads += 3;

  }

  for (; pads % 48 != 0; pads++)
    fprintf(fp, " ");

  if (sets.data) {
    fprintf(fp, "| ");
    for (; data_indices % 0x10 != 0; data_indices--);

    if (buffer[data_indices] > 31 && buffer[data_indices] < 127)
      fprintf(fp, "%c", (char)buffer[data_indices]);
    else fprintf(fp, ".");
    data_indices++;

    for (; data_indices % 0x10 != 0; data_indices++) {
      if (buffer[data_indices] > 31 && buffer[data_indices] < 127)
        fprintf(fp, "%c", (char)buffer[data_indices]);
      else if (data_indices < bytes_count) fprintf(fp, ".");
      else fprintf(fp, " ");
    }
    fprintf(fp, " |\n");
  }
  else fprintf(fp, "|\n");
}

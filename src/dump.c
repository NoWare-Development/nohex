#include "dump.h"

#include <stdio.h>
#include <stdlib.h>

#include "stream.h"

void print_file_hex(uint8_t *buffer, uint32_t bytes_count, bool hide_zeros) {
  stream_to_file(stdout, buffer, bytes_count, hide_zeros);
}

void dump_to_file(settings sets, char **argv, uint8_t *buffer, uint32_t bytes_count) {
  remove(argv[sets.file_to_dump]);
  FILE *fp = fopen(argv[sets.file_to_dump], "w");
  if (!fp) {
    fprintf(fp, "Failed to open file \"%s\"\n", argv[sets.file_to_dump]);
    exit(-1);
  }

  fprintf(fp, "Dump of \"%s\"\n", argv[1]);
  fprintf(fp, "Generated via NoHex (https://github.com/NoWare-Development/nohex)\n\n");

  stream_to_file(fp, buffer, bytes_count, sets.hide_zeros);

  fclose(fp);
}

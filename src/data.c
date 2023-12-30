#include "data.h"

#include <stdio.h>
#include <stdlib.h>

#include "settings.h"

void get_data(char *file, uint8_t *buffer, uint32_t *bytes_count) {
  FILE *fp = fopen(file, "r");
  if (!fp) {
    fprintf(stderr, "No such file or directory: \"%s\"\n", file);
    exit(-1);
  }

  *bytes_count = fread(buffer, 1, BUFFER_SIZE, fp);

  fclose(fp);
}

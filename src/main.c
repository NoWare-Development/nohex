#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "settings.h"

#include "args.h"
#include "data.h"
#include "dump.h"

int main(int argc, char **argv) {
  settings sets;

  parse_arguments(argc, argv, &sets);

  uint8_t buffer[BUFFER_SIZE];
  uint32_t bytes = 0;
  get_data(argv[1], buffer, &bytes);

  print_file_hex(buffer, bytes, sets.hide_zeros);
  if (sets.dump)
    dump_to_file(sets, argv, buffer, bytes);

  return 0;
}

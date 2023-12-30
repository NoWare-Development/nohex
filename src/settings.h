#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <stdbool.h>

#define BUFFER_SIZE 0xFFFF

typedef struct settings {
  bool nogui;
  bool hide_zeros;
  bool dump;
  bool data;
  unsigned int file_to_dump;
} settings;

#endif // SETTINGS_H_

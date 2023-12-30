#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 0xFFFF

static bool nogui = false;
static bool hide_zeros = false;
static bool dump = false;

int g_argc;
char **g_argv;
int file_to_dump;

void print_args(void) {
  printf("Flags:\n");
  printf("\t-h (-help) -- print this\n");
  printf("\t-hz (-hide-zeros) -- replace zeros with dots\n");
  printf("\t-nogui -- run terminal version of application\n");
  printf("\t-d (-dump) [file] -- dumps to specified file\n");
}

void print_usage(void) {
  printf("=== USAGE ===\n");
  printf("nohex [path/to/file] [flags]\n\n");
  print_args();
}

void parse_arguments(void) {
  if (g_argc < 2) {
    printf("No file specified\n");
    print_usage();
    exit(1);
  }

  if (g_argc > 2) {
    for (int i = 2; i < g_argc; i++) {
      if (g_argv[i] != 0) {
        if (!strcmp(g_argv[i], "-h") || !strcmp(g_argv[i], "-help")) {
          print_usage();
          exit(0);
        }
        else if (!strcmp(g_argv[i], "-hz") || !strcmp(g_argv[i], "-hide-zeros")) {
          hide_zeros = true;
        }
        else if (!strcmp(g_argv[i], "-d") || !strcmp(g_argv[i], "-dump")) {
          if (g_argv[i + 1] == 0)
            printf("No file to dump to\n");
          else {
            dump = true;
            file_to_dump = i + 1;
            i++;
          }
        }
        else if (!strcmp(g_argv[i], "-nogui")) {
          printf("Running terminal version...\n");
          nogui = true;
        }
        else {
          printf("Unknown flag \"%s\"\n", g_argv[i]);
          printf("You can get all available flags by providing this argument: -h\n");
        }
      }
    }
  }
}

void print_file_content(char *file);
void dump_to_file(uint8_t *buffer, uint32_t bytes);

int main(int argc, char **argv) {
  g_argc = argc;
  g_argv = argv;
  parse_arguments();
  print_file_content(argv[1]);

  exit(0);
}

void print_file_content(char *file) {
  FILE *fp = fopen(file, "r");
  if (!fp) {
    printf("No such file or directory: \"%s\"\n", file);
    exit(-1);
  }

  uint8_t buffer[BUFFER_SIZE];
  uint32_t bytes = fread(buffer, 1, BUFFER_SIZE, fp);

  printf("| Address  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F |\n");
  printf("| -------- | ----------------------------------------------- |\n");

  uint32_t pads = 0;
  for (uint32_t i = 0; i < bytes; i++) {
    if (i % 0x10 == 0) {
      if (i != 0)
        printf("|\n");

      printf("| %.8X | ", i);
    }

    if (buffer[i] == 0 && hide_zeros) printf(".. ");
    else printf("%.2X ", buffer[i]);

    pads += 3;
  }
  for (; pads % 48 != 0; pads++)
    printf(" ");

  printf("|\n");

  fclose(fp);

  if (dump)
    dump_to_file(buffer, bytes);
}

void dump_to_file(uint8_t *buffer, uint32_t bytes) {
  remove(g_argv[file_to_dump]);

  FILE *fp = fopen(g_argv[file_to_dump], "w");
  if (!fp) {
    printf("No such file or directory: \"%s\"\n", g_argv[file_to_dump]);
    exit(-2);
  }

  fprintf(fp, "Dump of \"%s\"\n", g_argv[1]);
  fprintf(fp, "Generated via NoHex (https://github.com/NoWare-Development/nohex)\n\n");

  fprintf(fp, "| Address  | 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F |\n");
  fprintf(fp, "| -------- | ----------------------------------------------- |\n");

  uint32_t pads = 0;
  for (uint32_t i = 0; i < bytes; i++) {
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

  fclose(fp);
}

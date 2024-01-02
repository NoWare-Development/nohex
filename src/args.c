#include "args.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage(void) {
  fprintf(stdout, "=== USAGE ===\n");
  fprintf(stdout, "nohex [path/to/file] [flags]\n\n");
  print_args();
}

void print_args(void) {
  fprintf(stdout, "Flags:\n");
  fprintf(stdout, "\t-h (-help) -- display this message\n");
  fprintf(stdout, "\t-hz (-hide-zeros) -- replace zeros with dots\n");
  fprintf(stdout, "\t-nogui -- run terminal version of NoHex\n");
  fprintf(stdout, "\t-d (-dump) [path/to/file] -- dumps to specified file\n");
}

void parse_arguments(int argc, char **argv, settings *sets) {
  if (argc < 2) {
    fprintf(stdout, "No file specified\n");
    print_usage();
    exit(1);
  }

  if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-help")) {
    print_usage();
    exit(0);
  }

  if (argc > 2) {
    for (int i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "-help")) {
          print_usage();
          exit(0);
        }
        else if (!strcmp(argv[i], "-hz") || !strcmp(argv[i], "-hide-zeros")) {
          sets->hide_zeros = true;
        }
        else if (!strcmp(argv[i], "-d") || !strcmp(argv[i], "-dump")) {
          if (argv[i + 1] == 0)
            printf("No file to dump to\n");
          else {
            sets->dump = true;
            sets->file_to_dump = i + 1;
            i++;
          }
        }
        else if (!strcmp(argv[i], "-data")) {
          sets->data = true;
        }
        else if (!strcmp(argv[i], "-nogui")) {
          fprintf(stdout, "Running terminal version...\n");
          sets->nogui = true;
        }
        else {
          fprintf(stderr, "Unknown flag \"%s\"\n", argv[i]);
          fprintf(stderr,
          "You can get all available flags by providing this argument: -h\n");
        }
    }
  }
}

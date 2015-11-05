#include <stdio.h>
#include <stdbool.h>

// user input buffer
static char input[2048];

int main(int argc, char** argv) {
  // version info
  puts("Lispy Version 0.1");
  puts("Press Ctrl+c to Exit\n");

  // REPL loop
  while (true) {
    // output prompt
    fputs("lispy> ", stdout);
    // read a line of user input into the buffer
    fgets(input, 2048, stdin);
    // for now, just echo the input back
    printf("You entered: %s", input);
  }

  return 0;
}

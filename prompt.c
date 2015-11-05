#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char** argv) {
  // version info
  puts("Lispy Version 0.1");
  puts("Press Ctrl+c to Exit\n");

  // REPL loop
  while (true) {
    // output prompt and read user input
    char* input = readline("lispy> ");
    // add input to history
    add_history(input);
    // for now, just echo the input back
    printf("You entered: %s\n", input);
    // free retrieved input
    free(input);
  }

  return 0;
}

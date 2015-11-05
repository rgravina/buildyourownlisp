#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// readline isn't available on Windows so provide a similar interface.
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

// add_history here just does nothing
void add_history(char* unused) {}
#else
#include <readline/readline.h>
#include <readline/history.h>
#endif

int main(int argc, char** argv) {
  // version info
  puts("Build Your Own Lip: Version 0.1");
  puts("Press Ctrl+c to Exit\n");

  // REPL loop
  while (true) {
    // output prompt and read user input
    char* input = readline("lisp> ");
    // add input to history
    add_history(input);
    // for now, just echo the input back
    printf("You entered: %s\n", input);
    // free retrieved input
    free(input);
  }

  return 0;
}

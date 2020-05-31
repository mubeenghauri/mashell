#include<stdio.h>
#include<unistd.h>
#include<string.h>

/*  prototypes */
void shell_loop();

int main(int argc, char *argv[]) {

  shell_loop();

  return 0;
}

void shell_loop() {
  char* line = NULL;
  size_t line_size;

  do{
    printf("> ");
    getline(&line, &line_size, stdin);
    printf("%s", line);
  } while(strcmp(line, "exit\n") != 0);

  printf("[mashell] BYE :) !");
  getchar();
  return;
}

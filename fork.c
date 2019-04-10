#include <stdio.h>
#include <unistd.h>

int display_msg(char *);

int main(int argc, char const *argv[]) {
  static char *msg[] = {"Ola", "qe", "ase"};
  for (size_t i = 0; i < 3; ++i) {
    (void) display_msg(msg[i]);
  }
  sleep(2);
  return 0;
}

int display_msg(char *m) {
  char err_msg[25];
  switch (fork()) {
    case 0:
      execlp("/usr/bin/echo", "echo", m, (char *) NULL);
      sprintf(err_msg, "%s falla en exec", m);
      perror(err_msg);
      return 1;
    case -1:
      perror("falla en fork");
      return 2;
    default:
      return 0;
  }
}

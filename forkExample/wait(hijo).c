#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]){
    pid_t pid;
    int ret_value;
    pid= getpid();
    ret_value= (int) (pid % 256);
    srand((unsigned)pid);
    sleep(rand()%5);
    if (atoi(*argv + 1)%2) {
        printf("Hijo %d terminado por la señal 0009\n", pid);
        kill(pid, 9);
    } else {
        printf("Hijo %d terminado por exit(%04X)\n", pid, ret_value);
        exit(ret_value);
    }
}

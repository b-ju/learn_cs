/* 
 * Author: Ben Jurenka
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        exit(EXIT_FAILURE);
    }
    
    
    char num[3];
    int stat, count = 0;
    const int NUM_CHILDS = 3;
    pid_t starter_pid, pid;
    starter_pid = getpid();
    
    char* file_name = argv[1];
    FILE* file_ptr;
    file_ptr = fopen(file_name, "r");
    fscanf(file_ptr, "%s", num);
    
    while (!feof(file_ptr)) {

        for (int i = 0; i < NUM_CHILDS; ++i) {
            pid = fork();
            if (pid == -1) {
                printf("failed to fork.\n");

            } else if (pid > 0) {
                //parent	
                printf("Starter[%d] : Forked process with ID %d.\n", starter_pid, pid);
                printf("Starter[%d] : Waiting for process [%d].\n", starter_pid, pid);
                pid_t cpid = waitpid(pid, &stat, 0);
                if (WIFEXITED(stat)) {
                    printf("Starter: Child process %d returned %d.\n", cpid, WEXITSTATUS(stat));
                }

            } else if (pid == 0) {
                //child 
                if (i == 0) {
                    if (execlp("./fib", "./fib", num, (char*) NULL) == -1) {
                        printf("execl error\n");
                        exit(EXIT_FAILURE);
                    }
                }

                if (i == 1) {
                    if (execlp("./prime", "./prime", num, (char*) NULL) == -1) {
                        printf("execl error\n");
                        exit(EXIT_FAILURE);
                    }
                }
                if (i == 2) {
                    if (execlp("./total", "./total", num, (char*) NULL) == -1) {
                        printf("execl error\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
        fscanf(file_ptr, "%s", num);
    }
    fclose(file_ptr);
    return (EXIT_SUCCESS);
}


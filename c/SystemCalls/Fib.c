/*
 *@author Ben Jurenka
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int print_fib(int n) {
    if (n <= 0) {
        printf("FIBB: Input was: %d. Input must be a positive integer.\n", n);
        exit(EXIT_FAILURE);
    }
    int prev_one = 0, n_minus_one = 1, n_minus_two = 0;
    if (n == 1) {
        printf("The first number of the fibonacci series is 0.\n");
        return 0;
    }

    printf("FIB[%d] The first %d numbers of the fibonacci series are:\n", getpid(), n);
    for (int i = 0; i < n - 1; ++i) {
        printf("%d, ", prev_one);
        prev_one = n_minus_one;
        n_minus_one += n_minus_two;
        n_minus_two = prev_one;
    }
    printf("%d\n", prev_one);
    return prev_one;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("1 argument required.\n");
        exit(EXIT_FAILURE);
    }
    int n = atoi(argv[1]);
    pid_t pid = getpid();
    printf("FIB[%d] : Number of terms in fibonacii series is %d.\n", pid, n);
    return print_fib(n);
}


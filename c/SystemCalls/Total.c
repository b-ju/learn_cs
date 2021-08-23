/*
 *@author Ben Jurenka
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int sum_of_n_nums(int n) {
    if (n < 0) {
        printf("[TOTAL]: Input n must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("1 argument required.\n");
        exit(EXIT_FAILURE);
    }
    int n = atoi(argv[1]);
    int total = sum_of_n_nums(n);
    printf("TOTAL[%d] : sum = %d\n", getpid(), total);
    return total;
}

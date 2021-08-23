/*
 * @author Ben Jurenka
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// each value of array is initialized to 0
// set value to 1 if it not a prime

int* sieve(int n) {
    if (n < 2) {
        exit(EXIT_FAILURE);
    }
    int arr_size = (n + 1);
    int* prime_arr = calloc(sizeof (int), arr_size);
    const int CROSSED_OUT = 1;
    int prime = 2, not_prime = 2;
    while ((prime * prime) < arr_size) {
        not_prime = prime;
        while (not_prime <= arr_size) {
            not_prime += prime;
            prime_arr[not_prime] = CROSSED_OUT;
        }
        prime++;
        while (prime_arr[prime] == CROSSED_OUT) {
            prime++;
        }
    }
    return prime_arr;
}

int print_n_primes(int n) {
    int* prime_arr = sieve(4 * n);
    int count = 0, nth_prime = 0;
    const int PRIME = 0;
    for (int i = 2; i < (4 * n); ++i) {
        if (prime_arr[i] == PRIME) {
            ++count;
            printf("%d, ", i);
        }
        if (count == n) {
            nth_prime = i;
            break;
        }
    }
    printf("\n");
    free(prime_arr);
    return nth_prime;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("1 argument required.\n");
        exit(EXIT_FAILURE);
    }
    int n = atoi(argv[1]);
    printf("PRIME[%d] : The first %d prime numbers are:\n", getpid(), n);
    return print_n_primes(n);
}

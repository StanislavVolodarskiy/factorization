#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void print_factorization(int userInput) {
    printf("\n%d =\n", userInput);
    int counter = 2;
    int max = (int)(sqrt(userInput)) + 1;
    printf("= %d * %d\n", 1, userInput);
    while (counter < max) {
        if ((userInput % counter) == 0) {
            printf("= %d * %d\n", counter, userInput/counter);
        }
        counter++;
    }
}

void help(const char *name)
{
    fprintf(stderr, "Usage: %s FIRST LAST REPEAT\n", name);  
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc < 2 || 4 < argc) {
        help(argv[0]);
    }

    int first;
    if (sscanf(argv[1], "%d", &first) != 1) {
        help(argv[0]);
    }

    int last = first;
    if (argc >= 3) {
        if (sscanf(argv[2], "%d", &last) != 1) {
            help(argv[0]);
        }
    }

    int repeat = 1;
    if (argc >= 4) {
        if (sscanf(argv[3], "%d", &repeat) != 1) {
            help(argv[0]);
        }
    }

    if (first <= last) {
        for (int k = 0; k < repeat; ++k) {
            for (int n = first; n < last; ++n) {
                print_factorization(n);
            }
            print_factorization(last);
        }
    }
}

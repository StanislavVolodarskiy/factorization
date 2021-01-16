#include <math.h>
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Item_
{
    unsigned int p, k;
} Item;

Item f[11];

void factors(unsigned int n)
{
    memset(f,0,sizeof(f));
    int idx = 0;
    while(n > 1 && n%2 == 0)
    {
        f[idx].p = 2;
        f[idx].k++;
        n /= 2;
    }
    if (f[idx].p) idx++;

    if (n > 1)
        for(unsigned int i = 3; i*i <= n; i += 2)
        {
            while(n%i == 0)
            {
                f[idx].p = i;
                f[idx].k++;
                n /= i;
            }
            if (f[idx].p) idx++;
        }
    if (n > 1)
    {
        f[idx].p = n;
        f[idx].k = 1;
    }
}

void outpairs(unsigned int N, unsigned int p, int m )
{
    if (f[m].p == 0)
    {
        printf("= %u * %u\n",p,N/p);
        return;
    }
    unsigned int k = 1, i = 0;
    do {
        if (p*k > sqrt(N)) return;
        outpairs(N,p*k,m+1);
        k *= f[m].p;
    } while(++i <= f[m].k);
}

void print_factorization(unsigned int N)
{
    printf("\n%u =\n", N);
    factors(N);
    outpairs(N,1,0);
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

    unsigned int first;
    if (sscanf(argv[1], "%u", &first) != 1) {
        help(argv[0]);
    }

    unsigned int last = first;
    if (argc >= 3) {
        if (sscanf(argv[2], "%u", &last) != 1) {
            help(argv[0]);
        }
    }

    unsigned int repeat = 1;
    if (argc >= 4) {
        if (sscanf(argv[3], "%u", &repeat) != 1) {
            help(argv[0]);
        }
    }

    if (first <= last) {
        for (unsigned int k = 0; k < repeat; ++k) {
            for (unsigned int n = first; n < last; ++n) {
                print_factorization(n);
            }
            print_factorization(last);
        }
    }
}

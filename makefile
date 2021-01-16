.PHONY: help
help:
	cat makefile

.PHONY: clean
clean:
	rm -rf tmp
	rm -f f1 f2 f3 f4 f5

f1: f1.c
	gcc -std=c11 -pedantic -Wpedantic -Wall -Wextra -O3 f1.c -lm -o f1
	strip f1

f2: f2.c
	gcc -std=c11 -pedantic -Wpedantic -Wall -Wextra -O3 f2.c -lm -o f2
	strip f2

f3: f3.c
	gcc -std=c11 -pedantic -Wpedantic -Wall -Wextra -O3 f3.c -lm -o f3
	strip f3

f4: f4.c
	gcc -std=c11 -pedantic -Wpedantic -Wall -Wextra -O3 f4.c -lm -o f4
	strip f4

f5: f5.c
	gcc -std=c11 -pedantic -Wpedantic -Wall -Wextra -O3 f5.c -lm -o f5
	strip f5

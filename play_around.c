#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//play around with pointers, malloc, realloc and free while building arrays (normal and dynamic) 

int * blah(int val) {
	int x;
	int * pointer = &x;
	x = val*val;
	return pointer;
}

int main(int argc, char **argv) {
	int * b = blah(5);
	printf("%d.\n", *b);
	return 0;
}
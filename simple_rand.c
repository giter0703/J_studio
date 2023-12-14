#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int rad;
	srand((unsigned int)time(NULL));
	rad = rand() % 3;
	printf("%d\n", rad);
}
#include <stdint.h>
#include <stdio.h>
#include <string.h>

extern void entry();

int main() {
	printf("Hello from C!");
	getchar();
	entry();
	return 0;
}

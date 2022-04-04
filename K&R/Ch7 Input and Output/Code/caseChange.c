#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int buffer;

	while((buffer = getchar()) != EOF)
		putchar(strcmp(argv[0], "upper") ? toupper(buffer) : tolower(buffer));
	return 0;
}

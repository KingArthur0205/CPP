#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Return the length of the str
int my_getline(char *line, int max_length) {
	if(fgets(line, max_length, stdin) == NULL)
		return 0;
	return strlen(line);
}

int main(int argc, char* argv[]) {
	char *line = (char *)malloc(sizeof(char) * 20);
	printf("%d", my_getline(line, 20));
	return 0;
}

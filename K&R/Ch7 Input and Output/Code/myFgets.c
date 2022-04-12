#include <stdio.h>
#include <assert.h>

char *my_gets(char *s, int max_length, FILE *fp) {
	register char c;
	register char *ch;
	// Create a variable in order to change the value of string stored in s.
	ch = s;

	while(--max_length > 0 && (c = fgetc(fp)) != EOF)
		if((*ch++ = c) == '\n')
			break;
	*ch = '\0';
	return (c == EOF && ch == s) ? NULL : s;
}

int main(int argc, char* argv[]) {
	char line[20];
	int length = 30;
	
	assert(argc > 1);

	FILE *fp = fopen(argv[1], "r");
	printf("%s", my_gets(line, length, fp));
	return 0;
}

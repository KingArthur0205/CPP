#include <stdio.h>
#include <assert.h>

int my_fputs(char *line, FILE *fp) {
	int c;

	while((c = *line++) != '\0')
		fputc(c, fp);
	return ferror(fp) ? EOF : 0;
}

int main(int argc, char* argv[]) {
	char *line = "Arthur";

	assert(argc > 1);
	my_fputs(line, fopen(argv[1], "w"));
	return 0;
}

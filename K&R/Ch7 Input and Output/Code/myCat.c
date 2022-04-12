#include <stdio.h>

// Copy the contents from the first file to the second file
void file_copy(FILE*, FILE*);

int main(int argc, char* argv[]) {
	FILE *fp;
	
	if(argc == 1)
		file_copy(stdin, stdout);
	else {
		while(--argc >0) {
			if((fp = fopen(*++argv, "r")) == NULL) {
				printf("Cannot open: %s\n", *argv);
				return 1;
			} else {
				file_copy(fp, stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}

void file_copy(FILE *src, FILE *dest) {
	char c;
	while((c = getc(src)) != EOF) {
		putc(c, dest);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void printFirstDiff(FILE *fstFile, FILE *sndFile) {
	char *fstLine = (char*)malloc(sizeof(char) * 500);
	char *sndLine = (char*)malloc(sizeof(char) * 500);

	while(fgets(fstLine, 100, fstFile) != NULL && fgets(sndLine, 100, sndFile) != NULL)
		if(strcmp(fstLine, sndLine) != 0) {
		printf("%s\n%s\n", fstLine, sndLine);
			break;
		}
}

int main(int argc, char* argv[]) {
	assert(argc == 3);
	printFirstDiff(fopen(argv[1], "r"), fopen(argv[2], "r"));
	return 0;
}



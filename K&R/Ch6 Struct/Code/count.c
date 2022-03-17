#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

#include "keywords.h"

#define MAXWORD 100

char getword(int, char [MAXWORD], int);
extern struct key;
extern struct key keytab[];
int findKeyWord(char [MAXWORD], struct key[], int);
int strEqual(char[], char[]);

#define KEY_WORD_NUM (sizeof(keytab) / sizeof(struct key))

int main(int argc, char* argv[]) {
	// Use index to index into the keytab array that stores all of the keywords
	int index;
	char word[MAXWORD];
	int fd = open(argv[1], O_RDONLY);
	assert(fd != -1);

	int count = 0;

	// getword returns word[0]. If word[0] is '\0', it means there is no keywords to read any more
	while(getword(fd, word, MAXWORD) != EOF) {
		if(isalpha(word[0]) && (index = findKeyWord(word, keytab, KEY_WORD_NUM)) >= 0) {
			keytab[index].count++;
		}
	}

	int i;
	for(i = 0; i < KEY_WORD_NUM; ++i) {
		printf("Keyword: %s, Count: %d\n", keytab[i].word, keytab[i].count);
	}

	return 0;
}

char getword(int fd, char word[MAXWORD], int limit) {
	char singleChar;
	char *w = word;
	int count;
	while((count = read(fd, &singleChar, sizeof(char))) != EOF) {
		if(count == 0)
			break;
		if(!isalpha(singleChar)) {
			*w = '\0';
			return word[0];
		}
		*w++ = singleChar;
	}
		
	return EOF;
}

int findKeyWord(char word[MAXWORD], struct key keytab[], int size) {
	int index;
	for(index = 0; index < size; ++index) {
		if(strEqual(word, keytab[index].word)) {
			return index;
		}
	}
	return -1;
}

int strEqual(char word1[], char word2[]) {
	int length1 = strlen(word1);
	int length2 = strlen(word2);

	if(length1 != length2)
		return 0;

	for(int i = 0; i < length1; ++i) {
		if(word1[i] != word2[i])
			return 0;
	}
	return 1;
}

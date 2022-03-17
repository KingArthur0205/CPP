#include <ctype.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH_SIZE 101

struct hNode {
	struct hNode *nEntry;
	char *name;
	char *def;
};



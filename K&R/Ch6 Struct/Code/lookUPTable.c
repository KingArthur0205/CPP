#include "hNode.h"

// struct hNode is defined in "hNode.h"
extern struct hNode;
static struct hNode* hashTable[MAX_HASH_SIZE];

size_t hash(char *name);
struct hNode *addToTable(char *name, char* def);
void printTable();
struct hNode *lookUp(char *key);
void removeEntry(char*);

int main(int argc, char* argv[]) {
	addToTable("hello", "1");	
	addToTable("hello", "2");
	addToTable("King", "100");	
	removeEntry("hello");
	printTable();
	return 0;
}

void removeEntry(char *key) {
	if(lookUp(key) != NULL) {
		size_t hashVal = hash(key);
		struct hNode *head = hashTable[hashVal];

		if(strcmp(head->name, key) == 0) {
			hashTable[hashVal] = head->nEntry;
			free(head);
			return;
		}

		for(; head->nEntry != NULL; head = head->nEntry) {
			if(strcmp(head->nEntry->name, key) == 0) {
				struct hNode *temp = head->nEntry;
				head->nEntry = temp->nEntry;
				free((void*)temp);
				return;
			}
		}
	}
}

struct hNode* lookUp(char *key) {
	struct hNode* entry;
	for(entry = hashTable[hash(key)]; entry != NULL; entry = entry->nEntry) {
		if(strcmp(entry->name, key) ==  0)
			return entry;
	}
	return entry;
}

void printTable() {
	size_t i;
	for(i = 0; i < MAX_HASH_SIZE; ++i) {
		struct hNode *temp;
		if((temp = hashTable[i]) != NULL) {
			int numCount = 0;
			while(temp != NULL) {
				printf("%d\tName: %s Definition: %s\t", numCount++, temp->name, temp->def);
				temp = temp->nEntry;
			}
			printf("\n");
		}
	}
}

struct hNode* addToTable(char *name, char *def) {
	size_t hashIndex;
	struct hNode *entry;
	if((entry = lookUp(name)) == NULL) {
		entry = (struct hNode*)malloc(sizeof(struct hNode));
		if(entry == NULL || (entry->name = strdup(name)) == NULL)
			return NULL;

		entry->nEntry = hashTable[hashIndex = hash(name)];
		hashTable[hashIndex] = entry;
	} else 
		free((void*)entry->def);
	if((entry->def = strdup(def)) == NULL)
		return NULL;
	return entry;
}

// Get the hash value of the input name
size_t hash(char *name) {
	size_t hashValue;
	// Loop through the string
	for(hashValue = 0; *name != '\0'; name++) {
		hashValue = *name + 31 * hashValue;
	}
	// Make sure that hashValue is less than MAX_HASH_SIZE
	return hashValue % MAX_HASH_SIZE;
}

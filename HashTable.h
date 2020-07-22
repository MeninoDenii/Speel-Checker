#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

#define MAX_BUCKETS 160000

struct HashTable {
	struct Node *nodes[MAX_BUCKETS];
	unsigned int buckets;
	unsigned int words;
};

#endif

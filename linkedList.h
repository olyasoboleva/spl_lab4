#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#pragma once

typedef struct linkedList {
	int value;
	struct list* next;
} list;

list* list_create(int);
void list_add_front(int, list**);
void list_add_back(int, list**);
int list_get(size_t, list**);
void list_free(list**);
size_t list_length(list**);
list* list_node_at(size_t, list**);
long list_sum(list**);


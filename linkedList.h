#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int list_sum(list**);
void list_print(list**);
void list_read(list**);
bool save(struct list* lst, const char* filename);
bool load(struct list** lst, const char* filename);
bool serialize(struct list* lst, const char* filename);
bool deserialize(struct list** lst, const char* filename);

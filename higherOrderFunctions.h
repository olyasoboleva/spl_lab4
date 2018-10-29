#pragma once
#include "linkedList.h"

void forEach(list*, void (*f)(int));
list* map(list*, int (*f)(int));
void map_mut(list*, int (*f)(int));
int foldl(int, list*, int (*f)(int, int));
list* iterate(int, size_t, int (*f)(int));
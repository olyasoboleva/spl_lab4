#include "higherOrderFunctions.h"

void forEach(list* lst, void(*f)(int)) {
	while (lst!= NULL) {
		f(lst->value);
		lst = lst->next;
	}
}

list* map(list* lst, int(*f)(int)) {
	list* newList = NULL;
	while (lst!=NULL) {
		list_add_back(f(lst->value),&newList);
		lst = lst->next;
	}
	return newList;
}

void map_mut(list* lst, int(*f)(int)) {
	while (lst != NULL) {
		lst->value = f(lst->value);
		lst = lst->next;
	}
}

int foldl(int a, list* lst, int(*f)(int, int)) {
	while (lst != NULL) {
		a = f(lst->value, a);
		lst = lst->next;
	}
	return a;
}

list* iterate(int s, size_t n, int(*f)(int)) {
	list* lst = NULL;
	size_t i;
	for (i = 0;i < n;i++) {
		list_add_back(s, &lst);
		s = f(s);
	}
	return lst;
}
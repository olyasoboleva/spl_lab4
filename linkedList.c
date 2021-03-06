#include "linkedList.h"

list* list_create(int value) {
	list* element = (list*)malloc(sizeof(list));
	element->value = value;
	element->next = NULL;
	return element;
}

void list_add_front(int value, list** firstEl) {
	list* secondEl = *firstEl;
	*firstEl = list_create(value);
	(*firstEl)->next = secondEl;
}

void list_add_back(int value, list** firstEl) {
	if (*firstEl == NULL) {
		*firstEl = list_create(value);
		return;
	}
	else {
		list* lastEl = list_create(value);
		list* currentEl = *firstEl;
		while (currentEl->next != NULL) {
			currentEl = currentEl->next;
		}
		currentEl->next = lastEl;
	}
}

int list_get(size_t index, list** firstEl) {
	list* currentEl = list_node_at(index, firstEl);
	if (currentEl == NULL) return 0;
	return currentEl->value;
}

void list_free(list** firstEl) {
	while (*firstEl != NULL) {
		list* last = (*firstEl)->next;
		free(*firstEl);
		(*firstEl) = last;
	}
}

size_t list_length(list** firstEl) {
	size_t length = 0;
	list* currentEl = *firstEl;
	while (currentEl != NULL) {
		currentEl = currentEl->next;
		length++;
	}
	return length;
}

list* list_node_at(size_t index, list** firstEl) {
	list* currentEl = *firstEl;
	size_t counter = 0;
	if (index > list_length(firstEl)) return NULL;
	while (counter != index) {
		currentEl = currentEl->next;
		counter++;
	}
	return currentEl;
}

int list_sum(list** firstEl) {
	long sum = 0;
	list* currentEl = *firstEl;
	while (currentEl != NULL) {
		sum += currentEl->value;
		currentEl = currentEl->next;
	}
	return sum;
}

void list_read(list** firstEl) {
	int ch,value=0;
	bool space = false, minus=false;
	while ((ch = getchar()) != EOF){
		if (!isspace(ch) && ch!='\n') {
			if (ch == '-') {
				minus = true;
			}
			else {
				value = value * 10 + ch - '0';
				space = false;
			}

		}
		else {
			if (!space) {
				if (minus) value = -value;
				list_add_front(value, firstEl);
			}
			space = true;
			minus = false;
			value = 0;
			if (ch == '\n') { return 0; }
		}
	}
	return 0;
}

void list_print(list** firstEl) {
	list* currentEl = *firstEl;
	while (currentEl != NULL) {
		printf("%d ",currentEl->value);
		currentEl = currentEl->next;
	}
	printf("\n");
	//*firstEl = NULL;
}

bool save(list* lst, const char* filename) {
	FILE *f = fopen(filename,"w");
	if (f == NULL) return false;
	while (lst != NULL) {
		fprintf(f, "%d\n", lst->value);
		lst = lst->next;
	}
	fclose(f);
	return true;
}

bool load(list** lst, const char* filename) {
	int value=0;
	FILE *f = fopen(filename, "r");
	if (f == NULL) return false;
	while (fscanf(f, "%d", &value) != EOF) {
		list_add_back(value,lst);
	}
	fclose(f);
	return true;
}

bool serialize(list* lst, const char* filename) {
	FILE *f = fopen(filename, "w");
	if (f==NULL) return false;
	size_t i, size = list_length(&lst);
	int *buffer = (int*)malloc(size*sizeof(int));
	for (i = 0;i < size;i++) {
		buffer[i] = lst->value;
		lst = lst->next;
	}
	fwrite(buffer, size*sizeof(int), 1, f);
	fclose(f);
	return true;
}

bool deserialize(list** lst, const char* filename) {
	int* buf;
	size_t size, i;
	FILE *f = fopen(filename, "r");
	if (f == NULL) return false;
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, 0, SEEK_SET);
	buf = (int*)malloc(size);
	fread(buf, size, 1, f);
	for (i = 0;i < size/sizeof(int);i++) {
		list_add_back(buf[i],lst);
	}
	fclose(f);
	return true;
}
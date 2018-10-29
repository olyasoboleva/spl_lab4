#include "linkedList.h"

void print_with_space(int value) {
	printf("%d ",value);
}

void print_on_new_line(int value) {
	printf("%d\n", value);
}

int square(int value) {
	return value * value;
}

int cube(int value) {
	return value * value*value;
}

int module(int value) {
	return abs(value);
}

int pow_two(int value) {
	return value * 2;
}

int minimal_element(int a, int value) {
	return a > value ? value : a;
}

int maximal_element(int a, int value) {
	return a > value ? a : value;
}

int sum_elements(int a, int value) {
	return a += value;
}
int main() {
	int index = 0;
	list* first = NULL;
	list* element = NULL;
	list* temp = NULL;
	list_read(&first);
	printf("Sum of elements: %d\n", list_sum(&first));
	printf("Input element's index: \n");
	scanf("%d", &index);
	element = list_node_at(index, &first);
	if (element == NULL) {
		printf("Index out of list size!");
	}
	else {
		printf("Value of element %d: %d\n", index, element->value);
	}
	printf("Output with space\n");
	forEach(first, &print_with_space);
	printf("\nOutput on new line\n");
	forEach(first, &print_on_new_line);
	printf("\nSquares of elements\n");
	temp = map(first, &square);
	forEach(temp, &print_with_space);
	list_free(&temp);
	printf("\nCubes of elements\n");
	temp = map(first, &cube);
	forEach(temp, &print_with_space);
	list_free(&temp);
	printf("\nMaximal element: %d\n", foldl(first->value, first, &maximal_element));
	printf("Minimal element: %d\n", foldl(first->value, first, &minimal_element));
	printf("Sum of elements: %d\n", foldl(0, first, &sum_elements));
	map_mut(first, &module);
	printf("Modules of elements: ");
	list_print(&first);
	printf("\nPowers of two: ");
	temp = iterate(1, 10, &pow_two);
	forEach(temp, &print_with_space);
	list_free(&temp);
	serialize(first, "serialezedList");
	list_free(&first);
	deserialize(&first, "serialezedList");
	printf("\nAfter serialization: ");
	forEach(first, &print_with_space);
	save(first, "testSavingList");
	list_free(&first);
	load(&first,"testSavingList");
	printf("\nAfter saving: ");
	forEach(first, &print_with_space);
	return 0;
}
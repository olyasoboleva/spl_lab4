#include "linkedList.h"

int main() {
	int index = 0;
	list* first = NULL;
	list* element = NULL;
	list_read(&first);
	printf("Сумма элементов: %l\n", list_sum(&first));
	printf("Введите индекс элемента: \n");
	scanf("%d", &index);
	element = list_node_at(index, &first);
	if (element == NULL) {
		printf("Индекс за пределами размеров списка!");
	}
	else {
		printf("Значение по индексу %d: %d\n", index, element->value);
	}
	list_free(&first);
	return 0;
}
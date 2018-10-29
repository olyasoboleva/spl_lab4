#include "linkedList.h"

int main() {
	int index = 0;
	list* first = NULL;
	list* element = NULL;
	list_read(&first);
	printf("����� ���������: %l\n", list_sum(&first));
	printf("������� ������ ��������: \n");
	scanf("%d", &index);
	element = list_node_at(index, &first);
	if (element == NULL) {
		printf("������ �� ��������� �������� ������!");
	}
	else {
		printf("�������� �� ������� %d: %d\n", index, element->value);
	}
	list_free(&first);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode { // ���� ����Ʈ ����
	int* top;
	element data;
	struct StackNode* link;
}StackNode;


void createStack(StackNode** top) { // �ʱ�ȭ
	*top = NULL;
}

int is_empty(StackNode* S) { // is_Empty, top ���� NULL�� ��
	return (S->top == NULL);
}

void push(StackNode** top, element value) { // PUSH
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = value;
	if (!temp){ // ������ ���������� ��������� �ʾ��� ��
		printf("������ ���������� ��������� �ʾҽ��ϴ�.\n");
		exit(1);
	}
	else { // ���������� ����� �� ��
		temp->link = *top;
		*top = temp;
	}
}

element pop(StackNode** top) { // POP
	element item; // return ���ִ� ��
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode)); //���� �� ����
	if (is_empty(*top)) {
		exit(1);
	}
	else {
		temp = *top; // top�� �ӽ� ���� temp�� ����
		item = (*top)->data; // top ���� ��ȯ�ϱ� ���� top�� ���� item�� ����
		*top = (*top)->link; // top ����
		free(temp);  // temp ���� ����
		return item; // item(top ��) ��ȯ
	}
}

element peek(StackNode** top) { // PEEK
	if (*top == NULL) { // Top == NULL�� �� ���� ��� �� ���α׷� ����
		printf("\n\n Stack is empty !\n");
		exit(1);
	}
	else { // NULL�� �ƴ� �� top�� data�� ��ȯ
		return ((*top)->data); // top�� ������ ���� ��ȯ
	}
}

void printStack(StackNode** top) { // ������ top�������� bottom���� ��� element ���
	printf("printStack : ");
	for (StackNode* p = *top; p != NULL; p = p->link) // top���� �����ؼ� NULL�� �� ������ �ݺ��Ͽ� link�� Ÿ�� �̵�
		printf("%d-> ", p->data);
	printf("NULL \n\n");
}

void deleteStack(StackNode** top) { //������ top�������� bottom���� ��� element ��� ��, ��� ����
	StackNode* p = *top; // top���� �����ϴ� ���� p
	while (p != NULL) { // p �� NULL���� �� ������ �ݺ�
		StackNode* temp = p; // temp �� p���� ����
		p = p->link; // p �� ��ũ�� Ÿ�� ���� ���� �Ѿ
		printf("DeleteStack : %d\n", temp -> data); // temp�� z���
		free(temp); // temp ����
	}

	printf("\n==========���� �Ϸ�==========\n"); // ��� ��� ���� �Ϸ� �� ���
}

void start() {
	element item;
	StackNode* top;
	createStack(&top); // �ʱ�ȭ
	printf("** ���� ���� ���� **\n\n");

	for (int i = 0; i < 5; i++) { // PUSH 5�� ����
		push(&top, i);
	}

	printStack(&top); // Top ���� bottom���� ��� ���� ���

	item = peek(&top); // top �� �� ��� 
	printf("PEEK : %d\n\n", item);

	for (int j = 0; j < 5; j++) { // POP 5�� ����
		item = pop(&top);
		printf("POP => %d\n", item);
	}

	deleteStack(&top); // �����ִ� top ���� bottom ���� ��� �� ��� �� ��� ����

}

int main(void) {
	start();
	return 0;
}